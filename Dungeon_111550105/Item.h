#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include<Windows.h>
#include "Object.h"
#include "Player.h"
using namespace std;

class Player;

class Item: public Object
{
private:
    int health,attack,defense;
    int value;
public:
    Item();
    Item(string, int, int, int,int);

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    bool triggerEvent(Object*);

    /* Set & Get function*/
    int getHealth();
    int getAttack();
    int getDefense();
    int getValue();

    void setHealth(int);
    void setAttack(int);
    void setDefense(int);
    void setvalue(int);
};

#endif // ITEM_H_INCLUDED
