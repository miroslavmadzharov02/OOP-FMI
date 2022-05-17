#include <iostream>
#include <fstream>
#define FILE_PATH "binary.bin"

void capitalizeLetters(char*& text)
{
    int count = -1;
    while (text[count++] != '\0')
        if (text[count] >= 'a' && text[count] <= 'z')
            text[count] += 'A' - 'a';
}

void writeTextToBinaryFile(const char* text)
{
    std::ofstream outFile(FILE_PATH, std::ios::binary);
    if (!outFile.is_open())
    {
        std::cout << "Output file not open\n";
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&text), sizeof(text));
    outFile.close();
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

    capitalizeLetters(inputText);
    writeTextToBinaryFile(inputText);

    delete[] inputText;
    return 0;
}
