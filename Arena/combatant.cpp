#include "combatant.h"
#include <cstdlib>
class Combatant::Combatant
{
public:

	int health;
	char identifier;

	int attack()
	{
		return(std::rand() / (RAND_MAX / 20));
	}

	void takeDamage(int damage)
	{
		health -= damage;
	}
};