#pragma once
#include <iostream>
#include <vector>
class Item;

class Character{
    private:
        std::vector<Item*> Inventory;
        int MaxHealth = 100;
        int Health = 100;
        double HeadArmor = 0;
        double BodyArmor = 0;
        double Damage = 5;
        int Money = 50;

    public:

        ~Character(){
            for(auto item : Inventory)
                delete(item);
        }

        void Heal(int);
        void SetHeadArmor(double);
        void SetBodyArmor(double);
        void SetDamage(double);
        void AddItem(Item*, bool=false);
        void RemoveItem(Item*);
        Item* GetItem(int, bool=false);
        void Hit(double);
        void AddMoney(double);
        
        void CheckInventory()const;
        void CheckStats()const;
        void ShowUsableItems(bool=false)const;
        void CheckMoney()const;
        int GetHealth()const;
        int GetMoney()const;
        double GetDamage()const;
        double GetRandomDamage()const;

        friend std::ostream& operator<<(std::ostream&, const Character&);
};