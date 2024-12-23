#include "GameCharacter.h"

GameCharacter::GameCharacter() {}


// check death && take damage
bool GameCharacter::checkIsDead(){
    if(currentHealth <= 0){
        return true;
    }
    else{
        return false;
    }
}

int GameCharacter::takeDamage(int damage){

    this->currentHealth -= damage;
    return currentHealth;

}


//constructor
GameCharacter::GameCharacter(string name,string tag,int max_health,int attack,int defense):GameCharacter::Object(name,tag){
    this->maxHealth = max_health;
    this->currentHealth = max_health;
    this->attack = attack;
    this->defense = defense;
}

// Set & Get function

void GameCharacter::setMaxHealth(int max_health){
    maxHealth =max_health;
}
void GameCharacter::setCurrentHealth(int cur){
    currentHealth = cur;
}
void GameCharacter::setAttack(int attack){
    attack = attack;
}
void GameCharacter::setDefense(int defense){
    defense = defense;
}

int GameCharacter::getMaxHealth(){
    return maxHealth;
}
int GameCharacter::getCurrentHealth(){
    return currentHealth;
}
int GameCharacter::getAttack(){
    return attack;
}
int GameCharacter::getDefense(){
    return defense;
}


