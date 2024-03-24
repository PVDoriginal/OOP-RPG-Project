#include<iostream>
#include<string>
#include<vector>
#include "Headers/character.h"
#include "Headers/items.h"
#include "Headers/shop.h"

void mainLoop(Character&, Shop&);
void shopLoop(Character&, Shop&);


void InitiateShop(Shop* shop){
    shop->AddItem(new Item("Small Potion", 5, SmallHeal{}));
    shop->AddItem(new Item("Small Potion", 5, SmallHeal{}));
    shop->AddItem(new Item("Medium Potion", 10, MediumHeal{}));
    shop->AddItem(new Item("Big Potion", 15, BigHeal{}));
    shop->AddItem(new Item("Small Helmet", 10, SmallHeadArmor{}));
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
    player.ShowUsableItems();
    std::cout << "Item index: ";
    int index;
    std::cin >> index;
    Item* item = player.GetItem(index);
    if(item != nullptr) item->Use(player);
    system("pause");
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
        default:
            std::cout << "Unidentified command\n\n";
            return characterLoop(player, shop);
    }
}

void mainLoop(Character &player, Shop &shop){
    std::cout << "-----------------------\n";
    std::cout << "Choose an action:\n";
    std::cout << "1. Check Shop.\n";
    std::cout << "2. Check Character.\n";
    std::cout << "3. Explore.\n\n";

    int command; 
    std::cin >> command;

    switch (command){
        case 1: return shopLoop(player, shop); 
        case 2: return characterLoop(player, shop); 
        default:
            std::cout << "Unidentified command\n\n";
            return mainLoop(player, shop);
    }
}

int main(){
    Character player;
    Shop shop;

    //player.AddItem(new Item("Medium Potion", 10, MediumHeal{}));
    //shop.AddItem(new Item("Small Potion", 5, SmallHeal{}));

    InitiateShop(&shop);
    std::cout << "Your adventure has begun.\n\n";
    system("pause");
    mainLoop(player, shop);
}
