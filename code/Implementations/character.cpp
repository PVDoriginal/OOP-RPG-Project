#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include "../Headers/character.h"
#include "../Headers/items.h"
#include "../Headers/utility.h"

std::ostream& operator<<(std::ostream& os, const Character& character){
    os << character.Health << "/" << character.MaxHealth << "HP | ";
    os << character.HeadArmor << " Head ARM | ";
    os << character.BodyArmor << " Body ARM | ";
    os << character.Damage << " DMG\n";
    return os;
}

int Character::nr_of_players = 0;

void Character::Heal(int amount) { Health = std::min(Health + amount, MaxHealth); }
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

void Character::AddMoney(double amount) { Money += amount; }

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

void Character::Hit(double damage){
    damage = damage * 1/2 * (1 - HeadArmor/100) + damage * 1/2 * (1 - HeadArmor/100);
    Health -= int(damage);
}

void Character::SetDamage(double amount) { Damage = amount; }

void Character::CheckMoney()const{
    std::cout << "You have " << Money << "$\n";
}

double Character::GetRandomDamage() const { return Singleton<double>::getInstance()->GetRandomDamage(Damage, DamageMulti); }

void Character::Type(){std::cout << "This is a character!\n";}

int Character::GetHealth()const { return Health; }
int Character::GetMoney()const { return Money; }
double Character::GetDamage()const { return Damage; }
