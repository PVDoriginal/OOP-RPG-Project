#include <iostream>
#include <vector>
#include <string>
#include "../Headers/character.h"
#include "../Headers/items.h"

std::ostream& operator<<(std::ostream& os, const Character& character){
    os << character.Health << "/" << character.MaxHealth << "HP | ";
    os << character.HeadArmor << " Head ARM | ";
    os << character.BodyArmor << " Body ARM | ";
    os << character.Damage << " DMG\n";
    return os;
}

void Character::Heal(double amount) { Health = std::min(Health + amount, MaxHealth); }
void Character::SetHeadArmor(double amount) { HeadArmor = amount; }
void Character::SetBodyArmor(double amount) { BodyArmor = amount; }
void Character::AddItem(Item* item, bool free){
    if(!free) Money -= item->GetPrice();
    item->NullifyPrice();
    Inventory.push_back(item);
}
void Character::RemoveItem(Item *item){
    for(int i = 0; i < Inventory.size(); ++i)
        if(Inventory[i] == item){
            Inventory.erase(Inventory.begin()+i);
            return;
        }
}
void Character::CheckInventory()const{
    std::cout << "Inventory: \n";
    for(auto item : Inventory) std::cout << "- " << *item;
    std::cout << "\nMoney: " << Money << "$\n";
    std::cout << "\n";
}
void Character::CheckStats() const{
    std::cout << "Character Stats: \n";
    std::cout << *this;
}

void Character::ShowUsableItems(bool inCombat) const{
    std::cout << "Usable items: \n";
    for(int i = 0, nr = 0; i < Inventory.size(); ++i)
        if(!Inventory[i]->IsOnlyForCombat() || inCombat)
            std::cout << ++nr << ". " << *Inventory[i] << "\n";
    std::cout << "\n\n";
};
Item* Character::GetItem(int index, bool inCombat){
    for(int i = 0, nr = 0; i < Inventory.size(); ++i)
        if(!Inventory[i]->IsOnlyForCombat() || inCombat){
            nr++;
            if(nr == index) return Inventory[i];
        }
    std::cout << "Couldn't find item.\n";
    return nullptr;
}

void Character::CheckMoney()const{
    std::cout << "You have " << Money << "$\n";
}
int Character::GetHealth()const { return Health; }
int Character::GetMoney()const { return Money; }
