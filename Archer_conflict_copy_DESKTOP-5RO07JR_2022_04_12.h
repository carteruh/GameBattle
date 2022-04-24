#include "Character.h"
#include "Arrow.h"
#include <iostream>
#include <string>

using namespace std;

class Archer : public Character{
public:
	Archer();
	Archer(string name, string race);
	~Archer();
	void addArrowType(Arrow newarrow);

	int getEnergy();
	int getNumArrows();

	void setEnergy(int newenergy);
	void setNumArrows(int arrownum);

	void Attack(Character* target, string arrowtype);
private:
	Arrow* arrows; 
	int energy;
	int numArrows = 20;
};
