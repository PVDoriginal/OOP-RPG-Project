#include <ostream>

class Character;

class AbstractUseBehavior{
    public:
        virtual void Use(Character&)const = 0;
};

class Character{
    private:
        int health = 0;
    public:
        void Heal(int amount){health += amount;}
        int GetHealth(){return health;}
};

class HealBehavior: public AbstractUseBehavior{
    public:
        void Use(Character &character)const{
            character.Heal(10);
        }
};

class Item{
    protected:
        std::string Name;
        int Price;
        const AbstractUseBehavior UseBehavior;
    public:
        Item(std::string n, int p, const AbstractUseBehavior &use): Name(n), Price(p), UseBehavior(use){};
        void Use(Character &character){UseBehavior.Use(character);}
};
