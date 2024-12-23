#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include<Windows.h>

using namespace std;

void printdividing_line();

class Object
{
private:
    string name;
    string tag;
public:
    Object();
    Object(string,string);

    /* pure virtual function */
    virtual bool triggerEvent(Object*) = 0;

    /* Set & Get function*/
    void setName(string);
    void setTag(string);
    string getName();
    string getTag();
};

#endif // OBJECT_H_INCLUDED
