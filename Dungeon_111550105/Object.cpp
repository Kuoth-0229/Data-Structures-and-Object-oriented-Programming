#include "Object.h"

void printdividing_line(){
    cout << "\n\n \t ~ ~  This is dividing line  ~ ~ " << endl;

    for (int i = 0; i < 50; i++) {
        Sleep(10);
        cout << "=";
    }
    cout << "\n\n" << endl;
}

Object::Object(){}

Object::Object (string name,string tag): 
    name(name),tag(tag){
    }

void Object::setName(string name){
    this->name = name;
}

void Object::setTag(string tag){
    this->tag = tag;
}

string Object::getName(){
    return name;
}

string Object::getTag(){
    return tag;
}


