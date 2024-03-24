#pragma once
#include <iostream>
#include <vector>
class Item;

class Character{
    private:
        std::vector<Item*> Inventory;
        double MaxHealth = 100;
        double Health = 100;
        double HeadArmor = 0;
        double BodyArmor = 0;
        double Damage = 5;
        int Money = 10;

    public:
        void Heal(double);
        void SetHeadArmor(double);
        void AddItem(Item*, bool=false);
        void RemoveItem(Item*);
        Item* GetItem(int, bool=false);
        
        void CheckInventory()const;
        void CheckStats()const;
        void ShowUsableItems(bool=false)const;
        void CheckMoney()const;
        int GetHealth()const;
        int GetMoney()const;

        friend std::ostream& operator<<(std::ostream&, const Character&);
};