#include "PlayersList.h"
#include "Character.h"
#include "Soldier.h"
#include "Archer.h"

#include <iostream>
#include <string>

using namespace std;

PlayersList::PlayersList() {
	for (int i = 0; i < MAX_SIZE; i++) {
		this->Players[i] = nullptr;
	}
	this->count = 0;
}


bool PlayersList::addPlayer(Character& newCharacter) {
	if (count >= MAX_SIZE) {
		return false;
	}
	int pos = 0;

	for (int i = 0; i < MAX_SIZE; i++) {
		if (Players[i] == nullptr) {
			pos = i;
			break;
		}
	}

	if (newCharacter.getType() == "Soldier") {
		Players[pos] = new Soldier((Soldier&)newCharacter);
	}
	else if (newCharacter.getType() == "Archer") {
		Players[pos] = new Archer((Archer&)newCharacter);
	}
	count++;
	return true;
}
bool PlayersList::removePlayer(string& removePlayer) {
	int pos = 0;
	for (int i = 0; i < numArrows; i++) {
		if (Players[i] != nullptr) {
			if (removePlayer == Players[i]->getcharacterName()) {
				pos = i;
				break;
			}
		}
	}

	if (pos == -1) { return false; }

	delete Players[pos];
	Players[pos] = nullptr;
	count--;
	return true;
}

PlayersList::~PlayersList() {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (Players[i] != nullptr) {
			delete Players[i];
			Players[i] = nullptr;
		}
	}
	cout << "Characters in the Players List is removed." << endl;
	this->count = 0;
}

Character& PlayersList::getCharacter(int playernum) {
	if (playernum >= 0 && playernum < MAX_SIZE && Players[playernum] != nullptr) {
		return *Players[playernum];
	}
	else {
		cout << "Invalid player number" << endl;
		exit(-1);
	}
}

int PlayersList::getCount() {
	return count;
}
