#include "NPC.h"


NPC:: NPC(string name,string script,vector<Item> com):
GameCharacter(name,"NPC",20,1000,1000){
    this->script = script;
    this->commodity = com;
}


void NPC::listCommodity(){
    int counter;
    if(commodity.size() == 0){
        cout << this->getName() << "said : " << "I have nothing" << endl;
    }
    else {
        cout << this->getName() << "said : " << "I have these things" << endl;
        for (int i=0;i< commodity.size();i++){
            cout << "\t " << i << ". " << commodity[i].getName() << " $ " << commodity[i].getValue() << endl;
        }
    }
}

bool NPC::triggerEvent(Object* objects){
    char is_transtation;
    int transtation_item_number;
    Player* player = dynamic_cast<Player*>(objects);

   
        cout << "\nDo you want some transtation?"<<endl;
        cout << "\ta. yes"<<endl;
        cout << "\tb. ignore"<<endl;
        cin >> is_transtation;
        if(is_transtation == 'a'){
            this->listCommodity();
            if (this->commodity.size() == 0){
                return false;
            }

            cout << "\nWhich item you want the most?"<<endl;
            cin >> transtation_item_number;
            if(player->getmoney() < commodity[transtation_item_number].getValue()){
                cout << this->getName() << "said : " << endl;
                cout << "\nGet away !You dont have enough money ! "<<endl;
                cout << "\nI believe that the value of you will be re evaluated." << endl;
                return false;
            }
            else{
                player->setmoney(player->getmoney() - commodity[transtation_item_number].getValue());
                player->addItem(commodity[transtation_item_number]);
                return true;
            }
        }
        else if (is_transtation == 'b'){
            return false;
        }
        else {
            cout << "wrong answer" << endl;
            return false;
        }
}

   /* Set & Get function*/
void NPC::setScript(string new_script){
    this->script = new_script;
}
void NPC::setCommodity(vector<Item> things){
    this->commodity = things;
}
string NPC::getScript(){
    return script;
}
vector<Item> NPC::getCommodity(){
    return commodity;
}
