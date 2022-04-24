#include <iostream>
#include <string>
#include "Archer.h"
#include "Arrow.h"

Archer::Archer() : Character() {
	this->energy = 100;
	this->currentArrow = nullptr;
	this->count = 0;
	for (int i = 0; i < numArrows; i++) {
		arrows[i] = nullptr;
	}
}
Archer::Archer(string name, string race, int level, int health) : Character(name, race, level, health) {
	this -> energy = 100 + level;
	this->count = 0;
	this->currentArrow = nullptr;
	for (int i = 0; i < numArrows; i++) {
		arrows[i] = nullptr;
	}

}

bool Archer::addArrowType(Arrow* newarrow) {
	if (count >= numArrows) {
		return false;
	}
	int pos = 0;
	
	for (int i = 0; i < numArrows; i++) {
		if (arrows[i] == nullptr) {
			pos = i;
			break;
		}
	}
	this->arrows[pos] = newarrow;
	this->count++;
	return true;
}

Archer::~Archer() {
	cout << "Archer arrow types is removed." << endl; 
	for (int i = 0; i < numArrows; i++) {
		if (arrows[i] != nullptr) {
			delete arrows[i];
			arrows[i] = nullptr;
		}
	}
	this->count = 0;
}

bool Archer::removeArrowType(string& removeArrow) {
	int pos = 0;
	for (int i = 0; i < numArrows; i++) {
		if (arrows[i] != nullptr) {
			if (removeArrow == arrows[i]->getName()) {
				pos = i; 
				break;
			}
		}
	}

	if (pos == -1) { return false; }

	delete arrows[pos];
	arrows[pos] = nullptr;
	count--;
	return true;
}

int Archer::getEnergy() { return energy; }
int Archer::getNumArrows() { return count; }

void Archer::setEnergy(int newenergy) {
	this->energy = newenergy;
}


void Archer::EquipWeapon(string& newArrow) {
	for (int i = 0; i < numArrows; i++) {
		if (arrows[i] != nullptr) {
			if (newArrow == arrows[i]->getName()) {
				this->currentArrow = arrows[i];
			}
		}
	}
}

void Archer::Attack(Character* target) {
	if (energy >= currentArrow->getEnergy()) {
		if (currentArrow != nullptr) {
			int healthafterdamage = target->getcharacterHealth() - (currentArrow->getDamage() + 0.25 * getcharacterLevel());
			target->setcharacterHealth(healthafterdamage);
			this->energy -= currentArrow->getEnergy();
		}
		else {
			cout << "No arrow equipped!" << endl;
		}
	}
	else {
		cout << "Not enough energy to attack! Rest to restore your energy!" << endl;
	}
}

string Archer::getType() {
	return "Archer";
}

void Archer::PrintInfo() {
	cout << "Archer Information:" << endl;
	cout << "Archer Name: " << getcharacterName() << endl;
	cout << "Archer Race: " << getcharacterRace() << endl;
	cout << "Archer Level: " << getcharacterLevel() << endl;
	cout << "Archer Health: " << getcharacterHealth() << endl;
	cout << "Archer Energy: " << energy << endl;
	cout << "Archer Arrow Type: " << currentArrow->getName() << " Arrow" << endl;
}

void Archer::Rest() {
	this->energy += 25;
}