#pragma once
#include <iostream>
#include <fstream>
#define FILE_PATH "Planes.db" 

class Plane
{
private:
	long long ID_;
	char plane_[256];
	char type_[256];
	long long flights_;

public:
	Plane();
	Plane(const long long& ID, const char plane[], const char type[], const long long& flights);
	void initializePlaneThroughInput();
	void printInfo();

	void writePlaneToFile();
	bool isEmpty();
	Plane getPlaneByID(const long long& IdToSeek);
};

