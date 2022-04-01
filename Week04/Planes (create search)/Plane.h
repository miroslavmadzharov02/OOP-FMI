#pragma once

#ifndef PLANES
#define PLANES

class Plane
{
private:
	long long id_;
	char plane_[256];
	char type_[256];
	long long flights_;

public:
	Plane();
	Plane(const long long& id, const char plane[], const char type[], const long long& flights);
	void initializePlaneThroughInput();
	void printInfo();
	bool isEmpty();

	void writePlaneToFile(const char* path);
	Plane getPlaneByID(const long long& IdToSeek, const char* path);
};

#endif PLANES