#pragma once

#ifndef DATABASE
#define DATABASE

#include "PlaneData.h"
namespace Database
{
	bool doesFileExist(const char* path);
	void createFile(const char* path);
	bool writePlaneToFile(const char* path, PlaneData planeToWrite);
	PlaneData getPlaneById(const char* path, const long long& IdToSeek);
	void printMenu();
};

#endif