#include <iostream>
#include <fstream>
#include <cstdlib>


int main()
{
	std::fstream file;
	char input[20] = "";
	char holder[20] = "";
	bool quit = false;
	int filesize = 0;
	std::cout << "What file should be opened?" << std::endl;
	std::cin >> input;
	file.open(input, std::ios_base::in | std::ios_base::binary | std::ios_base::out);
	if (file.is_open() && file.good() && !quit)
	{
		std::cout << "File opened." << std::endl;
		file.seekg(0, std::ios::end);
		filesize = (int)file.tellg();
		std::cout << "Contains " << (filesize / 20) << " entries." << std::endl;
		file.seekg(0, std::ios::beg);
		while (file.is_open() && !file.bad() && !quit)
		{
			std::cout << "Position: Entry " << (((int)file.tellg())/20) << std::endl;
			std::cout << "Action? (read, write, seek, add) \n";
			std::cin >> input;

			if ((input[0] == 'R' || input[0] == 'r') && input[1] == 'e' && input[2] == 'a' && input[3] == 'd')
			{
				input[0] = '\0'; input[1] = '\0'; input[2] = '\0'; input[3] = '\0'; //disallows 'read' from being printed after the output data

				file.read(holder, 20);
				if (file.eof())
				{
					std::cout << "End of file reached." << std::endl;
				}
				else
				{
					std::cout << "Entry " << (((int)file.tellg()) / 20) - 1 << ": " << holder << std::endl;
				}
			}
			else if ((input[0] == 'W' || input[0] == 'w') && input[1] == 'r' && input[2] == 'i' && input[3] == 't' && input[4] == 'e')
			{
				if (((int)file.tellg()) + 19 > filesize)
				{
					std::cout << "End of file reached." << std::endl;
				}
				else
				{
					std::cin >> input;
					file.write(input, 20);
				}
			}
			else if ((input[0] == 'S' || input[0] == 's') && input[1] == 'e' && input[2] == 'e' && input[3] == 'k')
			{
				std::cin >> input;
				int a = ((int)input[0] - 48) * 10;
				int b = ((int)input[1] - 48);
				int c = a + b;
				int d = c * 20;

				if (d > filesize)
				{
					std::cout << "Cannot seek past the file. \n";
				}
				else
				{
					file.seekg(d, std::ios::beg);
					std::cout << "Seeking to entry " << c << std::endl;
				}
			}
			else if ((input[0] == 'A' || input[0] == 'a') && input[1] == 'd' && input[2] == 'd')
			{
				file.seekg(0, std::ios::end);
				std::cin >> input;
				file.write(input, 20);
				file.seekg(0, std::ios::end);
				filesize = (int)file.tellg();
				file.seekg(-20, std::ios::end);
			}
			else if ((input[0] == 'Q' || input[0] == 'q') && input[1] == 'u' && input[2] == 'i' && input[3] == 't')
			{
				quit = true;
			}
			else
			{
				std::cout << "Invalid command." << std::endl;
			}


		}
	}
	else
	{
		std::cout << "File could not be opened." << std::endl;
		std::cin >> input;
		return 0;
	}

	file.close();
	std::cout << "File has been closed.";
	std::cin >> input;
	return 1;
}
