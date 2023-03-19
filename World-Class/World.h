#ifndef WORLD_H
#define WORLD_H

#include <string>
using namespace std;

enum Location {NONE, BATTLEFIELD, FOREST, WONDERLAND};

class World {
    protected:
        Location location;
        string name;
        int gamePosition;
        int numOfKills;
        
    public:
        World(Location location_given, string &name);

        void gamePositionSetter(int);
        void setLocation(Location);
        void killIncrementor();

        string getName(){ return name;}
        Location getLocation();
        int getNumOfKills();
        int getGamePos(){ return gamePosition;}

        virtual void outputStory() = 0;
        void gamePositionIndicator();
        void locationMap();
};

class BattleField: public World{
    public:
    BattleField(Location location, string &name);
    void outputStory();
};


class Forest: public World{
    public:
    Forest(Location location, string &name);
    void outputStory();
};

class Wonderland: public World{
    public:
    Wonderland(Location location, string &name);
    void outputStory();
};

//next event


//World will be a collection of locations
//there will be three locations: //in general three parts to the game: prep, mini battles, final boss


#endif