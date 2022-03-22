#include "Plane.h"

Plane::Plane() 
{
	this->ID_ = 0;
	this->plane_[0] = '\0';
	this->type_[0] = '\0';
	this->flights_ = 0;
}

Plane::Plane(const long long& ID, const char plane[], const char type[], const long long& flights)
{
	this->ID_ = ID;
	strcpy_s(this->plane_, plane);
	strcpy_s(this->type_, type);
	this->flights_ = flights;
}

void Plane::initializePlaneThroughInput()
{
	std::cout << "Enter ID:\n";
	std::cin >> this->ID_;
	std::cout << "Enter plane name:\n";
	std::cin >> this->plane_;
	std::cout << "Enter plane type:\n";
	std::cin >> this->type_;
	std::cout << "Enter amount of flights plane has:\n";
	std::cin >> this->flights_;
}

void Plane::printInfo()
{
	std::cout << "Plane Id: " << this->ID_
		<< "\nPlane name: " << this->plane_
		<< "\nPlane type: " << this->type_
		<< "\nAmount of flights: " << this->flights_ << '\n';
}

void Plane::writePlaneToFile()
{
	std::ofstream outFile(FILE_PATH, std::ios::binary | std::ios::app);

	if (!outFile.is_open())
	{
		std::cout << "Output file not open. Plane was not written.\n";
		return;
	}

	outFile.write(reinterpret_cast<const char*>(&*this), sizeof(*this));
	outFile.close();
}

bool Plane::isEmpty()
{
	return ID_ == 0 && flights_ == 0 && plane_[0] == '\0' && type_[0] == '\0';
}

Plane Plane::getPlaneByID(const long long& IdToSeek)
{
	std::ifstream inFile(FILE_PATH, std::ios::binary);
	if (!inFile.is_open())
	{
		std::cout << "Input file not open. Could not look for plane.\n";
		return {};
	}

	Plane buff;

	inFile.seekg(0, inFile.beg);
	while (inFile.read(reinterpret_cast<char*>(&buff), sizeof(buff)));
	if (buff.ID_ == IdToSeek)
	{
		inFile.close();
		return buff;
	}

	inFile.close();
	return {};
}
