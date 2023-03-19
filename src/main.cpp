#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "../Player-Class/Player.h"
#include "../World-Class/World.h"
#include "../Enemy-Class/Enemy.h"
#include "../Inventory-Class/Inventory.hpp"
#include "../Inventory-Class/InventoryActions.hpp"

using namespace std;

void mainMenu();
char menuOptions(Player *character, World *world, InventoryActions & actions);
char titleScreen();
void enemyEncounter(Player *character, World *world);
char enemyPrompt();

int main(){
    srand(time(nullptr));
    char input; 
    int int_input;  
    string name;
    Player *playerObj; 
    World *world;
    InventoryActions actions;

    input = titleScreen();
    if(input == 'N') { //quit game before it even starts if they want to for some reason
        exit(0);
    }


    cin.ignore();
    cout << "\nEnter name to start: ";
    getline(cin, name);
    cout << "Enter which type of character you'd like with its corresponding number: " << endl;
    cout << "1. Melee" << endl;
    cout << "2. Range" << endl;
    cout << "3. Mage" << endl;
    cin >> int_input;
  
    while(int_input != 1 && int_input != 2 && int_input != 3){
        cin.clear();
        cin.ignore();
        cout << "INVALID INPUT: Please choose option 1, 2, or 3: ";
        cin >> int_input;
        cout << endl;
    }

    if(int_input == 1) {
        playerObj = new Melee(MELEE, name);
        cout << "Melee Player Created!" << endl;
    } else if(int_input == 2) {
        playerObj = new Range(RANGE, name);
        cout << "Range Played Created!" << endl;
    } else {
        playerObj = new Mage(MAGE, name);
        cout << "Mage player created" << endl;
    }

    //FIXME: ADD IN GAME NAME
    cout << endl;
    cout << "Hello, " << name << "! AND WELCOME TO JOURNEY" << endl;
    cout << "CHOOSE A LOCATION:" << endl;
    cout << "\n============================================================"  << endl;
    cout << "                       Select Option" << endl;
    cout << "============================================================" << endl;
    cout << "a) BATTLEFIELD" << endl;
    cout << "b) FOREST" << endl;
    cout << "c) WONDERLAND" << endl;
    cout << "============================================================" << endl;
    cin.ignore();
    cin >> input;
    while(input != 'a' && input != 'b' && input != 'c'){
        cin.clear();
        cin.ignore();
        cout << "INVALID INPUT: Please choose option a, b, or c (only lowercase): ";
        cin >> input;
        cout << endl;
    }
        if(input == 'a'){
            world = new BattleField(BATTLEFIELD, name);
            cout << "new world created: Battlefield" << endl;
        } else if(input == 'b'){
            world = new Forest(FOREST, name);
            cout << "new world created: forest" << endl;
        } else if(input == 'c'){
            world = new Wonderland(WONDERLAND, name);
            cout << "new world created: wonderland" << endl;
        }

    cout << "Navigate the game using keyboard input corresponding to prompts...." << endl;
    
    while(playerObj->is_alive() && input != 'q') {

        if(world->getNumOfKills() == 3) break; 

        char input = menuOptions(playerObj, world, actions);        
    } 

    delete playerObj;
    delete world;

    //playerObj = nullptr;
    //world = nullptr;
    return 0;
}

void mainMenu(){
    cout << "\n============================================================"  << endl;
    cout << "                       Select Option" << endl;
    cout << "============================================================" << endl;
    cout << "a) Continue" << endl;
    cout << "b) View Stats" << endl;
    cout << "c) View Inventory" << endl;
    cout << "d) View Current Location" << endl;
    cout << "e) View Map" << endl;
    cout << "q) Quit Game" << endl;
    cout << "============================================================" << endl;
}

char menuOptions(Player *character, World *world, InventoryActions & actions){
    mainMenu();
    char input; 
    cin >> input;

    while(input != 'a' && input != 'b' && input != 'c' && input != 'd' && input != 'e' && input != 'Y' && input != 'y' && input != 'N' && input != 'n' && input != 'q'){
        cout << "INVALID INPUT: Try Again " << endl;
        cin.clear();
        cin.ignore();
        mainMenu();
        cin >> input;
    }
    if(input == 'a'){
        srand(time(0));
        int random_num = rand() % 4 + 1;

        if(random_num == 1) 
        {
            cout << "\nYou encountered an enemy!" << endl;
            enemyEncounter(character, world);
        }
        else if(random_num == 2) 
        {
            cout << "\n'Plink' Your foot hits something on the ground." << endl;
            cout << "You found 20 gold!" << endl;
            character->add_cash(20);
        }
        else if (random_num == 3)
        {
            cout << "\nAs the trees sway in the wind, an Apple falls and hits your head." << endl;
            cout << "You obtained an apple!" << endl;
            actions.AddItem("apple");
        }
        else 
        {
            cout << "\nNothing happened today....." << endl;
        }
    } else if(input == 'b'){
        character->printStats();
    } else if(input == 'c'){
        actions.OpenInventory();
        actions.SelectOptions();
        bool game = true;
        char input;
        while (game)
        {
            cin >> input;
            if (input == 'a')
            {
                actions.OpenInventory();
            }
            if (input == 'b')
            {
                actions.OpenInventory();
                actions.SwapItems();
            }
            if (input == 'c')
            {
                actions.OpenInventory();
                actions.DropItems();
            }
            if (input == 'd')
            {
                actions.OpenInventory();
                actions.UseItems();
            }
            if (input == 'e')
            {
                game = false;
                break;
            }
            actions.SelectOptions();
        }
    } else if(input == 'd'){
        world->gamePositionIndicator();
    } else if(input == 'e'){
        world->locationMap();
    } else {
        cout << "Are you sure you want to quit (y/n) [All progress will be lost!]" << endl;
        cin >> input;
        if(input == 'Y' || input == 'y') {
            exit(0);
        }
    }

    return input;
}

