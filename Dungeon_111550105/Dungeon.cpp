#include "Dungeon.h"



Dungeon::Dungeon(){  
}

Dungeon::~Dungeon(){
    for (int i = 0; i < this -> rooms.size(); i++){
        rooms[i] -> clear_room_Objects();
        delete rooms[i];
    }
}

void Dungeon::createPlayer(){

    printdividing_line();
    Sleep(100);
    cout << "\tWhat is your name" << endl;
    string name;
    cin >> name;
    

    char occupation_chosed;
    string occupation;
    while(1){

        cout <<"\nOK! adventurer  " << name << " ." <<"Now! choose your occupation"<<endl;
        cout << "\ta. Hand angel fish" << endl;//手天使
        cout << "\tb. Apua King" << endl;//海王
        cout << "\tc. Omega Shoutmon" << endl; //奧米加咆嘯獸
        cin >> occupation_chosed;

        if(occupation_chosed == 'a'){
            occupation = "Hand angel";
            
            this->player =  Player(name,occupation,16,7,7,0,6);
            break;
        }
        else if (occupation_chosed == 'b'){
            occupation = "Apua King";
            this->player = Player(name,occupation,10,10,10,30,10);
            break;
        }
        else if(occupation_chosed == 'c'){
            occupation = "Omega Shoutmon";
            this->player = Player(name,occupation,10,13,7,2,6);
            break;
        }
        else{
           cout << "You don't choose the right." << endl;
           cout << "Please choose again."<<endl;
        }
    }
}

void Dungeon::createMap(){
        int Map_size = 11;

        for(int i =0;i< Map_size ;i++){
             
             Room *ptr = new Room();
             ptr->setIndex(i);
             this->rooms.push_back(ptr);
        }
        
        rooms[0]->setUpRoom(rooms[1]);

        rooms[1]->setDownRoom(rooms[0]);
        rooms[1]->setLeftRoom(rooms[2]);
        rooms[1]->setRightRoom(rooms[3]);
        rooms[1]->setUpRoom(rooms[5]);

        rooms[2]->setRightRoom(rooms[1]);

        rooms[3]->setLeftRoom(rooms[1]);
        rooms[3]->setUpRoom(rooms[4]);

  
        rooms[4]->setDownRoom(rooms[3]);
        rooms[4]->setLeftRoom(rooms[5]);

        rooms[5]->setUpRoom(rooms[6]);
        rooms[5]->setDownRoom(rooms[1]);
        rooms[5]->setLeftRoom(rooms[7]);
        rooms[5]->setRightRoom(rooms[4]);

        rooms[6]->setDownRoom(rooms[5]);

        rooms[7]->setUpRoom(rooms[8]);
        rooms[7]->setRightRoom(rooms[7]);

        rooms[8]->setUpRoom(rooms[10]);
        rooms[8]->setDownRoom(rooms[7]);
        rooms[8]->setLeftRoom(rooms[9]);

        rooms[9]->setRightRoom(rooms[8]);

        rooms[10]->setDownRoom(rooms[8]);
        rooms[10]->setIsExit(true);



        vector<Object*> content;

        vector<Item> items;

        Item sword = Item("sword",0,2,0,1);
        Item b_sword = Item("hand sword",0,1,0,2); // corressponding weapond for hand angle
        Item shield = Item("better shield",0,0,2,1);
        Item b_shield = Item("shield",0,0,4,3);
        Item poton =  Item("cure",2,0,0,2);
        Item fpoton =  Item("fcure",2,0,0,0);
        Item *health = new Item("healing potion",3,0,0,0);
        Item* poison = new Item("poison Potion", -3, -2, -2, 0);
        Item* treasure = new Item("treasure", 0, 0, 0, 0);
        Item magicStone = Item("magic stone", 0, 0, 0, 7);

        items.push_back(sword);
        items.push_back(shield);
        items.push_back(poton);
        NPC* npc1 = new NPC("poor Merchant","What can be shared is always very small.",items);
        items.clear();

        items.push_back(b_sword);
        items.push_back(b_shield);
        items.push_back(poton);
        NPC* npc2 = new NPC("Mystery Merchant","Midnight has come, and I must be light!",items);
        items.clear();

        items.push_back(fpoton);
        items.push_back(fpoton);
        items.push_back(magicStone);
        NPC* npc3 = new NPC("GOD father","Faith: not wanting to know what the truth is.",items);
        items.clear();

        content.push_back(npc1);
        rooms[3]->setObjects(content);
        content.clear();
        
        content.push_back(npc2);
        rooms[6]->setObjects(content);
        content.clear();

        content.push_back(npc3);
        rooms[9]->setObjects(content);
        content.clear();

        content.push_back(health);
        rooms[2]->setObjects(content);
        content.clear();

        content.push_back(poison);
        rooms[0]->setObjects(content);
        content.clear();

        content.push_back(treasure);
        rooms[8]->setObjects(content);
        content.clear();

        Monster *monster0 = new Monster("Death knight",5,1,1);
        Monster *monster1 = new Monster("Midgard Serpent ",10,3,3);
        Monster *monster2 = new Monster("Mad Gasser of Mattoon",25,4,4);
        Monster *monster3 = new Monster("Bahamut",10,2,7);
        Monster *monster4 = new Monster("Ars Goetia",20,5,9);

        content.push_back(monster0);
        rooms[1] -> setObjects(content);
        content.clear();

        content.push_back(monster1);
        rooms[4] -> setObjects(content);
        content.clear();

        content.push_back(new Monster("Death knight", 3, 1, 1));
        content.push_back(monster2);
        rooms[7] -> setObjects(content);
        content.clear();
        
        content.push_back(monster4);
        rooms[10] -> setObjects(content);
        content.clear();
}

