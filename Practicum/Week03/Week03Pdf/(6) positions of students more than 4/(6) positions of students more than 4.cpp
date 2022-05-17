#include <iostream>
#include <fstream>

struct Student
{
    int facultyNumber;
    int passedExams;
    int failedExams;
    double averageGradeFinals;
};

void initializeStudent(Student& student)
{
    std::cout << "Enter student's faculty number:\n";
    std::cin >> student.facultyNumber;
    std::cout << "How many exams has student passed:\n";
    std::cin >> student.passedExams;
    std::cout << "How many exams has student failed:\n";
    std::cin >> student.failedExams;
    std::cout << "What's the student's average score from these exams:\n";
    std::cin >> student.averageGradeFinals;
}

void writeStudentsToBinaryFile(const Student* students, const int& studentsAmount)
{
    std::ofstream outFile("binary.bin", std::ios::binary);
    if (!outFile.is_open())
    {
        std::cout << "Output file not open\n";
        return;
    }

    for (int i = 0; i < studentsAmount; i++)
        outFile.write(reinterpret_cast<const char*>(&students[i]), sizeof(students[i]));

    outFile.close();
}

void writePositionsStudentsGradedHigherThanFour(const int& studentsAmount)
{
    std::ifstream inFile("binary.bin", std::ios::binary);
    if (!inFile.is_open())
    {
        std::cout << "Input file not open\n";
        return;
    }

    Student* tempStudents = new Student[studentsAmount];
    for (int i = 0; i < studentsAmount; i++)
        inFile.read(reinterpret_cast<char*>(&tempStudents[i]), sizeof(tempStudents[i]));

    inFile.close();

    std::ofstream outFilePositions("positions.bin", std::ios::binary);
    if (!outFilePositions.is_open())
    {
        std::cout << "Output file not open\n";
        return;
    }

    for (int i = 0; i < studentsAmount; i++)
        if (tempStudents[i].averageGradeFinals >= 4)
            outFilePositions.write(reinterpret_cast<const char*>(&i), sizeof(i));

    outFilePositions.close();
}

int main()
{
    int studentsAmount;
    std::cout << "Enter amount of students to input:\n";
    std::cin >> studentsAmount;

    Student* students = new Student[studentsAmount];
    for (int i = 0; i < studentsAmount; i++)
    {
        std::cout << "Input info for student " << i + 1 << '\n';
        initializeStudent(students[i]);
    }

    writeStudentsToBinaryFile(students, studentsAmount);
    writePositionsStudentsGradedHigherThanFour(studentsAmount);

    std::ifstream inFilePositions("positions.bin", std::ios::binary);
    if (!inFilePositions.is_open())
    {
        std::cout << "Input file not open\n";
        return -1;
    }

    int buff = 0;
    while (inFilePositions)
    {
        inFilePositions.read(reinterpret_cast<char*>(&buff), sizeof(buff));
        std::cout << buff << " ";
    }

    inFilePositions.close();
    delete[] students;
    return 0;
}
