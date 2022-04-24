
#include <iostream>
#include <string>

using namespace std;

#pragma once
class Arrow {
public:
	Arrow();
	Arrow(string Arrowname, int Arrowdamage, int Arrowenergy);

	string getName();
	int getDamage();
	int getEnergy();

	void setName(string newName);
	void setDamage(int newDamage);
	void setEnergy(int newEnergy);

private:
	string name;
	int damage;
	int energy;

};
