#include <iostream>
#include <fstream>
#define FILE_PATH "binary.bin" 

void writeNumToBinaryFile(const int& numToWrite)
{
    std::ofstream outFile(FILE_PATH, std::ios::binary);
    if (!outFile.is_open())
    {
        std::cout << "Output file not open\n";
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&numToWrite), sizeof(numToWrite));
    outFile.close();
}

int getNumFromBinaryFile()
{
    std::ifstream inFile(FILE_PATH, std::ios::binary);
    if (!inFile.is_open())
    {
        std::cout << "Input file not open\n";
        return -1;
    }

    int num = 0;
    inFile.read(reinterpret_cast<char*>(&num), sizeof(num));
    
    inFile.close();
    return num;
}

void writeCharToBinaryFile(const char& symbolToWrite)
{
    std::ofstream outFile(FILE_PATH, std::ios::binary);
    if (!outFile.is_open())
    {
        std::cout << "Output file not open\n";
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&symbolToWrite), sizeof(symbolToWrite));
    outFile.close();
}

char getCharFromBinaryFile()
{
    std::ifstream inFile(FILE_PATH, std::ios::binary);
    if (!inFile.is_open())
    {
        std::cout << "Input file not open\n";
        return ' ';
    }

    char symbol = ' ';
    inFile.read(reinterpret_cast<char*>(&symbol), sizeof(symbol));

    inFile.close();
    return symbol;
}

int main()
{
    int num;
    std::cout << "Enter number:\n";
    std::cin >> num;
    writeNumToBinaryFile(num);
    std::cout << "The number you inputted is " << getNumFromBinaryFile() << '\n';

    char symbol;
    std::cout << "Enter symbol:\n";
    std::cin >> symbol;
    writeCharToBinaryFile(symbol);
    std::cout << "The symbol you inputted is " << getCharFromBinaryFile() << '\n';

    return 0;
}
