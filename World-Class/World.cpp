#include <iostream>
#include "World.h"
//#include "../Enemy-Class/Enemy.h"

using namespace std;

//for enemyEncounter, depending on location, you'll receive an enemy, and if you are at the 
//finally then you will go against the boss

World::World(Location location_given, string &name_given){
    this->location = location_given;
    this->name = name_given;
    this->gamePosition = 1;
    this->numOfKills = 0;
}

Location World::getLocation(){
    return location;
}

void World::killIncrementor(){
    ++this->numOfKills;
}

int World::getNumOfKills(){
    return this->numOfKills;
}
void World::setLocation(Location location_given){
    this->location = location_given;
}

void World::gamePositionSetter(int num){
    if(num <= 100 && num > 75){
        this->gamePosition = 1;
    } else if(num <= 75 && num > 30){
        this->gamePosition = 2;
    }else if(num <= 30){
        this->gamePosition = 3;
    }
}

void World::gamePositionIndicator(){
    if(gamePosition == 1){
        cout << "BEGINNING OF MAP" << endl;
    } else if(gamePosition == 2){
        cout << "MIDDLE OF MAP" << endl;
    } else if(gamePosition == 3){
        cout << "END OF MAP" << endl;
    }

   if(location == BATTLEFIELD){
        cout << R"(
            ]z
           `@@_
            @@@L
      .d@L,]@@@@L,
-z__   ]@@@a@@@@@@_
 `@@@@zza@@@@@@@@@@L
  `]@@@@@@@@@@@@@@@@@_
    `@@@@@@@@@@@@@@@@@L
     `-@@@@@@@@@@@@@@@@'
       `@@@@@@@@@@@@@@[
        `@@@@@@@@@@@@@[
          ]@@@@@@@@@@@[
           "~~~~-@@@@@@,
                  "~-@@@_
                     ~@@@L
                      `@@@L_
                       `~@@@L
                         `@@@z,
                          `]@@@_
                            `@@@z
                             `]@@L_
                               ~@@@z
                                `@@@z,
                                 `]@@@L
                                   `@@@z
                                     ]@@L,
                                      ~@@@z
                                       "@@@z
                                        `-@@@_
                                          ~@@@_
                                           `@@@z
                                            `-@@@_
                                              ]@@@_
                                               "@@@z
                                                `]@@L,
                                                  `@@@L
                                                   `@@@z,
                                                    `-@@@_
                                                      `@@@L
                                                       `@@@L    ]e
                                                         ~@@b_  a@b
                                                          `@@@e]@@L
                                                    -zzzz___@@@U@@@,
                                                      "~-@@@@@@@@@@@
                                                         `~-@@@@@@@@L
                                                            "~-@@@@@@,
                                                               "~@@@@L
                                                                 `~@@@e
        )" << endl;
    } else if(location == FOREST){
        cout << R"(
                            ___
                            ( ((
                            ) ))
    .::.                    / /(
    'M .-;-.-.-.-.-.-.-.-.-/| ((::::::::::::::::::::::::::::::::::::::::::::::.._
    (J ( ( ( ( ( ( ( ( ( ( ( |  ))   -====================================-      _.>
    `P `-;-`-`-`-`-`-`-`-`-\| ((::::::::::::::::::::::::::::::::::::::::::::::''
    `::'                    \ \(
                            ) ))
                            (_((
        )" << endl;
    } else if(location == WONDERLAND){
        cout << R"(
                             .--.
                            /.''.\
                            ||   \_)
                    /^\    '.'--,
                    .'_|_'.    `()
                <   |   >    ||
                    \_____/     ||
                    {/a a\}     ||
                {/-.^.-\}   (_|
                .'{  `  }'-._/|;\
                /  {     }  /; || |
                /`'-{     }-';  || |
            ; `'=|{   }|=' _/|| |
            |   \| |~| |  |/ || |
            |\   \ | | |  ;  || |
            | \   ||=| |=<\  || |
            | /\_/\| | |  \`-||_/
            '-| `;'| | |  |  ||
            jgs  |  | | | |  |  ||
                |  |+| |+|  |  ||
                |  """ """  |  ||
                |_ _ _ _ _ _|  ||
                |,;,;,;,;,;,|  ||
                `|||||||||||`  ||
                |||||||||||   ||
                `"""""""""`   ""
        )" << endl;
    }
}

BattleField::BattleField(Location location_given, string &name):World(BATTLEFIELD, name){}

Forest::Forest(Location location_given, string &name):World(FOREST, name){}

Wonderland::Wonderland(Location location_given, string &name):World(WONDERLAND, name){}

void World::locationMap(){
    if(gamePosition == 1){
    cout << R"(
    ------------------------------------------------
    [XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]
    -------------------------------------------------)" << endl;
    } else if(gamePosition == 2){

    cout << R"(
    ------------------------------------------------
    [XXXXXXXXXXXXXXXXXXXXXX]
    -------------------------------------------------)" << endl;
    
    } else if(gamePosition == 3){
        
    cout << R"(
    ------------------------------------------------
    [XXX]
    -------------------------------------------------)" << endl;

    }
    return;
}

void BattleField::outputStory(){
    if(getGamePos() == 1){
        cout << "battlefield stage 1" << endl;
    } else if(getGamePos() == 2){
        cout << "battlefield stage 2" << endl;
    } else if(getGamePos() == 3){
        cout << "battlefield stage 3" << endl;
    }
}

void Forest::outputStory(){
    if(getGamePos()== 1){
        cout << "forest stage 1" << endl;
    } else if(getGamePos() == 2){
        cout << "forest stage 2" << endl;
    } else if(getGamePos() == 3){
        cout << "forest stage 3" << endl;
    }
}

void Wonderland::outputStory(){
    if(getGamePos() == 1){
        cout << "wonderland stage 1" << endl;
    } else if(getGamePos() == 2){
        cout << "wonderland stage 2" << endl;
    } else if(getGamePos() == 3){
        cout << "wonderland stage 3" << endl;
    }
}