void Dungeon::handleMovement(){
    printdividing_line();

    cout << "You have chosen to move." << endl;
    printdividing_line();
    bool monster = false;
    vector<int> possibleDirections;
    vector<Object*> objects = this->player.getCurrentRoom()->getObjects();

    for (int i = 0; i < objects.size(); i++) {
        if (objects[i]->getTag() == "Monster") {
            monster = true;
        }
    }

    if (monster) {

        cout << "You can only retreat!" << endl;
    }
    else {
        cout << "Where do you want to go?" << endl;
        if (player.getCurrentRoom()->getUpRoom()) {
            possibleDirections.push_back(0);
        }
        if (player.getCurrentRoom()->getDownRoom()) {
            possibleDirections.push_back(1);
        }
        if (player.getCurrentRoom()->getLeftRoom()) {
            possibleDirections.push_back(2);
        }
        if (player.getCurrentRoom()->getRightRoom()) {
            possibleDirections.push_back(3);
        }

        for (int i = 0; i < possibleDirections.size(); i++) {
            if (possibleDirections[i] == 0) {
                cout <<"\t"  << char(i + 97) << ". Up" << endl;
            }
            else if (possibleDirections[i] == 1) {
                cout << "\t"  << char(i + 97) << ". Down" << endl;
            }
            else if (possibleDirections[i] == 2) {
                cout << "\t"  << char(i + 97) << ". Left" << endl;
            }
            else if (possibleDirections[i] == 3) {
                cout << "\t" << char(i + 97) << ". Right" << endl;
            }
        }
        char choice;
        cin >> choice;


        int r = 5;
        for (int i = 0; i < possibleDirections.size(); i++) {
            if (choice - 97 == i || choice - 65 == i) {
                r = possibleDirections[i];
            }
        }
        if (r == 0) {
            player.setPreviousRoom(player.getCurrentRoom());
            player.setCurrentRoom(player.getCurrentRoom()->getUpRoom());
        }
        else if (r == 1) {
            player.setPreviousRoom(player.getCurrentRoom());
            player.setCurrentRoom(player.getCurrentRoom()->getDownRoom());
        }
        else if (r == 2) {
            player.setPreviousRoom(player.getCurrentRoom());
            player.setCurrentRoom(player.getCurrentRoom()->getLeftRoom());
        }
        else if (r == 3) {
            player.setPreviousRoom(player.getCurrentRoom());
            player.setCurrentRoom(player.getCurrentRoom()->getRightRoom());
        }

        cout << "You are now in room " << player.getCurrentRoom()->getIndex() << "." << endl;
    }
}

// 之後再想
void Dungeon::handleEvent(Object* o){

}

void Dungeon::startGame(){
    this->createMap();
    this->createPlayer();
    this->player.setCurrentRoom(rooms[0]);
    this->player.setPreviousRoom(rooms[0]);
}

