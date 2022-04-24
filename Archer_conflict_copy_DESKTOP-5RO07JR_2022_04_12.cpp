#include <iostream>
#include <string>
#include "Archer.h"
#include "Arrow.h"

Archer::Archer() : Character() {
	this->energy = 100;
	this->numArrows = 0;
	this->arrows = nullptr;
}
Archer::Archer(string name, string race, int level, int health, int numArrowsize, Arrow* arrowarray) : Character(name, race, level, health) {
	int energy;
	int numArrows = numArrowsize;
	this->arrows = new Arrow[numArrows];

	for (int i = 0; i < numArrows; i++) {
		arrows[i] = arrowarray[i];
	}

}

void Archer::addArrowType(Arrow newarrow);

int Archer::getEnergy() { return energy; }
int Archer::getNumArrows() { return numArrows; }

void Archer::setEnergy(int newenergy) {
	this->energy = newenergy;
}
void Archer::setNumArrows(int arrownum) {
	this->numArrows = arrownum;
}

void Archer::Attack(Character* target, string arrowtype);