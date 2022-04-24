#include <iostream>
#include <string>

#include "Weapon.h"
#include "Soldier.h"

using namespace std;

Weapon::Weapon() {
	this ->weaponName = "Unknown";
	this -> damage = 0;
	this -> cost = 0;
}
Weapon::Weapon(string name, int damage, int cost) {
	this->weaponName = name;
	this->damage = damage;
	this->cost = cost;
}



string Weapon::getweaponName() {
	return weaponName;
}
int Weapon::getdamage() {
	return damage;
}
int Weapon::getcost() {
	return cost;
}

void Weapon::setweaponName(string newname) {
	this->weaponName = newname;
}
void Weapon::setdamage(int currdamage) {
	this->damage = currdamage;
}
void Weapon::setcost(int price) {
	this->cost = price;
}