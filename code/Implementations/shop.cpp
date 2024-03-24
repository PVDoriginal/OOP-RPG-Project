#include <iostream>
#include <vector>
#include <string>
#include "../Headers/items.h"
#include "../Headers/character.h"
#include "../Headers/shop.h"

void Shop::AddItem(Item* item) { Items.push_back(item); }
Item* Shop::GetItem(int index, const Character& character){
    if(index-1 >= Items.size()){
        std::cout << "There are only " << Items.size() << " items!\n";
        return nullptr;
    }
    if(Items[index-1]->GetPrice() > character.GetMoney()){
        std::cout << "You can't afford this item!";
        return nullptr;
    }
    std::cout << "Bought '" << Items[index-1]->GetName() << "'!\n";
    Item* item = Items[index-1];
    Items.erase(Items.begin()+index-1);
    return item;
}
void Shop::CheckItems() const {
    std::cout << "Shop items: \n";
    for(int i = 0; i < Items.size(); ++i)
        std::cout << i+1 << ". " << *Items[i] << "\n";
    std::cout << "\n";
}
