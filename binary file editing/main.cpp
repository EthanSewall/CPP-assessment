#include <iostream>
#include <fstream>
#include <cstdlib>


struct Info
{
	char name[10];
	int number;
};


int main()
{
	Info info;
	std::fstream file;
	char input[10] = "";
	char heldname[10] = "";
	int heldnumber;
	std::cout << "what file should be opened?" << std::endl;
	std::cin >> input;
	file.open(input, std::ios_base::in | std::ios_base::binary | std::ios_base::out);
	if (file.is_open() && file.good())
	{
		file.seekg(0, std::ios::beg);
		std::cout << "where should the data be sent?" << std::endl;
		char location[10] = "";
		std::cin >> input;
		if (location == "Console" || location == "console")
		{
			file.read(heldname, 8);
			std::cout << heldname << std::endl;
		}
	}
	else
	{
		std::cout << "file could not be opened" << std::endl;
	}



	file.close();
	return 1;
}