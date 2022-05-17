#include <iostream>
#include <fstream>

void writeTextToBinaryFile(const char* text)
{
    std::ofstream outFile("binary.bin", std::ios::binary);
    if (!outFile.is_open())
    {
        std::cout << "Output file not open\n";
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&text), sizeof(text));
    outFile.close();
}

int countNumsInCharArray(const char* text)
{
    int step = -1, count = 0;
    while (text[step++] != '\0')
        if (text[step] >= '0' && text[step] <= '9')
            count++;
    return count;
}

void writePositionsOfNumsToBinaryFile(const int& textLength)
{
    std::ifstream inFile("binary.bin", std::ios::binary);
    if (!inFile.is_open())
    {
        std::cout << "Input file not open\n";
        return;
    }

    char* text = new char[textLength + 1];
    text[textLength] = '\0';
    inFile.read(reinterpret_cast<char*>(&text), sizeof(text));
    inFile.close();

    std::ofstream outFilePositions("positions.bin", std::ios::binary);
    if (!outFilePositions.is_open())
    {
        std::cout << "Output file not open\n";
        return;
    }

    for (int i = 0; text[i] != '\0'; i++)
        if (text[i] >= '0' && text[i] <= '9')
            outFilePositions.write(reinterpret_cast<const char*>(&text[i]), sizeof(text[i]));
        
    outFilePositions.close();
    delete[] text;
}

int lastPositionOfNumFromBinaryFile()
{
    std::ifstream inFilePositions("positions.bin", std::ios::binary);
    if (!inFilePositions.is_open())
    {
        std::cout << "Input file not open\n";
        return -1;
    }

    int lastPos = -1;
    while (!inFilePositions.eof())
        inFilePositions.read(reinterpret_cast<char*>(&lastPos), sizeof(lastPos));

    return lastPos;
}

int main()
{
    int textLength;
    std::cout << "Enter text length:\n";
    std::cin >> textLength;

    char* inputText = new char[textLength + 1];
    inputText[textLength] = '\0';
    for (int i = 0; i < textLength; i++)
        std::cin >> inputText[i];

    writeTextToBinaryFile(inputText);
    writePositionsOfNumsToBinaryFile(textLength);
    std::cout << lastPositionOfNumFromBinaryFile();

    delete[] inputText;
    return 0;
}
