#include "Plane.h"
#include <iostream>
#include <fstream>
#define FILE_PATH "Planes.db" 

Plane::Plane() : id_(0), flights_(0)
{
	plane_[0] = '\0';
	type_[0] = '\0';
}

Plane::Plane(const long long& id, const char plane[], const char type[], const long long& flights) : id_(id), flights_(flights)
{
	strcpy_s(plane_, plane);
	strcpy_s(type_, type);
}

void Plane::initializePlaneThroughInput()
{
	std::cout << "Enter ID:\n";
	std::cin >> id_;
	std::cout << "Enter plane name:\n";
	std::cin >> plane_;
	std::cout << "Enter plane type:\n";
	std::cin >> type_;
	std::cout << "Enter amount of flights plane has:\n";
	std::cin >> flights_;
}

void Plane::printInfo()
{
	std::cout << "Plane Id: " << id_
		<< "\nPlane name: " << plane_
		<< "\nPlane type: " << type_
		<< "\nAmount of flights: " << flights_ << '\n';
}

void Plane::writePlaneToFile(const char* path)
{
	std::ofstream outFile(path, std::ios::binary | std::ios::app);

	if (!outFile.is_open())
	{
		std::cout << "Output file not open. Plane was not written.\n";
		return;
	}

	outFile.write(reinterpret_cast<const char*>(this), sizeof(*this));
	outFile.close();
}

bool Plane::isEmpty()
{
	return id_ == 0 && flights_ == 0 && plane_[0] == '\0' && type_[0] == '\0';
}

Plane Plane::getPlaneByID(const long long& IdToSeek, const char* path)
{
	std::ifstream inFile(path, std::ios::binary);
	if (!inFile.is_open())
	{
		std::cout << "Input file not open. Could not look for plane.\n";
		return Plane();
	}

	Plane buff;

	inFile.seekg(0, inFile.beg);
	while (inFile.read(reinterpret_cast<char*>(&buff), sizeof(buff)))
	{
		if (buff.id_ == IdToSeek)
		{
			inFile.close();
			return buff;
		}
	}
	

	inFile.close();
	return {};
}
