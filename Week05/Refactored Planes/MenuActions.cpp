#include "MenuActions.h"
#include "PlaneData.h"
#include "Database.h"
#include <iostream>

void MenuActions::createInputAction(const char* path)
{
	if (!Database::doesFileExist(path))
		Database::createFile(path);

	PlaneData inputPlane;
	inputPlane.initializePlaneThroughInput();

	if (Database::writePlaneToFile(path, inputPlane))
		std::cout << "Record saved.\n";
	else
		std::cout << "Record was not saved. Please try again\n";
}

void MenuActions::searchInputAction(const char* path)
{
	if (!Database::doesFileExist(path))
		Database::createFile(path);

	long long idToSeek;
	std::cout << "Enter ID to look for:\n";
	std::cin >> idToSeek;

	PlaneData foundPlane = Database::getPlaneById(path, idToSeek);
	if (foundPlane.isEmpty())
		std::cout << "Record not found.\n";
	else
		foundPlane.printInfo();
}

void MenuActions::printMenu()
{
	std::cout << "Please choose an action by typing its name:\n"
		<< "\"Create\" - Initialize a new plane by entering its ID, name, type and amount of flights.\n"
		<< "\"Search\" - Type an ID to print info about the plane it correlates to.\n"
		<< "\"Exit\" - Exit the program.\n";
}