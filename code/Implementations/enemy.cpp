#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include "../Headers/enemy.h"
#include "../Headers/character.h"
#include "../Headers/items.h"

std::ostream& operator<<(std::ostream& os, const Enemy& enemy){
    os << enemy.Health << "HP";
    return os;
}

void Enemy::Hit(double damage){
    Health -= damage;
}
void Enemy::Kill(){
    std::cout << Name << " died!!\n";
    delete(this);
}

void Enemy::Attack(Character& character) {
    int attackIndex = rand() % Attacks.size(); 
    Attacks[attackIndex]->Attack(*this, character);
}

double Enemy::GetDamage() const { 
    return rand() % int(Damage) + 2; 
}
double Enemy::GetHealth() const { return Health; }
std::string Enemy::GetName() const { return Name; }

Item* Enemy::GetDrop() { 
    int dropIndex = rand() % Drops.size();
    Item* drop = Drops[dropIndex];
    Drops.erase(Drops.begin() + dropIndex);
    return drop;
}
int Enemy::GetMoney() const { return DropMoney; }

void BasicMeleeAttack::Attack(Enemy& enemy, Character& character)const{
    double damage = int(enemy.GetDamage());
    character.Hit(damage);
    std::cout << enemy.GetName() << " swings its weapon lightly, hitting the player for " << damage << "HP!\n";
}
void BasicRangedAttack::Attack(Enemy& enemy, Character& character)const{
    double damage = int(enemy.GetDamage());
    character.Hit(damage);
    std::cout << enemy.GetName() << " shoots a light projectile, hitting the player for " << damage << "HP!\n";
}
void HeavyMeleeAttack::Attack(Enemy& enemy, Character& character)const{
    double damage = int(enemy.GetDamage() * 1.3f);
    character.Hit(damage);
    std::cout << enemy.GetName() << " swings its weapon heavily, hitting the player for " << damage << "HP!\n";
}
void HeavyRangedAttack::Attack(Enemy& enemy, Character& character)const{
    double damage = int(enemy.GetDamage() * 1.3f);
    character.Hit(damage);
    std::cout << enemy.GetName() << " shoots a heavy projectile, hitting the player for " << damage << "HP!\n";
}
void TreeAttack::Attack(Enemy& enemy, Character& character) const {
    std::cout << "The tree rustles its leaves...\n";
}