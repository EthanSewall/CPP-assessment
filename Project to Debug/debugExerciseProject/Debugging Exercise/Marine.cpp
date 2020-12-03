#include "Marine.h"



Marine::Marine()
{
   health = 20;
}


Marine::~Marine()
{
}

int Marine::attack()
{
	return 10;
}

void Marine::takeDamage(int damage)
{
	health -= damage;
}

bool Marine::isAlive(Marine marine)
{
	if (marine.health > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
