#include "Character.h"
#include "Arrow.h"
#include <iostream>
#include <string>

#pragma once

using namespace std;
const int numArrows = 3;
class Archer : public Character{
public:
	Archer();
	Archer(string name, string race, int level, int health);

	~Archer();

	void Rest();
	bool addArrowType(Arrow* newarrow);
	bool removeArrowType(string& removeArrow);

	int getEnergy();
	int getNumArrows();

	void setEnergy(int newenergy);
	void EquipWeapon(string&);
	void Attack(Character* target);
	string getType();
	void PrintInfo();
private:
	Arrow* arrows[numArrows];
	int energy;
	Arrow* currentArrow;
	int count;
};
