#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include<Windows.h>
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "Player.h"

using namespace std;

/* This is the record system. Get the information of the  */
/* player and rooms then save them to (a) file(s). Notice */
/* that using pass by reference can prevent sending the   */
/* whole vector to the function.                          */

class Record
{
private:
    void savePlayer(Player*, ofstream&);
    void saveRooms(vector<Room*>&, ofstream&);
    void loadPlayer(Player*,vector<Room*>& , ifstream&);
    void loadRooms(vector<Room*>&, ifstream&);

public:
    Record();
    ~Record();
    
    void saveToFile(Player*, vector<Room*>&);
    bool loadFromFile(Player*, vector<Room*>&);

};

#endif // RECORD_H_INCLUDED
