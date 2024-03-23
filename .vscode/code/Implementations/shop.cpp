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
void Shop::BuyItem(const int &index, Character &character){
    if(index-1 >= Items.size()){
        std::cout << "There are only " << Items.size() << " items!\n";
        return;
    }
    if(Items[index-1]->GetPrice() > character.GetMoney()){
        std::cout << "You do not have enough money!\n";
        return;
    }

    std::cout << "Bought '" << Items[index-1]->GetName() << "'!\n";
    character.AddItem(Items[index-1]);
    Item* item = Items[index-1];
    Items.erase(Items.begin()+index-1);
}
void Shop::CheckItems() const {
    std::cout << "Shop items: \n";
    for(int i = 0; i < Items.size(); ++i)
        std::cout << i+1 << ". " << *Items[i] << "\n";
    std::cout << "\n";
}
