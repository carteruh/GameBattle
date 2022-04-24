#include <iostream>
#include <string>
#include <fstream>
#include "Archer.h"
#include "Soldier.h"
#include "PlayersList.h"
#include "Arrow.h"
#include "Weapon.h"

using namespace std;

const int MAX_Players = 2;

void Reload(string filename, PlayersList* myPlayers) {
	// Read file name 
	// Take them information as inputs
	
	ifstream loadGame;

	loadGame.open(filename);                      //Checks and opens a SaveFile.txt if a game is saved. If not then it exits out.
	if (!loadGame.is_open()) {
		cout << "File not found." << endl;
		exit(-1);
	}

	string Player1Type;                             //The SaveFile has the Player 1 and Player 2 information and the ifstream will load the character information in
	loadGame >> Player1Type;

	if (Player1Type == "Soldier") {
		int SoldierLevel, SoldierHealth;
		string SoldierName, SoldierRace;
		loadGame >> SoldierName >> SoldierRace >> SoldierLevel >> SoldierHealth;
		Soldier* Player1 = new Soldier(SoldierName, SoldierRace, SoldierLevel, SoldierHealth);

		string AxeName = "Axe";
		int AxeDamage = 35;
		int AxeStamina = 35;
		Weapon* Axe = new Weapon(AxeName, AxeDamage, AxeStamina);
		Player1->AddWeapon(Axe);

		string SwordName = "Sword";
		int SwordDamage = 25;
		int SwordStamina = 30;
		Weapon* Sword = new Weapon(SwordName, SwordDamage, SwordStamina);
		Player1->AddWeapon(Sword);

		string HammerName = "SledgeHammer";
		int HammerDamage = 55;
		int HammerStamina = 55;
		Weapon* Hammer = new Weapon(HammerName, HammerDamage, HammerStamina);
		Player1->AddWeapon(Hammer);

		Player1->EquipWeapon(SwordName);
		myPlayers->addPlayer(*Player1);
	}
	else if (Player1Type == "Archer") {
		int ArcherLevel, ArcherHealth;
		string ArcherName, ArcherRace;
		loadGame >> ArcherName >> ArcherRace >> ArcherLevel >> ArcherHealth;
		Archer* Player1 = new Archer(ArcherName, ArcherRace, ArcherLevel, ArcherHealth);

		string FirearrowName = "Fire";
		int FirearrowDamage = 30;
		int FirearrowEnergy = 25;
		Arrow* FireArrow = new Arrow(FirearrowName, FirearrowDamage, FirearrowEnergy);
		Player1->addArrowType(FireArrow);
		string IcearrowName = "Ice";
		int IcearrowDamage = 20;
		int IcearrowEnergy = 15;
		Arrow* IceArrow = new Arrow(IcearrowName, IcearrowDamage, IcearrowEnergy);
		Player1->addArrowType(IceArrow);

		string LightningarrowName = "Lightning";
		int LightningarrowDamage = 40;
		int LightningarrowEnergy = 40;
		Arrow* LightningArrow = new Arrow(LightningarrowName, LightningarrowDamage, LightningarrowEnergy);
		Player1->addArrowType(LightningArrow);
		
		Player1->EquipWeapon(IcearrowName);
		myPlayers->addPlayer(*Player1);
	}

	string Player2Type;
	loadGame >> Player2Type;

	if (Player2Type == "Soldier") {
		int SoldierLevel, SoldierHealth;
		string SoldierName, SoldierRace;
		loadGame >> SoldierName >> SoldierRace >> SoldierLevel >> SoldierHealth;
		Soldier* Player2 = new Soldier(SoldierName, SoldierRace, SoldierLevel, SoldierHealth);

		string AxeName = "Axe";
		int AxeDamage = 35;
		int AxeStamina = 35;
		Weapon* Axe = new Weapon(AxeName, AxeDamage, AxeStamina);
		Player2->AddWeapon(Axe);

		string SwordName = "Sword";
		int SwordDamage = 25;
		int SwordStamina = 30;
		Weapon* Sword = new Weapon(SwordName, SwordDamage, SwordStamina);
		Player2->AddWeapon(Sword);

		string HammerName = "SledgeHammer";
		int HammerDamage = 55;
		int HammerStamina = 55;
		Weapon* Hammer = new Weapon(HammerName, HammerDamage, HammerStamina);
		Player2->AddWeapon(Hammer);

		Player2->EquipWeapon(SwordName);
		myPlayers->addPlayer(*Player2);
	}
	else if (Player2Type == "Archer") {
		int ArcherLevel, ArcherHealth;
		string ArcherName, ArcherRace;
		loadGame >> ArcherName >> ArcherRace >> ArcherLevel >> ArcherHealth;
		Archer* Player2 = new Archer(ArcherName, ArcherRace, ArcherLevel, ArcherHealth);

		string FirearrowName = "Fire";
		int FirearrowDamage = 30;
		int FirearrowEnergy = 25;
		Arrow* FireArrow = new Arrow(FirearrowName, FirearrowDamage, FirearrowEnergy);
		Player2->addArrowType(FireArrow);
		string IcearrowName = "Ice";
		int IcearrowDamage = 20;
		int IcearrowEnergy = 15;
		Arrow* IceArrow = new Arrow(IcearrowName, IcearrowDamage, IcearrowEnergy);
		Player2->addArrowType(IceArrow);

		string LightningarrowName = "Lightning";
		int LightningarrowDamage = 40;
		int LightningarrowEnergy = 40;
		Arrow* LightningArrow = new Arrow(LightningarrowName, LightningarrowDamage, LightningarrowEnergy);
		Player2->addArrowType(LightningArrow);

		Player2->EquipWeapon(IcearrowName);
		myPlayers->addPlayer(*Player2);
	}
	loadGame.close();
}

