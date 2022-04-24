
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;
#pragma once
class Weapon {

public:
	Weapon();
	Weapon(string name, int damage, int cost);


	string getweaponName();
	int getdamage();
	int getcost();

	void setweaponName(string newname);
	void setdamage(int currdamage);
	void setcost(int price);

private:
	string weaponName;
	int damage;
	int cost;

};
