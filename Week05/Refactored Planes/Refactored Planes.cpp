#include "Database.h"
#include "StringActions.h"
#include "PlaneData.h"
#include "MenuActions.h"
#include <iostream>
#include <fstream>
#define DATABASE_PATH "Planes.db"

int main()
{
    char inputAction[16];
	do
	{
		MenuActions::printMenu();
		std::cin >> inputAction;
		StringActions::toLower(inputAction);

		if (StringActions::areStringsEqual(inputAction, "create"))
			MenuActions::createInputAction(DATABASE_PATH);
		else if (StringActions::areStringsEqual(inputAction, "search"))
			MenuActions::searchInputAction(DATABASE_PATH);
		else if (StringActions::areStringsEqual(inputAction, "exit"))
			std::cout << "Program exited successfully!\n";
		else
			std::cout << "Invalid input.\n";
	} while (!StringActions::areStringsEqual(inputAction, "exit"));

    return 0;
}
