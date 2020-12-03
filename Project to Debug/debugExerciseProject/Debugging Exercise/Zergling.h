#pragma once

class Zergling
{
public:
	Zergling();
	~Zergling();

	int health = 10;
	int attack();
	void takeDamage(int damage);
	bool isAlive(Zergling ling);
};

