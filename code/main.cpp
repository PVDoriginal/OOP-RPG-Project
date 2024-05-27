#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<cassert>
#include<memory>
#include<algorithm>
#include "Headers/character.h"
#include "Headers/items.h"
#include "Headers/shop.h"
#include "Headers/enemy.h"
#include "Headers/utility.h"

class WrongInput : public std::exception {
    public:
        char* what(){return "Invalid Input";}
};

void mainLoop(Character&, Shop&);
void shopLoop(Character&, Shop&);

std::vector<Enemy*> GenerateEnemies(){
    std::vector<Enemy*> enemies;
    enemies.push_back(new Enemy("Ghoul", 7, 5, 10, {new Item("Small Potion", 0, new SmallHeal)}, {new BasicMeleeAttack}));
    enemies.push_back(new Enemy("Flesh Golem", 10, 5, 15, {new Item("Medium Potion", 0, new MediumHeal)}, {new BasicMeleeAttack, new HeavyMeleeAttack}));
    enemies.push_back(new Enemy("Flesh Golem", 10, 5, 15, {new Item("Medium Potion", 0, new MediumHeal)}, {new BasicMeleeAttack, new HeavyMeleeAttack}));
    enemies.push_back(new Enemy("Mage", 25, 7, 20, {new Item("Medium Potion", 0, new MediumHeal), new Item("Big Potion", 0, new BigHeal)}, {new BasicMeleeAttack, new BasicRangedAttack, new HeavyRangedAttack}));
    enemies.push_back(new Enemy("Tree", 80, 0, 5, {new Item("Wood", 0, new WoodSell)}, {new TreeAttack}));
    enemies.push_back(new Enemy("Tree", 80, 0, 5, {new Item("Wood", 0, new WoodSell)}, {new TreeAttack}));
    return enemies;
}


void InitiateShop(Shop* shop){
    shop->AddItem(new Item("Small Potion", 5, new SmallHeal));
    shop->AddItem(new Item("Small Potion", 5, new SmallHeal));
    shop->AddItem(new Item("Medium Potion", 10, new MediumHeal));
    shop->AddItem(new Item("Big Potion", 15, new BigHeal));
    shop->AddItem(new Item("Ugly Hat", 10, new SmallHeadArmor));
    shop->AddItem(new Item("Ugly Shirt", 15, new SmallBodyArmor));
    shop->AddItem(new Item("Knife", 15, new MediumDamage));
}

void buyLoop(Character &player, Shop &shop){
    std::cout << "-----------------------\n";
    std::cout << "Item index: ";
    int index;
    std::cin >> index;
    Item *item = shop.GetItem(index, player);
    if(item != nullptr) player.AddItem(item);
    system("pause");
    return mainLoop(player, shop);
}

void shopLoop(Character &player, Shop &shop){
    std::cout << "-----------------------\n";
    shop.CheckItems();
    player.CheckMoney();
    std::cout << "\n";
    std::cout << "Choose an action:\n";
    std::cout << "1. Buy Item.\n";
    std::cout << "2. Leave.\n";

    int command; 
    std::cin >> command;

    switch (command){
        case 1: return buyLoop(player, shop); 
        case 2: return mainLoop(player, shop); 
        default:
            std::cout << "Unidentified command\n\n";
            return shopLoop(player, shop);
    }
}

void useItemLoop(Character &player, Shop &shop){
    std::cout << "-----------------------\n";
    Singleton<double>::getInstance()->UseItem(player, shop);
    return mainLoop(player, shop);
}
void characterLoop(Character &player, Shop &shop){
    std::cout << "-----------------------\n";
    player.CheckInventory();
    player.CheckStats();
    std::cout << "\n";
    std::cout << "Choose an action:\n";
    std::cout << "1. Use item.\n";
    std::cout << "2. Leave.\n\n";

    int command; 
    std::cin >> command;

    switch (command){
        case 1: return useItemLoop(player, shop); 
        case 2: return mainLoop(player, shop); 
        default: throw WrongInput();
    }
}

