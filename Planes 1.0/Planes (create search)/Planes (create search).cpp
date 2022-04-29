#include "Plane.h"
#include <iostream>
#include <fstream>
#define FILE_PATH "Planes.db" 

bool doesFileExist(const char* path)
{
    std::ifstream inFile(path);
    bool result = inFile.good();
    inFile.close();

    return result;
}

void createFile(const char* path)
{
    std::ofstream outFile(path);
    outFile.close();
}

void toLower(char* text)
{
    do
    {
        if (*text >= 'A' && *text <= 'Z')
            *text += 'a' - 'A';
    } while (*text++ != '\0');
}

void printMenu()
{
    std::cout << "Please choose an action by typing its name:\n"
        << "\"Create\" - Initialize a new plane by entering its ID, name, type and amount of flights.\n"
        << "\"Search\" - Type an ID to print info about the plane it correlates to.\n"
        << "\"Exit\" - Exit the program.\n";
}

int main()
{
    if (!doesFileExist(FILE_PATH))
        createFile(FILE_PATH);

    char inputAction[16];
    do
    {
        printMenu();
        std::cin >> inputAction;
        toLower(inputAction);

        if (!strcmp(inputAction, "create"))
        {
            Plane inputPlane;
            inputPlane.initializePlaneThroughInput();
            inputPlane.writePlaneToFile(FILE_PATH);
            std::cout << "Record saved.\n";
        }
        else if (!strcmp(inputAction, "search"))
        {
            long long idToSeek;
            std::cout << "Enter ID to look for:\n";
            std::cin >> idToSeek;

            Plane foundPlane = foundPlane.getPlaneByID(idToSeek, FILE_PATH);
            if (foundPlane.isEmpty())
                std::cout << "Record not found.\n";
            else
                foundPlane.printInfo();
        }
        else if (!strcmp(inputAction, "exit"))
        {
            std::cout << "Program exited successfully.\n";
        }
        else
        {
            std::cout << "Invalid input.\n";
        }
        std::cout << '\n';
    } while (strcmp(inputAction, "exit"));

    return 0;
}
