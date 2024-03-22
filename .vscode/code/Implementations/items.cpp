#include <iostream>
#include <vector>
#include <string>
#include "../Headers/character.h"
#include "../Headers/items.h"

    void Item::Use(Character &character) { UseBehavior.Use(character); }
    void Item::HalvePrice() { Price /= 2; }

    std::string Item::GetName() const { return Name; }
    int Item::GetPrice() const { return Price; }
    
    std::ostream& operator<<(std::ostream& os, const Item& item) {
        return os << item.Name << ", " << item.Price << "$\n";
    }

    void SmallHeal::Use(Character &character) const { 
        character.Heal(10); 
    }
    void MediumHeal::Use(Character &character) const { 
        character.Heal(30); 
    }
    void BigHeal::Use(Character &character) const {
        character.Heal(60);
    }
    
