#include <iostream>
#include <vector>
#include <string>
#include "../Headers/character.h"
#include "../Headers/items.h"

void Item::Use(Character &character) { UseBehavior.Use(character); }
void Item::HalvePrice() { Price /= 2; }
void Item::NullifyPrice() { Price = 0; }

std::string Item::GetName() const { return Name; }
int Item::GetPrice() const { return Price; }

std::ostream& operator<<(std::ostream& os, const Item& item) {
    return os << item.Name << ", " << item.Price << "$";
}

void SmallHeal::Use(Character &character) const { 
    character.Heal(10);
    std::cout << "Healed 10HP!";
}
void MediumHeal::Use(Character &character) const { 
    character.Heal(30); 
    std::cout << "Healed 30HP!";
}
void BigHeal::Use(Character &character) const {
    character.Heal(60);
    std::cout << "Healed 60HP!";
}

