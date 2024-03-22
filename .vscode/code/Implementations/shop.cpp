#include <iostream>
#include <vector>
#include <string>
#include "../Headers/items.h"
#include "../Headers/character.h"
#include "../Headers/shop.h"

    void Shop::AddItem(Item* item){Items.push_back(item);}
    void Shop::BuyItem(const std::string &name, Character &character){
        for(int i = 0; i < Items.size(); ++i)
            if(Items[i]->GetName() == name){

                if(Items[i]->GetPrice() > character.GetMoney()){
                    std::cout << "Can't afford '" << name << "'\n\n";
                    return;
                }

                std::cout << "Bought '" << name << "'!\n\n";
                character.AddItem(Items[i]);
                Item* item = Items[i];
                Items.erase(Items.begin()+i);
                return;
            }
        std::cout << "Couldn't find '" << name << "'\n\n";
        return;
    }
    void Shop::CheckItems() const {
        std::cout << "Shop items: \n";
        for(auto item : Items) std::cout << "- " << *item;
        std::cout << "\n\n";
    }
