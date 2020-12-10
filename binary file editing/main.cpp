#include <iostream>
#include <fstream>
#include <cstdlib>

struct Info
{
	char string[10] = "";
	int number = 0;
};

int main()
{
	std::fstream file;
	char input[10] = "";
	char holder[10] = "";
	bool quit = false;
	std::cout << "what file should be opened?" << std::endl;
	std::cin >> input;
	file.open(input, std::ios_base::in | std::ios_base::binary | std::ios_base::out);
	if (file.is_open() && file.good() && !quit)
	{
			std::cout << "File opened" << std::endl;
		while (file.is_open() && file.good() && !quit)
		{
			file.seekg(0, std::ios::beg);

			std::cout << "input or output mode?";
			std::cin >> input;

			if ((input[0] == 'I' || input[0] == 'i') && input[1] == 'n')
			{
				file.read(input, 10);
				std::cout << input << std::endl;
			}
			else if ((input[0] == 'O' || input[0] == 'o') && input[1] == 'u' && input[2] == 't')
			{
				std::cin >> input;
				file.write(input, 10);
			}
			else
			{
				std::cout << "invalid command" << std::endl;
			}
		}

	}
	else
	{
		std::cout << "file could not be opened" << std::endl;
	}

	file.close();
	std::cout << "file is closed";
	std::cin >> input;
	return 1;
}