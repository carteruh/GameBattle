#include "Character.h"
#include "Archer.h"
#include "Soldier.h"

#include <iostream>
#include <string>

using namespace std;
#pragma once
const int MAX_SIZE = 2;

class PlayersList {
public :
	PlayersList();
	Character& getCharacter(int playernum);
	int getCount();
	bool addPlayer(Character&);
	bool removePlayer(string&);

	~PlayersList();


private:
	Character* Players[MAX_SIZE];
	int count;
};