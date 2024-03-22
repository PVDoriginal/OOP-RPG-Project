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
        protected:
            std::string Name;
            double Price;
            const AbstractItemUseBehavior &UseBehavior;

        public:
            Item(std::string name, int price, const AbstractItemUseBehavior &use): Name(name), Price(price), UseBehavior(use){};
            void Use(Character&);
            void HalvePrice();

            std::string GetName()const;
            int GetPrice()const;

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