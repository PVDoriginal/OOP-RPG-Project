#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "shop.h"
#include "character.h"

template <typename T>
class Singleton{
    private:
    static Singleton* instancePtr; 
    Singleton() {}

    public:
    Singleton(const Singleton& obj) = delete; 

    void UseItem(Character &player, Shop &shop){
        player.ShowUsableItems();
        std::cout << "Item index: ";
        int index;
        std::cin >> index;
        std::shared_ptr<Item> item(player.GetItem(index));
        if(item != nullptr) item->Use(player);
        system("pause");
    }

    T GetRandomDamage(T characterDamage, T characterDamageMulti) const {
        return int(characterDamage * characterDamageMulti + rand()%7 - 3);
    }

    static Singleton* getInstance(){
        if (instancePtr == NULL) {
            instancePtr = new Singleton(); 
            return instancePtr; 
        }
        else return instancePtr;
    }
};
 
Singleton<double>* Singleton<double> :: instancePtr = NULL; 
Singleton<float>* Singleton<float> :: instancePtr = NULL; 
Singleton<int>* Singleton<int> :: instancePtr = NULL; 
 