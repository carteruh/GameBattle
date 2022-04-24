#include <iostream>
#include <string>
#include "Character.h"
#include "Weapon.h"

using namespace std;
const int MAX_WEAPONS = 3;
#pragma once
class Soldier : public Character {
public:
	Soldier();
	Soldier(string name, string race, int level, int health);

	~Soldier();

	void Rest();
	Weapon& getsoldierWeapon();
	int getSoldierStamina();
	
	bool AddWeapon(Weapon* newWeapon);
	bool removeWeapon(string& weaponName);
	void EquipWeapon(string&);
	void printWeapon();
	void Attack(Character* target);
	string getType();
	void PrintInfo();
private:
	Weapon* soldierWeapon;
	int soldierStamina;
	Weapon* weapons[MAX_WEAPONS];
	int count;
	


};
