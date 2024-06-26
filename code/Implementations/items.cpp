#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../Headers/character.h"
#include "../Headers/items.h"

void Item::Use(Character &character){
    UseBehavior->Use(character);
    if(!Reusable) character.RemoveItem(this); 
}
void Item::HalvePrice() { Price /= 2; }
void Item::NullifyPrice() { Price = 0; }

std::string Item::GetName() const { return Name; }
int Item::GetPrice() const { return Price; }
bool Item::IsOnlyForCombat() const { return CombatOnly; }
bool Item::IsReusable() const { return Reusable; }

std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << item.Name;
    if(item.GetPrice() > 0) os << ", " << item.Price << "$";  
    return os;
}

void Item::operator=(const Item& item){
    this->Name = item.Name;
    this->Price = item.Price;
    this->CombatOnly = item.CombatOnly;
    this->Reusable = item.Reusable;
    this->UseBehavior = item.UseBehavior;
}

void SmallHeal::Use(Character &character) const { 
    character.Heal(30);
    std::cout << "Healed 30HP!\n";
}
void MediumHeal::Use(Character &character) const { 
    character.Heal(65); 
    std::cout << "Healed 65HP!\n";
}
void BigHeal::Use(Character &character) const {
    character.Heal(100);
    std::cout << "Healed 100HP!\n";
}
void SmallHeadArmor::Use(Character &character) const {
    character.SetHeadArmor(30);
    std::cout << "New Head Armor Protection: 30!\n";
}
void SmallBodyArmor::Use(Character &character) const {
    character.SetBodyArmor(30);
    std::cout << "New Body Armor Protection: 30!\n";
}

void MediumDamage::Use(Character &character) const {
    character.SetDamage(10);
    std::cout << "New DMG value: 10!\n";
}

void WoodSell::Use(Character &character) const {
    character.AddMoney(30);
    std::cout << "You sold the wood for 30$\n";
}