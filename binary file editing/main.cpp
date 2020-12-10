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
		std::cout << "File size: " << filesize << std::endl;
		file.seekg(0, std::ios::beg);
		while (file.is_open() && file.good() && !quit)
		{
			std::cout << "Mode? (read, write, seek, add) \n";
			std::cin >> input;

			if ((input[0] == 'R' || input[0] == 'r') && input[1] == 'e' && input[2] == 'a' && input[3] == 'd')
			{
				file.read(holder, 20);
				std::cout << holder << std::endl;
			}
			else if ((input[0] == 'W' || input[0] == 'w') && input[1] == 'r' && input[2] == 'i' && input[3] == 't' && input[4] == 'e')
			{
				std::cin >> input;
				file.write(input, 20);
			}
			else if ((input[0] == 'S' || input[0] == 's') && input[1] == 'e' && input[2] == 'e' && input[3] == 'k')
			{
				std::cin >> input;
				int a = ((int)input[0] - 48) * 10;
				int b = ((int)input[1] - 48);

				if (a + b > filesize)
				{
					std::cout << "Cannot seek past the file. \n";
				}
				else
				{
					file.seekg((a + b), std::ios::beg);
					std::cout << "Seeking to position " << a + b << std::endl;
				}
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
