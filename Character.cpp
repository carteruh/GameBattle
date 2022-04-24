#include <iostream>
#include <string>
#include "Character.h"
using namespace std;



Character::Character() {
	this -> characterName = "Unknown";
	this -> characterRace = "Unknown";
	this->characterLevel = 0;
	this->characterHealth = 100;
}

Character::Character(string name, string race, int level, int health) {
	this->characterName = name;
	this->characterRace = race;
	this->characterLevel = level;
	this->characterHealth = health;
}

string Character::getcharacterName() { return characterName; }
string Character::getcharacterRace() { return characterRace; }
int Character::getcharacterLevel() { return characterLevel; }
int Character::getcharacterHealth() { return characterHealth; }

void Character::setcharacterName(string name) {
	this->characterName = name;
}
void Character::setcharacterRace(string race) {
	this->characterRace = race;
}
void Character::setcharacterLevel(int level) {
	this->characterLevel = level;
}
void Character::setcharacterHealth(int health) {
	this->characterHealth = health;
}



void Character::PrintInfo() {
	cout << "Character Information:" << endl;
	cout << "Character Name: " << getcharacterName() << endl;
	cout << "Character Race: " << getcharacterRace() << endl;
	cout << "Character Level: " << getcharacterLevel() << endl;
	cout << "Character Health: " << getcharacterHealth() << endl;
}

Character::~Character() {
	cout << "Character deleted" << endl;
}
