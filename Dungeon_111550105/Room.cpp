#include "Room.h"

Room::Room() {}

Room::Room(bool isExist,int index,vector<Object*> object):
    index(index),
    isExit(isExist),
    objects(object)
{}

 bool Room::popObject(Object* object){
    for(int i=0;i< objects.size();i++){
        if (this->objects[i] == object){
            objects.erase(objects.begin() + i);
            delete object;
            return true;
        }
    }
    return false;
 }
 void Room::clear_room_Objects(){
    for (int i =0;i< objects.size();i++){
        delete objects[i];
    }
    index = 0;
    this->objects.clear();
 }
 

    /* Set & Get function*/
void Room::setUpRoom(Room* up){
    this->upRoom = up;
}
void Room::setDownRoom(Room* down){
    this->downRoom = down;
}
void Room::setLeftRoom(Room* left){
    this->leftRoom = left;
}
void Room::setRightRoom(Room* right){
    this->rightRoom = right;
}
void Room::setIsExit(bool exitence){
    this->isExit = exitence;
}
void Room::setIndex(int index){
    this->index =index;
}
void Room::setObjects(vector<Object*> Object){
    this->objects = Object;
}

bool Room::getIsExit(){
    return isExit;
}
int Room::getIndex(){
    return index;
}
vector<Object*> Room::getObjects(){
    return objects;
}
Room* Room::getUpRoom(){
    return upRoom;
}
Room* Room::getDownRoom(){
    return downRoom;
}
Room* Room::getLeftRoom(){
    return leftRoom;
}
Room* Room::getRightRoom(){
    return rightRoom;
}





