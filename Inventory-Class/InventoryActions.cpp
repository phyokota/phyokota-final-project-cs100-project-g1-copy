#include <iostream>
#include "../Inventory-Class/InventoryActions.hpp"

using namespace std;

InventoryActions::InventoryActions()
{
    Items = {"sword", "potion", "book"};
    size = 3;
    currItem = Items.at(0);
}

void InventoryActions::SelectOptions()
{
    cout << "============================================================" << endl;
    cout << "                       Select Option" << endl;
    cout << "============================================================" << endl;
    cout << "a) List Inventory" << endl;
    cout << "b) Swap Items" << endl;
    cout << "c) Drop Items" << endl;
    cout << "d) Use Items" << endl;
    cout << "e) Exit Inventory" << endl;
    cout << "============================================================" << endl;
}

void InventoryActions::SwapItems()
{
    string swappedItem;
    cout << "\nWhat Item would you like to swap: ";
    cin >> swappedItem;
    for (int i = 0; i < size; i++)
    {
        if (Items.at(i) == swappedItem)
        {
            currItem = Items.at(i);
            return;
        }
    }
    cout << "\nItem not found." << endl;
    return;
}

void InventoryActions::AddItem(string addedItem)
{
    Items.push_back(addedItem);
    size++;
}

void InventoryActions::DropItems()
{
    string droppedItem;
    cout << "\nItem to drop: " << endl;
    cin >> droppedItem;
    for (int i = 0; i < size; i++)
    {
        if (Items.at(i) == droppedItem)
        {
            if (Items.at(i) == currItem)
            {
                cout << "\nCannot drop held item!" << endl;
                return;
            }
            else
            {
                Items.erase (Items.begin()+i);
                size --;
                return;
            }
        }
    }
    cout << "Item not found." << endl;
    return;
}

void InventoryActions::UseItems()
{
    cout << "Used " << currItem << endl;
    if (currItem == "sword")
    {
        cout << "\nSword Equipped! +5 attack" << endl;

    }
    else if (currItem == "potion")
    {
        cout << "\nTasty! Restored + 10 hp" << endl;

    }
    else if (currItem == "book")
    {
        cout << "\nYou can sell this for 20 gold" << endl;
    }
}