void Dungeon::chooseAction(Room* currRoom){
    int counter = 2;
    printdividing_line();

    int monsterExist = 0;
    int menuSize = currRoom->getObjects().size() + 3;

    cout << "\nNext move. Your call." << endl;
    cout << "\ta. Move." << endl;
    cout << "\tb. Check Status." << endl;
    
    for (int i = 0; i < currRoom->getObjects().size(); i++) {
        cout <<"\t" << char(counter++ + 97) << '.' << ' ';
        if (currRoom->getObjects()[i]->getTag() == "NPC") {
            cout << "Talk to " << currRoom->getObjects()[i]->getName() << '.' << endl;
        }
        else if (currRoom->getObjects()[i]->getTag() == "Monster") {
            cout << "Fight " << currRoom->getObjects()[i]->getName() << '.' << endl;
            monsterExist++;
        }
        else if (currRoom->getObjects()[i]->getTag() == "Item") {
            cout << "Open the Treasure Chest." << endl;
        }
    }

    if (monsterExist) {
        cout << "\t" << char(counter++ + 97) ;
        cout << ". Retreat." << endl;
        menuSize++;
    }
    cout << "\t" << char(counter + 97) << ". Save the Game." << endl;


    char choice;
    cin >> choice;


    if (choice == 'a' || choice == 'A') {
        this->handleMovement();
    }
    else if (choice == 'b' || choice == 'B') {
        player.triggerEvent(&player);
    }
    else {
        int num = choice - 97;

        for (int i = 2; i < menuSize - (monsterExist > 0) - 1; i++) {
            if (num == i || num + 32 == i) {
                bool success = currRoom->getObjects()[i - 2]->triggerEvent(&player);
                if (success) {
                    
                    if (currRoom->getObjects()[i - 2]->getTag() == "Monster") {
                        monsterExist--;
                    }
                    
                    player.getCurrentRoom()->popObject(currRoom->getObjects()[i - 2]);
                    
                }
                else if (!success && currRoom->getObjects()[i - 2]->getTag() == "Monster" && !this->player.checkIsDead()) {
                    this->retreat();
                }
            }
        }

        if (((num == menuSize - (monsterExist > 0) - 1) || (num + 32 == menuSize - (monsterExist > 0) - 1)) && monsterExist) {
            this->retreat();
        }
        else if ((num == menuSize - (monsterExist > 0) - 1 || num + 32 == menuSize - (monsterExist > 0) - 1) && !monsterExist) {
            Record record;
            record.saveToFile(&(this->player), this->rooms);
        }
        else if ((num == menuSize - (monsterExist > 0) || num + 32 == menuSize - (monsterExist > 0)) && monsterExist) {
            Record record;
            record.saveToFile(&(this->player), this->rooms);
        }
    }
}

void Dungeon::retreat(){
    printdividing_line();
     cout << "You have chosen to retreat to room " << player.getPreviousRoom() -> getIndex() << endl;
     this -> player.setCurrentRoom(this -> player.getPreviousRoom());
}
bool Dungeon::checkGameLogic(){
    if(this->player.checkIsDead()){
        printdividing_line();
        cout << "\nEverything return the the begining" << endl;
        cout << "Keep in mind : You might as well take a bold risk to life, because you have to lose it." << endl;
        return true;
    }
    else if (this->player.getCurrentRoom()->getIsExit() && this->player.getCurrentRoom()->getObjects().size() == 0){
        printdividing_line();
        cout << "\nYou break the dungeon" << endl;
        cout << "\nGet the fruits and enjoy life in the biggest secret is that adventurous life!" << endl;
        return true;
    }
    else{
        return false;
    }
    
}

void  Dungeon::runDungeon(){

    string name;
    char respond;

    cout << "Wellcome to this game\n" << endl;
    Sleep(100);
    cout << "Would you like to load old record?"<<endl;
    Sleep(30);
    cout << "\ta. Of course. " << endl;
    Sleep(30);
    cout << "\tb. No start a new game." << endl;
    cin >> respond;

    if(respond == 'b'){
        this->startGame();
    }
    else{
        while(1){
            Sleep(30);
            cout << "\nWhat is your record name ? " << endl;
            cout <<"(last time, what is your name ? )" << endl;
            cin >> name;
            Record record;
            this->player = Player(name,"unknown",10,10,10,10,10);

            if(record.loadFromFile(&(this->player),(this->rooms))){
                Sleep(30);
                cout <<"\nWellcome back " << name << " ." << endl;
                Sleep(30);
                cout << "We wait you so long" << endl;
                break;
            }
            
            printdividing_line();
            cout << "Would you want to try again ?" <<endl;
            Sleep(30);
            cout << "\ta. Yes, please find my record  (ゝ∀･)" << endl;
            Sleep(30);
            cout << "\tb. No, I give up. New game. Please." << endl;
            cin >> respond;
            if (respond == 'b'){
                this->startGame();
                break;
            }
            Sleep(30);
            cout << "\nHope is the worst of all evils, for it prolongs the torment of man.\n" << endl;
        }

    }
    while(!this->checkGameLogic()){
        this->chooseAction(player.getCurrentRoom());

    }
}   

