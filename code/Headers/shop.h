#pragma once
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
        ~Shop(){
           for(auto item : Items)
                delete(item);
        }
        void AddItem(Item*);
        Item* GetItem(const int&, const Character&);
        void CheckItems()const;
        
        friend std::ostream& operator<<(std::ostream&, const Shop&);
};
