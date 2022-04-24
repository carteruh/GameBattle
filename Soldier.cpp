#include "Soldier.h"
#include "Weapon.h"

#include <iostream>
#include <string>
using namespace std;

Soldier::Soldier() : Character() {
	this->soldierWeapon = nullptr;;
	this -> soldierStamina = 100;
	this->count = 0;
	for (int i = 0; i < MAX_WEAPONS; i++) {
		weapons[i] = nullptr;
	}
}
Soldier::Soldier(string name, string race, int level, int health ) : Character(name, race, level, health) {
	soldierStamina = 100 + level;
	this->soldierWeapon = nullptr;
	this->count = 0;
	for (int i = 0; i < MAX_WEAPONS; i++) {
		weapons[i] = nullptr;
	}
}

Soldier::~Soldier() { 
	cout << "Soldier weapons is removed" << endl;
	for (int i = 0; i < MAX_WEAPONS; i++) {
		if (weapons[i] != nullptr) {
			delete weapons[i];
			weapons[i] = nullptr;
		}
	}
	this->count = 0;
}

Weapon& Soldier::getsoldierWeapon() { return *soldierWeapon; }
int Soldier::getSoldierStamina() { return soldierStamina; }

bool Soldier::AddWeapon(Weapon* newWeapon) {
	int pos = 0;
	if (count >= MAX_WEAPONS) {
		return false;
	}

	for (int i = 0; i < MAX_WEAPONS; i++) {
		if (weapons[i] == nullptr) {
			pos = i;
			break;
		}
	}

	if (pos < 0) { return false; }

	weapons[pos] = newWeapon;
	count++;
	return true;
}

bool Soldier::removeWeapon(string& weaponName) {
	int pos = 0;
	for (int i = 0; i < MAX_WEAPONS; i++) {
		if (weapons[i] != nullptr) {
			if (weapons[i]->getweaponName() == weaponName) {
				pos = i;
				break;
			}
		}
	}

	if (pos < 0) { return false; }

	delete weapons[pos];
	weapons[pos] = nullptr;
	count--;
	return true;
}

void Soldier::EquipWeapon(string& newWeapon) {
	for (int i = 0; i < MAX_WEAPONS; i++) {
		if (weapons[i] != nullptr) {
			if (weapons[i]->getweaponName() == newWeapon) {
				this->soldierWeapon = weapons[i];
			}
		}
	}
}
void Soldier::printWeapon() {
	cout << "Weapon Name: " << soldierWeapon->getweaponName() << endl;
	cout << "Weapon Damage: " << soldierWeapon->getdamage() << endl;
	cout << "Weapon Cost: " << soldierWeapon->getcost() << endl;
}
void Soldier::Attack(Character* target) {
	if (soldierStamina >= soldierWeapon->getcost()) {
		if (soldierWeapon != nullptr) {
			int healthafterdamage = target->getcharacterHealth() - (soldierWeapon->getdamage() + 0.25 * getcharacterLevel());
			target->setcharacterHealth(healthafterdamage);
			this->soldierStamina -= soldierWeapon->getcost();
		}
		else {
			cout << "No weapon is equipped!" << endl;
		}
	}
	else {
		cout << "Not enough stamina to attack! Please rest to restore stamina!" << endl;
	}
}

string Soldier::getType() {
	return "Soldier";
}

void Soldier::PrintInfo() {
	cout << "Soldier Information:" << endl;
	cout << "Soldier Name: " << getcharacterName() << endl;
	cout << "Soldier Race: " << getcharacterRace() << endl;
	cout << "Soldier Level: " << getcharacterLevel() << endl;
	cout << "Soldier Health: " << getcharacterHealth() << endl;
	cout << "Soldier Stamina: " << soldierStamina << endl;
	cout << "Soldier Weapon: " << soldierWeapon->getweaponName() << endl;
}

void Soldier::Rest() {
	this->soldierStamina += 25;
}