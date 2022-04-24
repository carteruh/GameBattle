#include <iostream>
#include <string>
#include "Arrow.h"


using namespace std;

Arrow::Arrow() {
	this->name = "Unknown";
	this->damage = 0;
	this->energy = 0;
}

Arrow::Arrow(string Arrowname, int Arrowdamage, int Arrowenergy) {
	this->name = Arrowname;
	this->damage = Arrowdamage;
	this->energy = Arrowenergy;
}


string Arrow::getName() {
	return name;
}

int Arrow::getDamage() {
	return damage;
}

int Arrow::getEnergy() {
	return energy;
}

void Arrow::setName(string newName) {
	this->name = newName;
}

void Arrow::setDamage(int newDamage) {
	this->damage = newDamage;
}

void Arrow::setEnergy(int newEnergy) {
	this->energy = newEnergy;
}