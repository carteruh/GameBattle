#include <iostream>
#include <string>

#pragma once
using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
public:
	Character();
	Character(string name, string race, int level, int health);

	virtual ~Character() ;

	string getcharacterName();
	string getcharacterRace();
	int getcharacterLevel();
	int getcharacterHealth();

	void setcharacterName(string name);
	void setcharacterRace(string race);
	void setcharacterLevel(int level);
	void setcharacterHealth(int health);
	virtual void EquipWeapon(string&) = 0;
	virtual void Rest() = 0;

	virtual void Attack(Character* target) = 0;
	virtual string getType() = 0;
	virtual void PrintInfo();

protected:
	string characterName;
	string characterRace;
	int characterLevel;
	int characterHealth;
};
#endif CHARACTER_H