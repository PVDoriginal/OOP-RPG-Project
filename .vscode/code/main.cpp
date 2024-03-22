#include<iostream>
#include<string>
#include<vector>
#include "Headers/character.h"
#include "Headers/items.h"
#include "Headers/shop.h"

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
    Damon.CheckInventory();
    shop.CheckItems();
}
