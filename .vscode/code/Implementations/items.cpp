#include <iostream>
#include <vector>
#include <string>
#include "../Headers/character.h"
#include "../Headers/items.h"

void Item::Use(Character &character){
    UseBehavior.Use(character);
    if(!Reusable){
        character.RemoveItem(this); 
        delete(this);
    }
}
void Item::HalvePrice() { Price /= 2; }
void Item::NullifyPrice() { Price = 0; }

std::string Item::GetName() const { return Name; }
int Item::GetPrice() const { return Price; }
bool Item::IsOnlyForCombat() const { return CombatOnly; }

std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << item.Name;
    if(item.GetPrice() > 0) os << ", " << item.Price << "$";  
    return os;
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
