#include <iostream>
#include <vector>
#include <string>
class Item;
class Character;

/// SHOP
class Shop{
    private:
        std::vector<Item*> Items;

    public:
        void AddItem(Item*);
        Item* GetItem(int);
        void CheckItems()const;
};
