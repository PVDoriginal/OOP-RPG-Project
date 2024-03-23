#include <iostream>
#include <vector>
#include <string>
#include "../Headers/character.h"
#include "../Headers/items.h"

void Character::Heal(double amount){Health = std::min(Health + amount, MaxHealth);}
void Character::AddItem(Item* item, bool free){
        if(!free){
            Money -= item->GetPrice();
            item->HalvePrice();
    }
    Inventory.push_back(item);
}
void Character::CheckInventory()const{
    std::cout << "Inventory: \n";
    for(auto item : Inventory) std::cout << "- " << *item;
    std::cout << "Money: " << Money << "$\n";
    std::cout << "\n\n";
}
void Character::CheckMoney()const{
    std::cout << "You have " << Money << "$\n";
}
int Character::GetHealth()const { return Health; }
int Character::GetMoney()const { return Money; }
