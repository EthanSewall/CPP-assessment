// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2019

#include <iostream>
#include <ctime>
#include "Entity.h"
#include "Marine.h"
#include "Zergling.h"
#include "Main.h"

using std::cout;
using std::endl;

// Is there a Marine Alive?
bool marineAlive(Marine *squad, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (squad[i].isAlive(squad[i]))
		{
			return true;
		}
	}
	return false;
}

// Is there a zergling Alive
bool zerglingAlive(Zergling *swarm, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (swarm[i].isAlive(swarm[i]))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	Marine squad[10];
	Zergling swarm[20];

	float target = 0;

	std::srand(time(NULL));

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;
	
	while (marineAlive(squad, 10) && zerglingAlive(swarm, 20)) // Attack each other until only one team is left alive
	{
		if (marineAlive(squad, 10)) // if there's at least one marine alive
		{
			for (size_t i = 0; i < 10; i++) // go through the squad
			{
				if (squad[i].isAlive(squad[i]))
				{
					while (!swarm[(int)target].isAlive(swarm[(int)target]))
					{
						target = round((std::rand() / RAND_MAX) * 19);
					}
					cout << "Marine " << i << " attacks Zergling "<< target << " for " << squad[i].attack() << " damage. " << endl;
					int damage = squad[i].attack();
					swarm[i].takeDamage(damage);
					if (!swarm[i].isAlive(swarm[i])) // if the zergling dies, it is marked as such
					{
						cout << "The zergling target dies." << endl;
					}
				}
			}
		}
		if (zerglingAlive(swarm, 20)) // if there's at least one zergling alive
		{
			for (size_t i = 0; i < 10; i++) // loop through zerglings
			{
				cout << "A zergling attacks for " << swarm[i].attack() << " damage." << endl;
				squad[i].takeDamage(swarm[i].attack());
				if (squad[i].isAlive(squad[i]))
				{

				}
				else
				{
					cout << "The marine succumbs to his wounds." << endl;
					cout << "There are ??? marines left." << endl;
				}
			}
		}
		target = 0;
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marineAlive(squad, 10))
	{
		cout << "The Marines win." << endl;
	} else 
	{
		cout << "The Zerg win." << endl;
	}
}



