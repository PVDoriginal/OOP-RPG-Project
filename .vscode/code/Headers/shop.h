#include <iostream>
#include <vector>
#include <string>
class Item;
class Character;

    /// SHOP
    class Shop{
        private:
            std::vector<Item*> Items;

        public:
            void AddItem(Item*);
            void BuyItem(const std::string&, Character&);
            void CheckItems()const;
    };
