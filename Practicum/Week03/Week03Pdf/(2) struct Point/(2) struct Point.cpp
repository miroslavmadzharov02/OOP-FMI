#include <iostream>
#include <fstream>
#define FILE_PATH "binary.bin"

struct Point
{
    int x;
    int y;
};

void writePointToBinaryFile(const Point& point)
{
    std::ofstream outFile(FILE_PATH, std::ios::binary);
    if (!outFile.is_open())
    {
        std::cout << "Output file not open\n";
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&point), sizeof(point));
    outFile.close();
}

void readPointFromBinaryFile()
{
    std::ifstream inFile(FILE_PATH, std::ios::binary);
    if (!inFile.is_open())
    {
        std::cout << "Input file not open\n";
        return;
    }

    Point tempPoint;
    inFile.read(reinterpret_cast<char*>(&tempPoint), sizeof(tempPoint));
    inFile.close();

    std::cout << "X: " << tempPoint.x << "\nY: " << tempPoint.y;
}

int main()
{
    Point point(4,2);
    writePointToBinaryFile(point);
    readPointFromBinaryFile();

    return 0;
}
