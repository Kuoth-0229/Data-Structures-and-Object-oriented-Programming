#include "Monster.h"
#include <time.h>

Monster::Monster(string name,int health,int attack,int defense):
GameCharacter(name,"Monster",health,attack,defense){}


bool Monster::triggerEvent(Object *combat){
    Player *player = dynamic_cast<Player*>(combat);
    vector <Item> items = player->getInventory();

    int seed;
    char Player_action_choice = 'z';
    int Player_weapon_choice =0;
    int damage_decider;
    int damage =0;
    int oma = 0;

    srand(time(NULL));

    bool takeDamage;
    bool is_MP;
    bool is_hand;
    
    
    while(1){
        
        cout << "You have chosen to fight !" << endl;
        cout << "\nRemember : Whoever fights monsters should see to it that in the process he does not become a monster." << endl;
        Sleep(300);
        cout << "\nPlayer " << player->getName() << "here is your current status" << endl;
        Sleep(300);
        cout << "\tHP : " << player->getCurrentHealth()<< "/" << player->getMaxHealth() << endl;
        Sleep(300);
        cout << "\tAtk : " << player->getAttack() << endl;
        Sleep(300);
        cout << "\tDef : " << player->getDefense() << endl;
        Sleep(300);
        cout << "\tMP : "<< player->getMP() <<endl;
        Sleep(300);
        cout <<"\nMonster: " <<this->getName() << endl;
        Sleep(300);
        cout << "\tHp :" << this->getCurrentHealth() << "/" << this->getMaxHealth() << endl;

        printdividing_line();

        
        // MP system
        is_MP = false;
        is_hand = false;

        for (int i = 0; i < items.size(); i++) {
            if (items[i].getName() == "magic stone") {
                is_MP = true;
            }
            if (items[i].getName() == "hand sword" && player->getOccupation() == "Hand angel") {
                is_hand = true;
            }
        }
        
       


        cout << "\nGuess a number between 1 to 10 to attack" << endl;
        cin >> damage_decider;
        int random_num_for_player_to_guess = rand() % 11;
        Sleep(300);
        cout << "\nYou attact the monster at " << damage_decider << " ." << endl;
        cout << "\nThe weak point of monster " << random_num_for_player_to_guess << endl;

        Sleep(200);
        //爆擊
        if ( damage_decider == random_num_for_player_to_guess){
            damage = (player->getAttack() )*2;
            cout << "\nYou attack at the right point and punch the Monster. " << endl;
        }
        else if(abs(damage_decider - random_num_for_player_to_guess) <= 3){
            damage = (player->getAttack() );
             cout << "\nYou attack successfully." << endl;
        }
        else if(abs(damage_decider - random_num_for_player_to_guess) <= 4){
            damage = (player->getAttack())*(1/2);
             cout << "\nI could said you just attact." << endl;
        }
        else{
            damage =0;
            cout << "\nYour attact miss" <<endl;
        }
        //物理攻擊&&魔法攻擊區別 MP-10
        //職業是海王才有魔法
        if ((is_MP == true && player->getMP() > 0 )&& player->getOccupation() == "Apua King") {
            damage*2;
            player->setMP(player->getMP() - 10);
            Sleep(200);
            cout << "\nYou successfully use MP to do extra damage"<<endl;
        }
        if(is_MP == true && damage == 0){
            Sleep(200);
            cout << "\nCool! You successfully waste your MP" <<endl;
            cout << "\nPrefer to pursue the emptiness, also cannot have no pursuit." << endl;
        }
        




        if (damage > this->getDefense()) {
            damage -= this->getDefense();
        }
        else if (damage < 0) {
            damage = 2;
        }

        //hand 武器的特殊技能 攻擊時加血量(吸血)
        if (is_hand && player->getCurrentHealth() != player->getMaxHealth()) {
            Sleep(300);
            cout << "\nDid not see \" hand \"  coming !!!" << endl;
            cout << "\n \" Hand Angel \" can use \" hand sword \" to get some vitality from the monster. " << endl;


            while (1) {
                int h = rand() % 5;
                if (player->getCurrentHealth() + h <= player->getMaxHealth()) {
                    player->setCurrentHealth(player->getCurrentHealth() + h);
                    Sleep(300);
                    cout << "\n Your HP arise" << h << "point." << endl;
                    break;
                }
            }
            
            
           
        }
        


        Sleep(200);
        cout << "\nYou finally case " << damage <<" damage" << endl;
        this->setCurrentHealth(getCurrentHealth() - damage);


        if (this->checkIsDead()) {
            Sleep(200);
            cout << "\nYou  beat " << this->getName() << endl;

            player->setmoney(player->getmoney() + 2);
            Sleep(300);
            cout << "\nYou obtain $ 2 from Monster" << endl;
            Sleep(300);
            cout << "\nTake no notice of it! Let them sigh! Take it! I ask you to take it only." << endl;

            return true;
            break;
        }
        printdividing_line();

        //奧米加咆嘯獸具有免疫一次敵人攻擊的技能(CD是用遇到一次怪物刷新
        char skill;
        
        if (player->getOccupation() == "Omega Shoutmon" && oma < 1) {
            cout << "Do you want to use Omega Shoutmon's skill" << endl;
            cout << "\ta. Yes" << endl;
            cout << "\tb. No" << endl;
            cin >> skill;
            if (skill == 'a') {
                cout << "\nSkill work \nYou pass one attack from enemy" << endl;
                cout << "\nThe higher we fly, the less we are in the eyes of those who can't fly.So is the damage." << endl;
                oma++;
                continue;
            }
        }

        //防守
        damage = 0;
        printdividing_line();
        cout << "Choose a num between 1 to 10 to defense" << endl;
        cin >> damage_decider;
        srand(damage_decider);

        random_num_for_player_to_guess = rand() % 11;

        cout << "\nThe monster attact you on " << random_num_for_player_to_guess << " point " << endl;
        cout << "\nYou choose to protect on the point " << damage_decider << " of your body." << endl;

        if ( damage_decider == random_num_for_player_to_guess){
            damage =0;
            cout << "\nDamage?? What is that??" <<endl;
        }
        else if(abs(damage_decider - random_num_for_player_to_guess) <= 1){
            damage = this->getAttack()*0.5;
             cout << "\nFor me, the damage seems like  manipulation" << endl;
        }
        else if(abs(damage_decider - random_num_for_player_to_guess) <= 3){
            damage = this->getAttack();
             cout << "\nYou don not defense well" << endl;
        }
        else{

            damage = this->getAttack()*2;
            cout << "\nApparently, damage is a treasure for you! Take it double!!" << endl;
        }

        damage -= player->getDefense();
        if (damage < 0) {
            damage = 3;
        }
        
        cout << "\nThe " << this->getName() << " finally cause " << damage << " damage on you" << endl;

        player->setCurrentHealth(player->getCurrentHealth() - damage);

        if(player->checkIsDead()){
            Sleep(300);
            cout << "\nYou are beated by " << this->getName() << " ." << endl;
            cout << "\nA wise man never loses anything if he has hilf." << endl;
            cout << "\nApparently, you are not as wise as you though" << endl;
            printdividing_line();
            break;
        }

        printdividing_line();

        cout << "Remember : Running away is shameful, but useful." << endl;

        cout << "Retreat ? " << endl;
        cout << "\ta. yes" << endl;
        cout << "\tb. no" << endl;
        cin >> Player_action_choice;
        if (Player_action_choice == 'a') {
            cout << "You need to pay some money to let monster forgive you!" << endl;
            cout << "\ta. yes" << endl;
            cout << "\tb. no" << endl;
            cin >> Player_action_choice;
            if (Player_action_choice == 'a'&& player->getmoney()>=2) {
                player->setmoney(player->getmoney() - 2);
                return false;
            }
            else if(Player_action_choice == 'a' && player->getmoney() < 2){
                cout << "\nNow ! You have to face two problem : your finanace and " << this->getName()<< endl;
            }
            else {
                cout << "\nTime to face the problem" << endl;
            }
        }
    }
    this->setCurrentHealth(this->getMaxHealth());
    return false;
}