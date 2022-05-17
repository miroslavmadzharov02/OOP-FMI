#include <iostream>
#include <fstream>

void copyFile(const char* fileToCopyName, const char* newFileName)
{
    std::ifstream inFile(fileToCopyName);
    std::ofstream outFile(newFileName);

    if (!inFile.is_open())
    {
        std::cout << "File to be copied is not opened.\n";
        return;
    }

    if (!outFile.is_open())
    {
        std::cout << "The new file is not opened.\n";
        return;
    }

    char buff[256];
    while (!inFile.eof())
    {
        inFile.getline(buff, 256);
        outFile << buff;
    }

    inFile.close();
    outFile.close();
}

int main()
{
    char fileToCopyName[64], newFileName[64];
    std::cout << "What file should be copied?\n";
    std::cin >> fileToCopyName;
    std::cout << "What should the new file be named?\n";
    std::cin >> newFileName;
    
    copyFile(fileToCopyName, newFileName);

    return 0;
}

