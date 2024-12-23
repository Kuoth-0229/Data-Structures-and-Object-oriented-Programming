#include <iostream>
#include <string>
#include <vector>
#include<Windows.h>
#include "Dungeon.h"
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "Player.h"


using namespace std;

int main(){
    Dungeon dungeon = Dungeon();
    dungeon.runDungeon();

    Sleep(3000);
    cout << "There is no fact, only annotation." << endl;
    Sleep(3000);
    cout << "Now, let me announce that we come to the" << endl;
    printf("\tEND~~~~~");
    return 0;
}
