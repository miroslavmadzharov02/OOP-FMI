#include <iostream>
#include <fstream>

int main()
{
	std::ifstream inFile("./(1) print own code.cpp");

	if (!inFile.is_open())
	{
		std::cout << "File not open.\n";
		return -1;
	}

	char buffer[256];
	while (!inFile.eof())
	{
		inFile.getline(buffer, 256);
		std::cout << buffer << std::endl;
	}

	inFile.close();
	return 0;
}
