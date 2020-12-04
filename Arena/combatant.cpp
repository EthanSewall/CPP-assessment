#include "combatant.h"
#include <cstdlib>

	int health;
	char identifier;

	int Combatant::attack()
	{
		return(std::rand() / (RAND_MAX / 20));
	}

	void Combatant::takeDamage(int damage)
	{
		health -= damage;
	}
