#pragma once
#include <iostream>
#include <vector>
#include <string>
class Character;

class AbstractItemUseBehavior{
    public:
        virtual void Use(Character&)const = 0;
};

class Item{
    private:
        std::string Name;
        double Price;
        const AbstractItemUseBehavior &UseBehavior;
        bool CombatOnly;
        bool Reusable;

    public:
        Item(std::string name, int price, const AbstractItemUseBehavior &use, bool combatOnly = false, bool reusable = false): Name(name), Price(price), UseBehavior(use), CombatOnly(combatOnly), Reusable(reusable){};
        Item(const Item& item): Name(item.Name), Price(item.Price), UseBehavior(item.UseBehavior), CombatOnly(item.CombatOnly), Reusable(item.Reusable){};
        ~Item() { std::cout << "Destroyed " << Name << ".\n"; }
        void Use(Character&);
        void HalvePrice();
        void NullifyPrice();

        std::string GetName()const;
        int GetPrice()const;
        bool IsOnlyForCombat()const;

        friend std::ostream& operator<<(std::ostream&, const Item&);
};

class SmallHeal: public AbstractItemUseBehavior{
    public:
        void Use(Character&)const;
};
class MediumHeal: public AbstractItemUseBehavior{
    public:
        void Use(Character&)const;
};
class BigHeal: public AbstractItemUseBehavior{
    public:
        void Use(Character&)const;
};
class SmallHeadArmor: public AbstractItemUseBehavior{
    public:
        void Use(Character&)const;
};