#include "Entity.h"



Entity::Entity()
{
	maxHealth = 20;
	health = maxHealth;
}


Entity::~Entity()
{
}

bool Entity::isAlive()
{
	if (health > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Entity::attack()
{
	return 10;
}

void Entity::takeDamage(int damage)
{
	health -= damage;
}
