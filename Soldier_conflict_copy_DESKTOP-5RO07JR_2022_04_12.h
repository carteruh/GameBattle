#include <iostream>
#include <string>
#include "Character.h"
#include "Weapon.h"
using namespace std;

class Soldier : public Character {
public:
	Soldier();
	Soldier(string name, string race, int level, int health,Weapon* currentWeapon);

	Weapon getsoldierWeapon();
	int getSoldierStamina;

	
	void EquipWeapon(Weapon newWeapon);
	void printWeapon();
	void Attack(Character* target, string weapontype);
	void AddWeapon(Weapon weapon);
private:
	Weapon soldierWeapon;
	int soldierStamina;
	Weapon* weapons;
	int numWeapons = 20;


};
