#pragma once
#include <iostream>
#include <vector>
class Item;

    class Character{
        private:
            std::vector<Item*> Inventory;
            double MaxHealth = 30;
            double Health = 30;
            double HeadArmor = 0;
            double BodyArmor = 0;
            int Money = 10;

        public:
            void Heal(double);
            void AddItem(Item*, bool=false);

            void CheckInventory()const;
            int GetHealth()const;
            int GetMoney()const;
    };