#pragma once
#include <iostream>
#include <vector>
class Item;

class Character{
    protected:
        std::vector<Item*> Inventory;
        int MaxHealth = 100;
        int Health = 100;
        double HeadArmor = 0;
        double BodyArmor = 0;
        double Damage = 5;
        double DamageMulti = 1;
        int Money = 50;
        static int nr_of_players;

    public:
        Character(int mx, int hp, double h, double b, double dmg, double dmgmulti, int money): 
            MaxHealth(mx), Health(hp), HeadArmor(h), BodyArmor(b), Damage(dmg), DamageMulti(dmgmulti), Money(money){nr_of_players++;}; 

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

        static void Type(); 
};

class BasicCharacter : public Character{
    public:
        BasicCharacter() : Character(100, 100, 0, 0, 5, 1, 70) {ShowNR();}
        static void ShowNR(){std::cout << "Number of created players:" << nr_of_players << "\n";}
        ~BasicCharacter(){}
};

class ArmoredCharacter : public Character{
    public:
        ArmoredCharacter() : Character(100, 100, 30, 60, 6, 1.2, 10) {ShowNR();}
        static void ShowNR(){std::cout << "Number of created players:" << nr_of_players << "\n";}
        ~ArmoredCharacter(){}
};

class RogueCharacter : public Character{
    public:
        RogueCharacter() : Character(25, 25, 40, 10, 6, 4, 25) {ShowNR();}
        static void ShowNR(){std::cout << "Number of created players:" << nr_of_players << "\n";}
        ~RogueCharacter(){}
};