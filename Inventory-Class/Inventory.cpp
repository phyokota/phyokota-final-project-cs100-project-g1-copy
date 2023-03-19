#include <iostream>
#include "../Inventory-Class/Inventory.hpp"

using namespace std;

Inventory::Inventory()
{
    Items = {"sword", "potion", "book"};
    size = 3;
    currItem = Items.at(0);
}

void Inventory::OpenInventory()
{
    cout << "\n============================================================"  << endl;
    cout << "                       Inventory" << endl;
    cout << "============================================================" << endl;
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        counter ++;
        cout << counter << ". " << Items.at(i);
        if (Items.at(i) == currItem)
        {
            cout << " <- held";
        }
        cout << endl;
    }
}

int Inventory::getSize()
{
    return size;
}