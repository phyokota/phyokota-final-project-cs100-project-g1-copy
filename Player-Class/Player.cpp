#include "../Player-Class/Player.h"
#include <iostream>

Player::Player(PlayerType type, string &name) { 
    this->type = type;
    this->name = name;
    this->health = 100.0;
    this->level = 0; 
}

void Player::set_name(string &name) {
    this->name = name;
}

void Player::damage_player(double damage) {
    this->health = this->health - damage;
    if(damage > 0) { 
        cout << "\nEnemy dealt you " << damage << " damage!" << endl;
    }
}

void Player::level_up() {
    this->level++;
}

double Player::get_health() const {
    return health;
}

int Player::get_level() const {
    return level;
}

string Player::get_name() const {
    return name;
}

PlayerType Player::get_type() const {
    return type;
}

void Player::add_cash(double gold) {
    cash = cash + gold;
}
double Player::get_cash() const {
    return cash;
}

bool Player::is_alive() const {
    if(health > 0) {
        return true;
    } else {
        return false;
    }
}

void Player::printStats() const {
    if(this->get_type() == MELEE) {
        std::cout << R"(
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
        )" << std::endl;
        std::cout << "============================================================" << std::endl;
        std::cout << "[NAME] " << this->get_name() << std::endl;
        std::cout << "[TYPE] " << "MELEE" << std::endl;    
        std::cout << "[HEALTH] " << this->get_health() << std::endl;
        std::cout << "[LEVEL] " << this->get_level() << std::endl;
        std::cout << "[CASH] " << this->get_cash() << std::endl;
        std::cout << "============================================================" << std::endl;
    } else if(this->get_type() == RANGE) {
        std::cout << R"(
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
                                                                    ~@@_
                                                                      ~@
        )" << std::endl;
        std::cout << "============================================================" << std::endl;
        std::cout << "[NAME] " << this->get_name() << std::endl;
        std::cout << "[TYPE] " << "RANGE" << std::endl;    
        std::cout << "[HEALTH] " << this->get_health() << std::endl;
        std::cout << "[LEVEL] " << this->get_level() << std::endl;
        std::cout << "[CASH] " << this->get_cash() << std::endl;
        std::cout << "============================================================" << std::endl;
    } else {
        std::cout << R"(
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
        )" << std::endl;
        std::cout << "============================================================" << std::endl;
        std::cout << "[NAME] " << this->get_name() << std::endl;
        std::cout << "[TYPE] " << "MAGE" << std::endl;    
        std::cout << "[HEALTH] " << this->get_health() << std::endl;
        std::cout << "[LEVEL] " << this->get_level() << std::endl;
        std::cout << "[CASH] " << this->get_cash() << std::endl;
        std::cout << "============================================================" << std::endl;
    }
}