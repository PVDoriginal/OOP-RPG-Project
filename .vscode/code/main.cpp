#include<iostream>
#include<string>
#include<vector>
#include "Headers/character.h"
#include "Headers/items.h"
#include "Headers/shop.h"

void mainLoop(Character&, Shop&);
void shopLoop(Character&, Shop&);

void InitiateShop(Shop& shop){
    shop.AddItem(new Item("small potion", 5, SmallHeal{}));
    shop.AddItem(new Item("small potion", 5, SmallHeal{}));
    shop.AddItem(new Item("medium potion", 10, MediumHeal{}));
    shop.AddItem(new Item("big potion", 15, BigHeal{}));
}

void buyLoop(Character &player, Shop &shop){
    std::cout << "-----------------------\n";
    std::cout << "Item index: ";
    int index;
    std::cin >> index;
    shop.BuyItem(index, player);
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

void useItemLoop(Character &player){


}
void equipItemLoop(Character &player){


}

void characterLoop(Character &player){
    std::cout << "-----------------------\n";
    player.CheckInventory();
    std::cout << "\n";
    std::cout << "Choose an action:\n";
    std::cout << "1. Use item.\n";
    std::cout << "2. Equip item.\n";
    std::cout << "3. Leave.\n\n";

    int command; 
    std::cin >> command;

    switch (command){
        case 1: return useItemLoop(player); 
        case 2: return equipItemLoop(player); 
        default:
            std::cout << "Unidentified command\n\n";
            return characterLoop(player);
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
        case 2: return characterLoop(player); 
        default:
            std::cout << "Unidentified command\n\n";
            return mainLoop(player, shop);
    }
}

int main(){
    Character player;
    Shop shop;
    InitiateShop(shop);
    std::cout << "Your adventure has begun.\n\n";
    system("pause");
    mainLoop(player, shop);
}
