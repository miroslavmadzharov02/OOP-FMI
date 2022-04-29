#include "Database.h"
#include <fstream>
#include <iostream>

bool Database::doesFileExist(const char* path)
{
	std::ifstream inFile(path);
	bool result = inFile.good();
	inFile.close();

	return result;
}

void Database::createFile(const char* path)
{
	std::ofstream outFile(path);
	outFile.close();
}

bool Database::writePlaneToFile(const char* path, PlaneData planeToWrite)
{
	std::ofstream outFile(path, std::ios::binary | std::ios::app);

	if (!outFile.is_open())
	{
		std::cout << "Output file not open. Plane was not written.\n";
		return false;
	}
	else 
	{
		outFile.write(reinterpret_cast<const char*>(&planeToWrite), sizeof(planeToWrite));
		return outFile.good();
	}
}

PlaneData Database::getPlaneById(const char* path, const long long& IdToSeek)
{
	std::ifstream inFile(path, std::ios::binary);
	if (!inFile.is_open())
	{
		std::cout << "Input file not open. Could not look for plane.\n";
		return PlaneData();
	}

	PlaneData buff;

	inFile.seekg(0, inFile.beg);
	while (inFile.read(reinterpret_cast<char*>(&buff), sizeof(buff)))
	{
		if (buff.getId() == IdToSeek)
		{
			inFile.close();
			return buff;
		}
	}


	inFile.close();
	return PlaneData();
}