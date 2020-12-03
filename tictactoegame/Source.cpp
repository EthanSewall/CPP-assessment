#include <iostream>;
#include <ctime>;
#include <cmath>;

int main()
{
	char grid[3][3] = { '_', '_','_','_','_','_','_','_','_'};
	
	std::srand(time(NULL));

	bool gameFinish = false;
	bool validInput = false;
	char inputChar1 = '\0';
	char inputChar2 = '\0';
	float row = 0;
	float column = 0;

	while (!gameFinish)
	{
		while (!validInput)
		{
			row = std::rand();
			row /= RAND_MAX;
			row *= 3;
			row = round(row);

			if (row == 3)
			{
				while (row == 3)
				{
					row = std::rand();
					row /= RAND_MAX;
					row *= 3;
					row = round(row);
				}
			}

			column = std::rand();
			column /= RAND_MAX;
			column *= 3;
			column = round(column);

			if (column == 3)
			{
				while (column == 3)
				{
					column = std::rand();
					column /= RAND_MAX;
					column *= 3;
					column = round(column);
				}
			}

			if (grid[(int)row][(int)column] == '_')
			{
				validInput = true;
				grid[(int)row][(int)column] = 'X';
				std::cout << grid[0][0] << " " << grid[0][1] << " " << grid[0][2] << std::endl;
				std::cout << grid[1][0] << " " << grid[1][1] << " " << grid[1][2] << std::endl;
				std::cout << grid[2][0] << " " << grid[2][1] << " " << grid[2][2] << std::endl;
				std::cout << " " << std::endl;

			}
		}

		if ((grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X') || (grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X') || (grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X') || (grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X') || (grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X') || (grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X') || (grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X') || (grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X') || (grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X') || (grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X') || (grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X') || (grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X'))
		{
			gameFinish = true;
			std::cout << "Computer wins.";
		}
		else if ((grid[0][0] == 'O' && grid[0][1] == 'O' && grid[0][2] == 'O') || (grid[1][0] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O') || (grid[2][0] == 'O' && grid[2][1] == 'O' && grid[2][2] == 'O') || (grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O') || (grid[0][1] == 'O' && grid[1][1] == 'O' && grid[2][1] == 'O') || (grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O') || (grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O') || (grid[0][1] == 'O' && grid[1][1] == 'O' && grid[2][1] == 'O') || (grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O') || (grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O') || (grid[0][1] == 'O' && grid[1][1] == 'O' && grid[2][1] == 'O') || (grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O'))
		{
			gameFinish = true;
			std::cout << "User wins.";
		}
		else if (grid[0][0] != '_' && grid[0][1] != '_' && grid[0][2] != '_' && grid[1][0] != '_' && grid[1][1] != '_' && grid[1][2] != '_' && grid[2][0] != '_' && grid[2][1] != '_' && grid[2][2] != '_')
		{
			std::cout << "A draw." << std::endl;
			gameFinish = true;
		}

		validInput = false;
		row = 0;
		column = 0;

		if (!gameFinish)
		{
			while (!validInput)
			{
				while (inputChar1 != '1' && inputChar1 != '2' && inputChar1 != '3')
				{
					std::cout << "Row of input?" << std::endl;
					std::cin >> inputChar1;
				}
				switch (inputChar1)
				{
				case '1':
					row = 0;
					break;
				case '2':
					row = 1;
					break;
				case '3':
					row = 2;
					break;
				}
				while (inputChar2 != '1' && inputChar2 != '2' && inputChar2 != '3')
				{
					std::cout << "Column of input?" << std::endl;
					std::cin >> inputChar2;
				}
				switch (inputChar2)
				{
				case '1':
					column = 0;
					break;
				case '2':
					column = 1;
					break;
				case '3':
					column = 2;
					break;
				}
				if (grid[(int)row][(int)column] == '_')
				{
					validInput = true;
					grid[(int)row][(int)column] = 'O';
				}
				else
				{
					std::cout << "Invalid input." << std::endl;
					inputChar1 = '\0';
					inputChar2 = '\0';
				}
			}
		}

		validInput = false;
		row = 0;
		column = 0;
		inputChar1 = '\0';
		inputChar2 = '\0';
		
	}

	return 1;
}