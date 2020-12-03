#pragma once

class Marine
{
public:
	Marine();
	~Marine();
	int health = 20;

	int attack();
	void takeDamage(int damage);
	bool isAlive(Marine marine);
};

