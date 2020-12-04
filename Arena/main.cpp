#include <iostream>
#include <ctime>
#include "combatant.h"

int main()
{
	std::srand((int)time(NULL));

	bool finished = false;
	Combatant team1[4];
	Combatant team2[4];
	int j = 0;
	int target = 0;

	for (int i = 0; i < 4; i++)
	{
		team1[i].health = 100;
		team1[i].identifier = 65 + i;
	}
	for (int i = 0; i < 4; i++)
	{
		team2[i].health = 100;
		team2[i].identifier = 65 + i;
	}

	while (!finished)
	{
		for (int i = 0; i < 4; i++)
		{
			if (team1[i].health > 0)
			{
				if ((target > -1) && (target < 4))
				{
					if (!(team2[target].health > 0))
					{
						for (int i = 0; i < 4; i++)
						{
							if (team2[i].health > 0)
							{
								j++;
							}

						}
						if (j > 0)
						{
							while (!(team2[target].health > 0) || target == 4)
							{
								target = (std::rand() / (RAND_MAX / 4));
							}
						}					
					}
				}
			}
			int attack = team1[i].attack();
			team2[target].takeDamage(attack);
			std::cout << "Team 1 member " << team1[i].identifier << " attacks Team 2 member " << team2[target].identifier << " for " << attack << " damage." << std::endl;
		}

		for (int i = 0; i < 4; i++)
		{
			if (team2[i].health > 0)
			{
				if (target > -1 && target < 4)
				{
					if (!(team1[target].health > 0))
					{
						for (int i = 0; i < 4; i++)
						{
							if (team1[i].health > 0)
							{
								j++;
							}

						}
						if (j > 0)
						{
							while (!(team1[target].health > 0) || target == 4)
							{
								target = (std::rand() / (RAND_MAX / 4));
							}
						}
					}
				}
			}
			int attack = team2[i].attack();
			team1[target].takeDamage(attack);
			std::cout << "Team 1 member " << team2[i].identifier << " attacks Team 2 member " << team1[target].identifier << " for " << attack << " damage." << std::endl;

		}

		j = 0;
		for (int i = 0; i < 4; i++)
		{
			if (team1[i].health > 0)
			{
				j++;
			}
		}
		if (j == 0)
		{
			finished = true;
		}
		j = 0;
		for (int i = 0; i < 4; i++)
		{
			if (team1[i].health > 0)
			{
				j++;
			}
		}
		if (j == 0)
		{
			finished = true;
		}
		j = 0;

		bool sorted = false;

		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < 3; i++)
			{
				if (team1[i].health < team1[i + 1].health)
				{
					char holdIdentifier = team1[i].identifier;
					int holdHealth = team1[i].health;

					team1[i].health = team1[i + 1].health;
					team1[i].identifier = team1[i + 1].identifier;

					team1[i + 1].identifier = holdIdentifier;
					team1[i + 1].health = holdHealth;
				}
			}
		}
		sorted = false;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < 3; i++)
			{
				if (team2[i].health < team2[i + 1].health)
				{
					char holdIdentifier = team2[i].identifier;
					int holdHealth = team2[i].health;

					team2[i].health = team2[i + 1].health;
					team2[i].identifier = team2[i + 1].identifier;

					team2[i + 1].identifier = holdIdentifier;
					team2[i + 1].health = holdHealth;
				}
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (team1[i].health > 0)
		{
			j++;
		}
	}
	if (j != 0)
	{
		std::cout << "Victory: Team 1" << std::endl;
	}
	else
	{
		std::cout << "Victory: Team 2" << std::endl;
	}



	return 1;
}