bool fightEnemy(Character &player, Enemy &enemy){
    std::cout << "-----------------------\n";
    std::cout << "Fight with " << enemy.GetName() << " started!\n";
    while(true){
        std::cout << "-----------------------\n";
        std::cout<<"\n";
        player.CheckStats();
        std::cout << "Enemy HP: " << enemy << "\n\n";
        std::cout << "-----------------------\n";
        std::cout << "Choose an action:\n";
        std::cout << "1. Attack.\n";
        std::cout << "2. Use item.\n";

        int command; 
        std::cin >> command;
        double damage = player.GetRandomDamage();

        switch(command){
            case 1: 
                std::cout << "Player hits " << enemy.GetName() << " for " << damage << "HP!\n";
                enemy.Hit(damage);
                break;
            case 2:
                std::cout << "-----------------------\n";
                player.ShowUsableItems(true);
                std::cout << "Item index: ";
                int index;
                std::cin >> index;
                std::unique_ptr<Item> item(player.GetItem(index, true));
                if(item != nullptr) item->Use(player);
                break;
        }
        if(enemy.GetHealth() <= 0) return true;
        enemy.Attack(player);
        system("pause");
        if(player.GetHealth() <= 0) return false;
    }
}

bool Compare(const Enemy* a, const Enemy* b){
    return a->GetName() < b->GetName();
}

void exploreLoop(Character &player, Shop &shop){
    std::vector<Enemy*> enemies; 
    sort(enemies.begin(), enemies.end(), Compare);
    
    while(true){
        if(enemies.size() == 0) enemies = GenerateEnemies();
        int randIndex = rand()%enemies.size();
        Enemy* enemy = enemies[randIndex];
        enemies.erase(enemies.begin() + randIndex);

        bool won = fightEnemy(player, *enemy);
        Item* item = enemy->GetDrop();
        int money = enemy->GetMoney();
        delete(enemy);
        if(!won) return;

        std::cout << "Gained a " << item->GetName() << " and " << money << "$!\n\n";
        
        player.AddMoney(money);
        player.AddItem(item);

        std::cout << "-----------------------\n";
        std::cout << "Choose an action:\n";
        std::cout << "1. Keep exploring.\n";
        std::cout << "2. Go back.\n";
        
        int command; 
        std::cin >> command;

        switch(command){
            case 1: break;
            case 2: return mainLoop(player, shop);
            default: break;
        }
    }
}


void mainLoop(Character &player, Shop &shop){
    std::cout << "-----------------------\n";
    std::cout << "Choose an action:\n";
    std::cout << "1. Check Shop.\n";
    std::cout << "2. Check Character.\n";
    std::cout << "3. Explore.\n";
    std::cout << "4. Exit.\n\n";

    int command; 
    std::cin >> command;

    switch (command){
        case 1: return shopLoop(player, shop); 
        case 2: 
            while(true) {
                try{
                    return characterLoop(player, shop);
                    break;
                }
                catch(WrongInput e){
                    std::cout << e.what() << "\n";
                }
            }
        case 3: return exploreLoop(player, shop);
        case 4: return;
        default: throw WrongInput();
    }
}

void Test1();
void Test2();

Character* ChooseCharacter(){
    std::cout << "-----------------------\n";
    std::cout << "Choose a character type:\n";
    std::cout << "1. Basic.\n";
    std::cout << "2. Armored.\n";
    std::cout << "3. Rogue.\n";

    int command; 
    std::cin >> command;

    Character* player;
    //upcasts!
    switch (command){
        case 1:
            player = new BasicCharacter();
            return player;
        case 2:
            player = new ArmoredCharacter();
            return player;
        case 3:
            player = new RogueCharacter();
            return player;;
        default:
            std::cout << "Unidentified command\n\n";
            return ChooseCharacter();
    }
}

int main(){
    srand(time(0));
    Test1();
    Test2();
    system("CLS");

    Character* player = ChooseCharacter();

    Shop shop; 
    InitiateShop(&shop);
    std::cout << "Your adventure has begun.\n\n";
    system("pause");

    while(true){
        try{
            mainLoop(*player, shop);
            break;
        }
        catch (WrongInput e){
            std::cout << e.what() << "\n";
        }
    }
}

// Test if using a potion brings the player back to full health after taking damage
void Test1(){
    BasicCharacter player;
    player.Hit(10);
    Item potion = Item("medium potion", 0, new MediumHeal);
    potion.Use(player);
    assert(player.GetHealth() == 100);
}

// Test adding, buying, and using an item from the shop 
void Test2(){
    BasicCharacter player;
    Shop shop;
    shop.AddItem(new Item("Knife", 15, new MediumDamage)); // sets the player damage to 10
    Item* item = shop.GetItem(1, player);
    item->Use(player);
    assert(player.GetDamage() == 10);
}
