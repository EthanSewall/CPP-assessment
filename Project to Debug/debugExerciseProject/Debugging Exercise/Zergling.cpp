#include "Zergling.h"



Zergling::Zergling()
{
}


Zergling::~Zergling()
{
}

int Zergling::attack()
{
	return 8;
}

void Zergling::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
		health = 0;
}

bool Zergling::isAlive(Zergling ling)
{
	if (ling.health > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
