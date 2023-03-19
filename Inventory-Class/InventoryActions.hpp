#ifndef INVENTORYACTIONS__HPP__
#define INVENTORYACTIONS__HPP__

#include <iostream>
#include <vector>
#include <string>
#include "Inventory.hpp"

using namespace std;

class InventoryActions : public Inventory
{
    public:
        InventoryActions();
        void SelectOptions();
        void SwapItems();
        void DropItems();
        void UseItems();
        void AddItem(string);
};

#endif