void playerStats(Player *character){
    //includes name, type, health, inventory level, and currency balance
    cout << character->get_name() << "'s Stats:" << endl;
    cout << "Type: " << character->get_type() << endl;
    //cout << "Inventory: " << player.getInventoryLevel() << endl;
    cout << "Cash Balance: " << character->get_cash() << endl;
}

char titleScreen() {
    char input;

    cout << R"(
        ▄█  ▄██████▄  ███    █▄     ▄████████ ███▄▄▄▄      ▄████████ ▄██   ▄   
        ███ ███    ███ ███    ███   ███    ███ ███▀▀▀██▄   ███    ███ ███   ██▄ 
        ███ ███    ███ ███    ███   ███    ███ ███   ███   ███    █▀  ███▄▄▄███ 
        ███ ███    ███ ███    ███  ▄███▄▄▄▄██▀ ███   ███  ▄███▄▄▄     ▀▀▀▀▀▀███ 
        ███ ███    ███ ███    ███ ▀▀███▀▀▀▀▀   ███   ███ ▀▀███▀▀▀     ▄██   ███ 
        ███ ███    ███ ███    ███ ▀███████████ ███   ███   ███    █▄  ███   ███ 
        ███ ███    ███ ███    ███   ███    ███ ███   ███   ███    ███ ███   ███ 
    █▄ ▄███  ▀██████▀  ████████▀    ███    ███  ▀█   █▀    ██████████  ▀█████▀  
    ▀▀▀▀▀▀                          ███    ███                                  
    )" << endl;

    cout << "                                   (Y) To Start." << endl;
    cout << "                                   (N) To Quit." << endl;
    cin >> input;
    while(input != 'Y' && input != 'N'){
        cin.clear();
        cin.ignore();
        cout << "INVALID INPUT: Please enter 'Y' to start or 'N' to quit: ";
        cin >> input;
        cout << endl;
    }
    return input;
}

void enemyEncounter(Player *character, World *world) {
    char input = enemyPrompt();
    bool runAway = false;

    regularEnemy *enemy;
    enemy = new regularEnemy(REGULAR, character->get_level());

    while(enemy->getHealth() > 0 && character->get_health() > 0) {
        
        if(input == 'a') {
            double potentialDmg = enemy->attack();
            character->damage_player(potentialDmg);

            double playerDmg = character->attack(enemy);
            cout << "\nYou Dealt " << playerDmg << " damage!" << endl;
        } else if(input == 'b') {
            if(character->runAway()) {
                cout << "\nGot away successfully!" << endl;
                runAway = true;
                //delete enemy;
                break;
            } else {
                cout << "\nUnable to run away!" << endl;
            }
        } else {
            cout << "FIXME: view inventory";
        }

        input = enemyPrompt();
    }     
    delete enemy;
    if(character->is_alive() && world->getNumOfKills() == 2) {
        cout << "YOU WON! YOU BEAT ALL THREE ENEMIES!" << endl;
        world->killIncrementor();
        cout << "Kills: " << world->getNumOfKills() << endl;
    } else if(character->is_alive() && runAway == true){
        cout << "\nYou overcame the enemy encounter!" << endl;
        world->gamePositionSetter(character->get_health());
        cout << "Kills: " << world->getNumOfKills() << endl;
        cout << "Use (b) to check stats and view remaining health..." << endl;
    }  else if(character->is_alive() && runAway == false){
        cout << "\nYou overcame the enemy encounter!" << endl;
        world->gamePositionSetter(character->get_health());
        world->killIncrementor();
        cout << "Kills: " << world->getNumOfKills() << endl;
        cout << "Use (b) to check stats and view remaining health..." << endl;
    } else {
        cout << "\nYou have died!" << endl;
    }   
    // if(character->is_alive()) {
    //     cout << "\nYou overcame the enemy encounter!" << endl;
    //     world->gamePositionSetter(character->get_health());
    //     cout << "Use (b) to check stats and view remaining health..." << endl;
    // } else {
    //     cout << "\nYou have died!" << endl;
    // }   
}

char enemyPrompt() {
    char input;

    cout << "What would you like to do?" << endl;

    cout << "\n============================================================"  << endl;
    cout << "                       BATTLE!" << endl;
    cout << "============================================================" << endl;
    cout << "a) Fight" << endl;
    cout << "b) Run Away" << endl;
    cout << "c) View Inventory" << endl;
    cout << "============================================================" << endl;

    cin >> input;
    return input;
}