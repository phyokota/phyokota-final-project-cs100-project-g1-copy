#ifndef INVENTORY__HPP__
#define INVENTORY__HPP__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Inventory
{
    public:
        vector <string> Items;
        string currItem;
        int size;
        Inventory();
        void OpenInventory();
        int getSize();
};

#endif