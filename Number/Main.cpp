#include <iostream>;
int main()
{
	int startingValue = 0;
	int endingValue = 100;
	bool correct = false;

	while (!correct)
	{
		char keypress = '\0';
		int middle = (startingValue + endingValue) / 2;
		std::cout << middle << std::endl;
		std::cout << "is this the answer?" << std::endl;
		std::cin >> keypress;
		if (keypress == 'y')
		{
			correct = true;
		}
		else if (keypress == 'n')
		{
			if (startingValue == middle || endingValue == middle)
			{
				std::cout << "the answer has benn changed" << std::endl;
				correct = true;
			}
			else
			{
				char keypress2 = '\0';
				std::cout << "is the answer larger?" << std::endl;
				std::cin >> keypress2;
				if (keypress2 == 'y')
				{
					startingValue = middle;
				}
				else if (keypress2 == 'n')
				{
					endingValue = middle;
				}
				else
				{
					continue;
				}
			}
		}
		else
		{
			continue;
		}

	}

	return 0;
}