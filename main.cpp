#include<iostream>
#include<string>
#include<vector>

    class Character;

    class AbstractItemUseBehavior{
        public:
            virtual void Use(Character&)const = 0;
    };

    /// Item
    class Item{
        protected:
            std::string Name;
            double Price;
            const AbstractItemUseBehavior &UseBehavior;

        public:
            Item(std::string name, int price, const AbstractItemUseBehavior &use): Name(name), Price(price), UseBehavior(use){};
            void Use(Character &character){UseBehavior.Use(character);}
            void HalvePrice() {Price /= 2;}

            std::string GetName()const { return Name; }
            int GetPrice()const { return Price; }

            friend std::ostream& operator<<(std::ostream&, const Item&);
    };

    std::ostream& operator<<(std::ostream& os, const Item& item){
        return os << item.Name << ", " << item.Price << "$\n";
    }

    /// Character
    class Character{
        private:
            std::vector<Item*> Inventory;
            double MaxHealth = 30;
            double Health = 30;
            double HeadArmor = 0;
            double BodyArmor = 0;
            int Money = 10;

        public:
            void Heal(double amount){Health = std::min(Health + amount, MaxHealth);}
            void AddItem(Item* item, bool free = false){
                if(!free){
                    Money -= item->GetPrice();
                    item->HalvePrice();
                }
                Inventory.push_back(item);
            }
            void CheckInventory()const{
                std::cout << "Inventory: \n";
                for(auto item : Inventory) std::cout << "- " << *item;
                std::cout << "Money: " << Money << "$\n";
                std::cout << "\n\n";
            }

            int GetHealth()const { return Health; }
            int GetMoney()const { return Money; }
    };

    /// Item Behaviors
    class SmallHeal: public AbstractItemUseBehavior{
        public:
            void Use(Character &character)const { character.Heal(10); }
    };
    class MediumHeal: public AbstractItemUseBehavior{
        public:
            void Use(Character &character)const { character.Heal(30); }
    };
    class BigHeal: public AbstractItemUseBehavior{
        public:
            void Use(Character &character)const { character.Heal(60); }
    };

    /// SHOP
    class Shop{
        private:
            std::vector<Item*> Items;

        public:
            void AddItem(Item* item){Items.push_back(item);}
            void BuyItem(const std::string &name, Character &character){
                for(int i = 0; i < Items.size(); ++i)
                    if(Items[i]->GetName() == name){

                        if(Items[i]->GetPrice() > character.GetMoney()){
                            std::cout << "Can't afford '" << name << "'\n\n";
                            return;
                        }

                        std::cout << "Bought '" << name << "'!\n\n";
                        character.AddItem(Items[i]);
                        Item* item = Items[i];
                        Items.erase(Items.begin()+i);
                        return;
                    }
                std::cout << "Couldn't find '" << name << "'\n\n";
                return;
            }
            void CheckItems()const{
                std::cout << "Shop items: \n";
                for(auto item : Items) std::cout << "- " << *item;
                std::cout << "\n\n";
            }
    };

    void InitiateShop(Shop& shop){
        shop.AddItem(new Item("small potion", 5, SmallHeal{}));
        shop.AddItem(new Item("small potion", 5, SmallHeal{}));
        shop.AddItem(new Item("medium potion", 10, MediumHeal{}));
        shop.AddItem(new Item("big potion", 15, BigHeal{}));
    }

    int main(){
        Character Damon;
        Shop shop;

        InitiateShop(shop);
        shop.CheckItems();
        shop.BuyItem("small potion", Damon);
        shop.BuyItem("small potion", Damon);
        Damon.CheckInventory();
        shop.CheckItems();
    }