void SaveGame(PlayersList* myPlayers) {                  // This will output all of Player 1 and Player 2 character information into a SaveFile.txt
	ofstream saveFile;								     //The SaveFile can be extracted using the Reload command.
	saveFile.open("SaveFile.txt");
	for (int i = 0; i < MAX_Players; i++) {
		saveFile << myPlayers->getCharacter(i).getType() << endl;
		saveFile << myPlayers->getCharacter(i).getcharacterName() << endl;
		saveFile << myPlayers->getCharacter(i).getcharacterRace() << endl;
		saveFile << myPlayers->getCharacter(i).getcharacterLevel() << endl;
		saveFile << myPlayers->getCharacter(i).getcharacterHealth() << endl;
		cout << endl;
	}
	saveFile.close();
}

int main() {
	
	
	
	int startgame = 1;
	do {
		cout << "--------------------------------------------------------------" << endl;       // Asks the user if they want to start a new game or saved game
		cout << "GAME BATTLE:" << endl;
		cout << "0 - exit game" << endl;
		cout << "1 - New Game" << endl;
		cout << "2 - Load Saved Game" << endl;
		cout << "--------------------------------------------------------------" << endl;
		cout << endl;
		
		cin >> startgame;
		system("cls");
		PlayersList* myPlayers = new PlayersList();    // A call to the PlayersList object will store all the existing Players in the game.


		if (startgame == 0) {      // If the user presses 0 from the menu, this will exit the program.
			exit(-1);
		}
		else if (startgame == 2) {             // The user pressing 2 will initiate the reading of a saved game text file that will take in all saved Player information from the Reload function.
			string filename = "SaveFile.txt";
			Reload(filename, myPlayers);
		}
		else if (startgame == 1) {    // The user pressing 1 will initiate the user to manually enter the character information during runtime.

			cout << "--------------------------------------------------------------" << endl;        // The player must first decide between Soldier or Archer class
			cout << "Choose your first character:" << endl;
			cout << "0 - exit game" << endl;
			cout << "1 - Soldier" << endl;
			cout << "2 - Archer" << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << endl;
			int userinput;
			cin >> userinput;
			system("cls");
			
			if (userinput == 0) {
				exit(-1);
			}
			else if (userinput == 1) {     // Option 1 will create a soldier class and append the user information to the PlayersList for Player 1
				string soldierName;
				string soldierRace;
				int soldierLevel;
				int soldierHealth;
				cout << "--------------------------------------------------------------" << endl;
				cout << "Enter Soldier Information: " << endl;
				cout << "Name: " << endl;
				cout << "Race: " << endl;
				cout << "Level: " << endl;
				cout << "Health: " << endl;
				cout << "--------------------------------------------------------------" << endl;

				cin >> soldierName >> soldierRace >> soldierLevel >> soldierHealth;
				system("cls");
				Soldier* SoldierPlayer1 = new Soldier(soldierName, soldierRace, soldierLevel, soldierHealth);

				string AxeName = "Axe";
				int AxeDamage = 35;
				int AxeStamina = 35;
				Weapon* Axe = new Weapon(AxeName, AxeDamage, AxeStamina);
				SoldierPlayer1->AddWeapon(Axe);

				string SwordName = "Sword";
				int SwordDamage = 25;
				int SwordStamina = 30;
				Weapon* Sword = new Weapon(SwordName, SwordDamage, SwordStamina);
				SoldierPlayer1->AddWeapon(Sword);

				string HammerName = "SledgeHammer";
				int HammerDamage = 55;
				int HammerStamina = 55;
				Weapon* Hammer = new Weapon(HammerName, HammerDamage, HammerStamina);
				SoldierPlayer1->AddWeapon(Hammer);

				SoldierPlayer1->EquipWeapon(SwordName);
				myPlayers->addPlayer(*SoldierPlayer1);

			}
			else if (userinput == 2) {      //Option 2 will create an Archer class that will append to the PlayersList for Player 1
				string archerName;
				string archerRace;
				int archerLevel;
				int archerHealth;
				cout << "--------------------------------------------------------------" << endl;
				cout << "Enter Archer Information:" << endl;
				cout << "Name: " << endl;
				cout << "Race: " << endl;
				cout << "Level: " << endl;
				cout << "Health: " << endl;
				cout << "--------------------------------------------------------------" << endl;
				cin >> archerName >> archerRace >> archerLevel >> archerHealth;
				system("cls");
				Archer* ArcherPlayer1 = new Archer(archerName, archerRace, archerLevel, archerHealth);

				string FirearrowName = "Fire";
				int FirearrowDamage = 30;
				int FirearrowEnergy = 25;
				Arrow* FireArrow = new Arrow(FirearrowName, FirearrowDamage, FirearrowEnergy);
				ArcherPlayer1->addArrowType(FireArrow);
				string IcearrowName = "Ice";
				int IcearrowDamage = 20;
				int IcearrowEnergy = 15;
				Arrow* IceArrow = new Arrow(IcearrowName, IcearrowDamage, IcearrowEnergy);
				ArcherPlayer1->addArrowType(IceArrow);

				string LightningarrowName = "Lightning";
				int LightningarrowDamage = 40;
				int LightningarrowEnergy = 40;
				Arrow* LightningArrow = new Arrow(LightningarrowName, LightningarrowDamage, LightningarrowEnergy);
				ArcherPlayer1->addArrowType(LightningArrow);

				ArcherPlayer1->EquipWeapon(IcearrowName);
				myPlayers->addPlayer(*ArcherPlayer1);
				cout << endl;
			}

			cout << "--------------------------------------------------------------" << endl;    // This is the selection to create Player 2 and resembles the same concept for creating character as Player 1.
			cout << "Choose a second character:" << endl;
			cout << "0 - exit game" << endl;
			cout << "1 - Soldier" << endl;
			cout << "2 - Archer" << endl;
			cout << "--------------------------------------------------------------" << endl;
			int secondinput;
			cin >> secondinput;
			system("cls");
			cout << endl;
			if (secondinput == 0) { 
				exit(-1);
			}
			else if (secondinput == 1) {
				string soldierName;
				string soldierRace;
				int soldierLevel;
				int soldierHealth;
				cout << "--------------------------------------------------------------" << endl;
				cout << "Enter Soldier Information:" << endl;
				cout << "Name: " << endl;
				cout << "Race: " << endl;
				cout << "Level: " << endl;
				cout << "Health: " << endl;
				cout << "--------------------------------------------------------------" << endl;

				cin >> soldierName >> soldierRace >> soldierLevel >> soldierHealth;
				system("cls");
				Soldier* SoldierPlayer2 = new Soldier(soldierName, soldierRace, soldierLevel, soldierHealth);

				string AxeName = "Axe";
				int AxeDamage = 35;
				int AxeStamina = 35;
				Weapon* Axe = new Weapon(AxeName, AxeDamage, AxeStamina);
				SoldierPlayer2->AddWeapon(Axe);

				string SwordName = "Sword";
				int SwordDamage = 25;
				int SwordStamina = 30;
				Weapon* Sword = new Weapon(SwordName, SwordDamage, SwordStamina);
				SoldierPlayer2->AddWeapon(Sword);

				string HammerName = "SledgeHammer";
				int HammerDamage = 55;
				int HammerStamina = 55;
				Weapon* Hammer = new Weapon(HammerName, HammerDamage, HammerStamina);
				SoldierPlayer2->AddWeapon(Hammer);

				SoldierPlayer2->EquipWeapon(SwordName);
				myPlayers->addPlayer(*SoldierPlayer2);
			}
			else if (secondinput == 2) {
				string archerName;
				string archerRace;
				int archerLevel;
				int archerHealth;
				cout << "--------------------------------------------------------------" << endl;
				cout << "Enter Archer Information:" << endl;
				cout << "Name: " << endl;
				cout << "Race: " << endl;
				cout << "Level: " << endl;
				cout << "Health: " << endl;
				cout << "--------------------------------------------------------------" << endl;
				cin >> archerName >> archerRace >> archerLevel >> archerHealth;
				system("cls");
				Archer* ArcherPlayer2 = new Archer(archerName, archerRace, archerLevel, archerHealth);

				string FirearrowName = "Fire";
				int FirearrowDamage = 30;
				int FirearrowEnergy = 25;
				Arrow* FireArrow = new Arrow(FirearrowName, FirearrowDamage, FirearrowEnergy);
				ArcherPlayer2->addArrowType(FireArrow);
				string IcearrowName = "Ice";
				int IcearrowDamage = 20;
				int IcearrowEnergy = 15;
				Arrow* IceArrow = new Arrow(IcearrowName, IcearrowDamage, IcearrowEnergy);
				ArcherPlayer2->addArrowType(IceArrow);

				string LightningarrowName = "Lightning";
				int LightningarrowDamage = 40;
				int LightningarrowEnergy = 40;
				Arrow* LightningArrow = new Arrow(LightningarrowName, LightningarrowDamage, LightningarrowEnergy);
				ArcherPlayer2->addArrowType(LightningArrow);

				ArcherPlayer2->EquipWeapon(IcearrowName);
				myPlayers->addPlayer(*ArcherPlayer2);
				cout << endl;
			}
		}
		
		
		
		while (myPlayers->getCharacter(0).getcharacterHealth() > 0 && myPlayers->getCharacter(1).getcharacterHealth() > 0){     // To run the game loop, a while loop that checks both Players 1 and Player 2 are above 0 is implemented.
			for (int i = 0; i < MAX_Players; i++) {         // A for loop is nested in this while loop to develop alternate turns for each Player.
				int playerdecision = 0;

				if (myPlayers->getCharacter(i).getcharacterHealth() <= 0) {    // This condition will check at the beginning of the loop if the current character health is below or equal to 0. Signaling the end of the game.
					break;
				}

				cout << "--------------------------------------------------------------" << endl;
				cout << "GameBattle" << endl;
				cout << "Player " << i + 1 << "'s turn" << endl;
				myPlayers->getCharacter(i).PrintInfo();        // Prints the current character's info.
				cout << "0 - exit game" << endl;
				cout << "1 - Save Game" << endl;
				cout << "2 - Attack" << endl;
				cout << "3 - Rest" << endl;
				cout << "4 - Equip New Weapon" << endl;
				cout << "--------------------------------------------------------------" << endl;
				cout << endl;
				
				cin >> playerdecision;
				system("cls");
				cout << endl;

				if (playerdecision == 0) {
					exit(-1);
				}
				else if (playerdecision == 1) {
					SaveGame(myPlayers);
				}
				else if (playerdecision == 2) {
					myPlayers->getCharacter(i).Attack(&myPlayers->getCharacter((i + (MAX_Players + 1)) % 2));     // The attack method uses the modulus of the PlayersList characters to attack the opposing Player.
				}
				else if (playerdecision == 3) {
					myPlayers->getCharacter(i).Rest();
				}
				else if (playerdecision == 4) {
					if (myPlayers->getCharacter(i).getType() == "Soldier") {     // Checks the current character's class type.
						cout << "--------------------------------------------------------------" << endl;
						cout << "GameBattle" << endl;
						cout << "Pick a weapon: " << endl;
						cout << "0 - Axe" << endl;
						cout << "1 - Sword" << endl;
						cout << "2 - Sledge Hammer" << endl;
						cout << "--------------------------------------------------------------" << endl;
						int weaponchoice;
						cin >> weaponchoice;
						system("cls");
						string weaponName;
						if (weaponchoice == 0) {     // Conditions are designed to call the correct weapon to the EquipWeapon method.
							weaponName = "Axe";
						}
						else if (weaponchoice == 1) {
							weaponName = "Sword";
						}
						else if (weaponchoice == 2) {
							weaponName = "SledgeHammer";
						}
						myPlayers->getCharacter(i).EquipWeapon(weaponName);
					}
					else if (myPlayers->getCharacter(i).getType() == "Archer") {
						cout << "--------------------------------------------------------------" << endl;
						cout << "GameBattle" << endl;
						cout << "Pick an arrow type: " << endl;
						cout << "0 - Fire Arrow" << endl;
						cout << "1 - Ice Arrow" << endl;
						cout << "2 - Lightning Arrow" << endl;
						cout << "--------------------------------------------------------------" << endl;
						int weaponchoice;
						cin >> weaponchoice;
						system("cls");
						string weaponName;
						if (weaponchoice == 0) {
							weaponName = "Fire";
						}
						else if (weaponchoice == 1) {
							weaponName = "Ice";
						}
						else if (weaponchoice == 2) {
							weaponName = "Lightning";
						}
						myPlayers->getCharacter(i).EquipWeapon(weaponName);
					}
				}
			}
		}

		for (int i = 0; i < MAX_Players; i++) {								// Checks which player has above 0 health and determines the winner.
			if (myPlayers->getCharacter(i).getcharacterHealth() > 0) {
				cout << "Player " << i + 1 << " wins!" << endl;
			}
		}
		cout << endl;
		cout << "--------------------------------------------------------------" << endl;
		cout << "GameBattle" << endl;
		cout << "Do you want to play again?" << endl;
		cout << "0 - No" << endl;
		cout << "1 - Yes" << endl;
		cout << "--------------------------------------------------------------" << endl;
		int endgame;
		cin >> endgame;
		system("cls");
		if (endgame == 0) {             // Calls the destructor for PlayersList and asks the user to play again or exit.
			delete myPlayers;
			startgame = 0;
		}
		else if (endgame == 1) {
			delete myPlayers;
			startgame = 1;
		}

		

	} while (startgame != 0);

	
	
	// system("cls") can clear screen 
	
	return 0;
}