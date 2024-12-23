#include "Record.h"


Record::Record(){}
Record::~Record(){}


void Record::savePlayer(Player* player, ofstream& outStream){
    
    vector<Item> playerItem = player->getInventory();

    // 基本資料
    outStream << player->getName() << "\n";
    outStream << player->getOccupation() << "\n";
    outStream << player->getCurrentHealth() << " ";
    outStream << player->getMaxHealth() <<  " ";
    outStream << player->getAttack()<< " ";
    outStream << player->getDefense()<< " ";
    outStream << player->getmoney()<< " ";
    outStream << player->getMP()<< " ";
    outStream << player->getCurrentRoom()->getIndex() << " ";
    outStream << player->getPreviousRoom()->getIndex() <<  " ";

    //物品清單
    outStream << playerItem.size();
    outStream << "\n";

    for (int i = 0; i < playerItem.size(); i++){
        outStream << playerItem[i].getName()<< "\n";
        outStream << playerItem[i].getHealth()<< " ";
        outStream << playerItem[i].getAttack()<< " ";
        outStream << playerItem[i].getDefense()<< " ";
        outStream << playerItem[i].getValue();
        outStream << "\n";
    }
    playerItem.clear();
    
}

void Record::saveRooms(vector<Room*>& rooms, ofstream& outStream){

    outStream << rooms.size() << "\n";

    for(int i =0;i<rooms.size();i++){

        outStream << rooms[i]->getIndex() << " ";
        outStream << rooms[i]->getIsExit() << " ";

        if (rooms[i]->getUpRoom()){
            outStream << rooms[i]->getUpRoom()->getIndex();
            outStream << " ";
        }
        else {
            outStream << "-1 " ;
        }
        if (rooms[i]->getDownRoom()){
            outStream << rooms[i]->getDownRoom()->getIndex();
            outStream << " ";
        }
        else {
            outStream << "-1 " ;
        }
        if (rooms[i]->getLeftRoom()){
            outStream << rooms[i]->getLeftRoom()->getIndex();
            outStream << " ";
        }
        else {
            outStream << "-1 " ;
        }
        if (rooms[i]->getRightRoom()){
            outStream << rooms[i]->getRightRoom()->getIndex();
            
        }
        else {
            outStream << "-1" ;
        }

        //房間內物品
        vector<Object*> objects = rooms[i]->getObjects();

        outStream << "\n" << rooms[i]->getObjects().size()<< "\n";

        for (int i = 0; i < objects.size(); i++) {
            if (objects[i] -> getTag() == "Monster"){
                Monster *currentObject = dynamic_cast<Monster*> (objects[i]);

                    outStream << "M\n";
                    outStream << currentObject -> getName() << "\n";
                    
                    outStream << currentObject -> getMaxHealth();
                    outStream << " ";
                    outStream << currentObject -> getAttack();
                    outStream << " ";
                    outStream << currentObject -> getDefense();
                    outStream << "\n";
        }
            else if (objects[i] -> getTag() == "NPC"){
                    NPC *currentObject = dynamic_cast<NPC*> (objects[i]);
                    vector<Item> commodity = currentObject -> getCommodity();

                    outStream << "N\n";
                    outStream << currentObject -> getName() << "\n";
                    
                    outStream << currentObject -> getScript() << "\n";
                    
                    outStream << commodity.size() << "\n";

                    for(int j =0;j<commodity.size();j++){
                        outStream  << commodity[j].getName()<< "\n";
                        outStream << commodity[j].getHealth()<< " ";
                        outStream << commodity[j].getAttack()<< " ";
                        outStream << commodity[j].getDefense()<< " ";
                        outStream << commodity[j].getValue();
                        outStream << "\n";
                    }
                    //if (commodity.size() == 0) { outStream << "\n"; }

                }
            else if (objects[i]->getTag() == "Item") {
                Item* currentObject = dynamic_cast<Item*> (objects[i]);

                outStream << "P\n";
                outStream << currentObject->getName() << "\n";
                outStream << currentObject->getHealth() << " ";
                outStream << currentObject->getAttack() << " ";
                outStream << currentObject->getDefense() << " ";
                outStream << currentObject->getValue() ;
                outStream << "\n";
            }
        }
    }
}

