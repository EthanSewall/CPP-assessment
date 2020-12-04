#pragma once
class Combatant
{
public:

	int health;
	char identifier;

	int attack();

	void takeDamage(int damage);
};