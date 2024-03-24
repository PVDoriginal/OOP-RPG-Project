#pragma once
#include <iostream>
#include <vector>
#include <string>
class Character;
class Item;
class Enemy;

class AbstractEnemyAttack{
    public:
        virtual void Attack(Enemy&, Character&)const = 0;
};

class Enemy{
    protected:
        std::string Name;
        int Health;
        double Damage;
        int DropMoney;
        std::vector<Item*> Drops;
        std::vector<AbstractEnemyAttack*> Attacks;

    public:
        Enemy(std::string name, int health, double damage, int dropMoney, std::vector<Item*> drops, std::vector<AbstractEnemyAttack*> attacks):
            Name(name), Health(health), Damage(damage), DropMoney(dropMoney), Drops(drops), Attacks(attacks){}
        ~Enemy(){
            for(auto drop : Drops)
                delete(drop);
            for(auto attack : Attacks)
                delete(attack);
        }
        void Hit(double);
        void Kill();
        void Attack(Character&);

        double GetHealth()const;
        std::string GetName()const;
        double GetDamage()const;
        
        Item* GetDrop();
        int GetMoney()const;

        friend std::ostream& operator<<(std::ostream&, const Enemy&);
};

class BasicMeleeAttack : public AbstractEnemyAttack{
    public:
        void Attack(Enemy&, Character&)const;
};
class BasicRangedAttack : public AbstractEnemyAttack{
    public:
        void Attack(Enemy&, Character&)const;
};
class HeavyMeleeAttack : public AbstractEnemyAttack{
    public:
        void Attack(Enemy&, Character&)const;
};
class HeavyRangedAttack : public AbstractEnemyAttack{
    public:
        void Attack(Enemy&, Character&)const;
};