void Record::loadPlayer(Player* player,vector<Room*>& rooms, ifstream& inStream){

    string name, occupation;

    getline(inStream, name);

    getline(inStream, occupation);

    int currentHealth, maxHealth, attack, defense, money, mp, currentRoomIndex, previousRoomIndex, numItems;
    
    inStream >> currentHealth >> maxHealth >> attack >> defense >> money >> mp >> currentRoomIndex >> previousRoomIndex >> numItems;

    player->setName(name);
    player->setoccupation(occupation);
    player->setCurrentHealth(currentHealth);
    player->setMaxHealth(maxHealth);
    player->setAttack(attack);
    player->setDefense(defense);
    player->setmoney(money);
    player->setMP(mp);

        string line2;
   
        int itemHealth, itemAttack, itemDefense, itemValue;

    for (int i = 0; i < numItems; i++) {
        string itemName;
        getline(inStream, itemName);
        getline(inStream, itemName);
        getline(inStream, line2);
        stringstream ss(line2);
        
        
        ss >> itemHealth >> itemAttack >> itemDefense >> itemValue;

        Item item(itemName, itemHealth, itemAttack, itemDefense, itemValue);
        player->addItem(item);
        
    }
    
    this->loadRooms(rooms,inStream);

    
    Room* currentRoom = rooms[currentRoomIndex];
    Room* previousRoom = rooms[previousRoomIndex];


    player->setCurrentRoom(currentRoom);
    player->setPreviousRoom(previousRoom);



    
}


void Record::loadRooms(vector<Room*>& rooms, ifstream& inStream){
    string rawr,pp;
    stringstream ss;

    inStream.get();
    getline(inStream, rawr);
    int sizeOfMap = stoi(rawr);

    vector <Object*> tempObjects;
    for (int i = 0; i < sizeOfMap; i++){
        Room *room = new Room(false, i, tempObjects);
        rooms.push_back(room);
    }

    for(int i = 0; i < sizeOfMap; i++){
        getline(inStream, rawr);
        
        ss.clear();
        ss.str(rawr);

        string buff;
        int index;
        int numberObjects;
        bool isExit;
        vector<Object*> objects;

        int up, down, left, right;

        ss >> index >> isExit >> up >> down >> left >> right ;

        getline(inStream, buff);
        numberObjects = stoi(buff);

        if (up != -1 ) {
            rooms[i] -> setUpRoom(rooms[up]);
        }
        if (down != -1) {
            rooms[i] -> setDownRoom(rooms[down]);
        }
        if (left != -1) {
            rooms[i] -> setLeftRoom(rooms[left]);
        }
        if (right != -1) {
            rooms[i] -> setRightRoom(rooms[right]);
        }

        string name = "";
        int stats[4];
        

        for (int j = 0; j < numberObjects; j++){
            inStream >> pp;
            inStream.get();

            if (pp == "M"){
                getline(inStream, buff);
                name = buff;

                getline(inStream, buff);
                ss.clear(); ss.str(buff);
                ss >> stats[0] >> stats[1] >> stats[2];

                Monster *monster = new Monster(name, stats[0], stats[1], stats[2]);
                objects.push_back(monster);
                name = "";
            }
            else if (pp == "N"){
                string script = "";
                vector <Item> inventory;

                getline(inStream, buff);
                name = buff;
                getline(inStream, buff);
                script = buff;

                getline(inStream, buff);
                int temp = stoi(buff);

                int counter2 = 0;
                for (int i = 0; i < temp; i++){
                    string itemName;
                    int itemStats[4];
                    getline(inStream, buff);
                    itemName = buff;
                    getline(inStream, buff);
                    ss.clear(); ss.str(buff);
                    ss >> itemStats[0] >> itemStats[1] >> itemStats[2] >> itemStats[3] ;
                    
                    Item item = Item(itemName, itemStats[0], itemStats[1], itemStats[2],itemStats[3]);
                    inventory.push_back(item);
                }
                
                NPC *npc = new NPC(name, script, inventory);
                objects.push_back(npc);
                name = "";
            }

            else if (pp == "P") {
                getline(inStream, buff);
                name = buff;

                getline(inStream, buff);
                ss.clear(); ss.str(buff);
                ss >> stats[0] >> stats[1] >> stats[2] >> stats[3];
                
                //name.pop_back();
                Item *item = new Item(name, stats[0], stats[1], stats[2],stats[3]);
                objects.push_back(item);
                name = "";
            }
        }

        rooms[i] -> setIsExit(isExit);
        rooms[i] -> setObjects(objects);

    }
}

void Record::saveToFile(Player* player, vector<Room*>& rooms)
{
    string saveFile = player -> getName();
    saveFile += "Save.txt";

    ofstream outStream;
    outStream.open(saveFile, ios::out);

    if (outStream.fail()){
        printdividing_line();
        cout << "Failed to open file." << endl;

        cerr << errno << endl;
        exit(1);
    }

    this -> savePlayer(player, outStream);

    this -> saveRooms(rooms, outStream);

    printdividing_line();
    cout << "Successfully saved to "<< saveFile << '.' << endl;

    outStream.close();
}

bool Record::loadFromFile(Player* player, vector<Room*>& rooms)
{
    string rawr = "Save.txt";
    string saveFile = player -> getName() + rawr;

    ifstream inStream;
    inStream.open(saveFile);
    
    if (inStream.fail()){
        printdividing_line();
        cout << "Failed to open file." << endl;
        return false;
    }

    this -> loadPlayer(player, rooms, inStream);

    return true;
}