#include "Player.h"

Player::Player() {}

// constructor 
Player::Player(string name,string occupation,int health,int attack,int defense,int money,int MP):
    GameCharacter(name,"player",health,attack,defense){
        this->money = money;
        this->MP = MP;
        this->occupation = occupation;
    }

void Player::addItem(Item new_thisng){
    this->inventory.push_back(new_thisng);
}

void Player::increaseStates(int health,int attack,int defense){
    this->setMaxHealth(this->getMaxHealth() + health);
    this->setCurrentHealth(this->getMaxHealth());
    this->setAttack(this->getAttack() + attack);
    this->setDefense(this->getDefense() + defense);
}

bool Player::triggerEvent(Object *thing){

    printdividing_line();
    Sleep(300);
    cout << "Hello " << this->getName() << " ." << endl;
    Sleep(300);
    cout<< "Here is your current status" << endl;
    Sleep(300);
    cout << "\tHP : " << this->getCurrentHealth() << "/" <<this->getMaxHealth() << endl;
    Sleep(300);
    cout << "\tAtk : " << this->getAttack() << endl;
    Sleep(300);
    cout << "\tDef : " << this->getDefense() << endl;
    Sleep(300);
    cout << "\tMP : "<< this->getMP() <<endl;
    Sleep(300);
    cout << "\tMoney : " << this->getmoney() << endl;

    cout << "Here is your iventory : " << endl;
    Sleep(300);

    if(inventory.size() > 0){
        for(int i =0;i < inventory.size();i++){
            Sleep(300);
            cout << "\t" << inventory[i].getName() << endl;
        }
    }
    else{
        cout << "Oh ! Sorry, you are too poor.\n But you have nothing to lose." << endl;
    }

    return true;
}

    /* Set & Get function*/
void Player::setCurrentRoom(Room *now){
    this->currentRoom = now;
}   
void Player::setPreviousRoom(Room *pre){
    this->previousRoom = pre;
}
void Player::setInventory(vector<Item> things){
    this->inventory = things;
}
void Player::setmoney(int money){
    this->money =money;
}
void Player::setoccupation(string occ){
    this->occupation = occ;
}
void Player::setMP(int mp){
    this->MP = mp;
}


Room* Player::getCurrentRoom(){
    return this->currentRoom;
}
Room* Player::getPreviousRoom(){
    return this->previousRoom;
}
vector<Item> Player::getInventory(){
    return this->inventory;
}
int Player::getmoney(){
    return this->money;
}
string Player::getOccupation(){
    return occupation;
}
int Player::getMP(){
    return MP;
}




