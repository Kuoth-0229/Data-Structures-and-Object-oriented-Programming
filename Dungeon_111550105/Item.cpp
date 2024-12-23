#include "Item.h"

//constructor
// all "Item" is a "Object" named "Item"
Item::Item() : Object("", "Item") {}

Item::Item(string name,int health,int attack,int defense,int value):Object(name,"Item")
{
    void setTag(string);
    this->attack = attack;
    this->defense = defense;
    this->health = health;
    this->value = value;
};
    
//corresponding weapond ¹ê§@
bool Item::triggerEvent(Object* object) {

    Player* player = dynamic_cast<Player*>(object);
    player->addItem(*this);

    

   player->increaseStates(this->health, this->attack, this->defense);

   if (this->getName() == "poison Potion") {
      
       cout << "\nThere is a strange bottle of watter . But you still drink it as if it was a healing poton. \nHa ha ! It is a permanent debuff on your HP." << endl;

   }
   else if (this->getName() == "healing potion") {
       cout << "\nYou find a bottle of water from healthing spring. You got a permanent buff." << endl;
   }
   else if (this->getName() == "treasure") {
       cout << "\n The Treasure Chest have no money" << endl;
   }
   else {
       cout << "\nYou obtain  " << this->getName() << "  successfully" << endl;
   }
    


    return true;

}
// getters
int Item::getHealth(){
    return health;
}
int Item::getAttack(){
    return attack;
}
int Item::getDefense(){
    return defense;
}
int Item::getValue(){
    return value;
}


//seter
void Item::setAttack(int new_attack){
    this->attack = new_attack;
}
void Item::setDefense(int new_defense){
    this->defense = new_defense;
}
void Item::setHealth (int new_health){
    this->health = new_health;
}
void Item::setvalue(int value){
    this->value = value;
}
