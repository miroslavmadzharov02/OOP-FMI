#include <iostream>
#include <fstream>

struct StudentRecord
{
    char name[32];
    unsigned int facultyNum;
    bool areThereFailedExams;
    unsigned short averageGrade;
};

void writeStudentRecordCsv(std::ofstream &outFile, const StudentRecord student)
{
    outFile << student.name << '\n';
    outFile << student.facultyNum << '\n';
    outFile << std::boolalpha << student.areThereFailedExams << '\n';
    outFile << student.averageGrade << '\n' << '\n';
}

void readStudentRecordCsv(std::ifstream &inFile, StudentRecord& student)
{
    inFile >> student.name;
    inFile >> student.facultyNum;
    inFile >> std::boolalpha >> student.areThereFailedExams;
    inFile >> student.averageGrade;
}

void writeStudentsRecordsCsv(std::ofstream &outFile, StudentRecord* students, const int& studentsAmount)
{
    for (int i = 0; i < studentsAmount; i++)
        writeStudentRecordCsv(outFile, students[i]);
}

void readStudentsRecordsCsv(std::ifstream& inFile, StudentRecord* students, const int& studentsAmount)
{
    for (int i = 0; i < studentsAmount; i++)
        readStudentRecordCsv(inFile, students[i]);
}

void writeStudentRecordBinary(std::ofstream& outFile, const StudentRecord student)
{
    outFile.write(reinterpret_cast<const char*>(&student), sizeof(student));
}

void readStudentRecordBinary(std::ifstream& inFile, StudentRecord& student)
{
    inFile.read(reinterpret_cast<char*>(&student), sizeof(student));
}

void writeStudentsRecordsBinary(std::ofstream& outFile, const StudentRecord* students, const int& studentsAmount)
{
    for (int i = 0; i < studentsAmount; i++)
        writeStudentRecordBinary(outFile, students[i]);
}

void readStudentsRecordsBinary(std::ifstream& inFile, StudentRecord*& students, const int& studentsAmount)
{
    for (int i = 0; i < studentsAmount; i++)
        readStudentRecordBinary(inFile, students[i]);
}

int main()
{
    char useCSV;
    std::cout << "Should storage file be easily readable? [y/n]\n";
    std::cin >> useCSV;

    StudentRecord* students;

    switch (useCSV)
    {
    case 'y':
    {
        std::ofstream outFile("students.csv");
        if (!outFile.is_open())
        {
            std::cout << "Output file is not open.\n";
            return -1;
        }

        std::ifstream inFile("students.csv");
        if (!inFile.is_open())
        {
            std::cout << "Input file is not open.\n";
            return -1;
        }

        int studentsAmount;
        std::cout << "How many students to read:\n";
        std::cin >> studentsAmount;
        students = new StudentRecord[studentsAmount];

        readStudentsRecordsCsv(inFile, students, studentsAmount);
        inFile.close();

        writeStudentsRecordsCsv(outFile, students, studentsAmount);
        outFile.close();

        delete[] students;
    }
        break;

    case 'n':
    {
        std::ofstream outFile("students.bin", std::ios::binary);
        if (!outFile.is_open())
        {
            std::cout << "Output file is not open.\n";
            return -1;
        }

        std::ifstream inFile("students.bin", std::ios::binary);
        if (!inFile.is_open())
        {
            std::cout << "Input file is not open.\n";
            return -1;
        }

        int studentsAmount;
        std::cout << "How many students to read:\n";
        std::cin >> studentsAmount;
        students = new StudentRecord[studentsAmount];

        readStudentsRecordsBinary(inFile, students, studentsAmount);
        inFile.close();

        writeStudentsRecordsBinary(outFile, students, studentsAmount);
        outFile.close();

        delete[] students;
    }
        break;

    default:
        std::cout << "Please enter a valid answer.\n";
        break;
    }

    return 0;
}
