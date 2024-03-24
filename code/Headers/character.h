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
        int Money = 100;

    public:

        ~Character(){
            for(auto item : Inventory)
                delete(item);
        }

        void Heal(double);
        void SetHeadArmor(double);
        void SetBodyArmor(double);
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