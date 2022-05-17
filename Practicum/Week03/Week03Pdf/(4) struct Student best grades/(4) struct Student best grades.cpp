#include <iostream>
#include <fstream>
#define FILE_PATH "binary.bin"

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
    std::ofstream outFile(FILE_PATH, std::ios::binary);
    if (!outFile.is_open())
    {
        std::cout << "Output file not open\n";
        return;
    }

    for (int i = 0; i < studentsAmount; i++)
        outFile.write(reinterpret_cast<const char*>(&students[i]), sizeof(students[i]));

    outFile.close();
}

void bubbleSortStudentsDescending(Student*& students, const int& studentsAmount)
{
    Student temp;
    for (int i = 0; i < studentsAmount; i++)
        for (int j = 0; j < studentsAmount - i; j++)
        {
            if (students[j].averageGradeFinals < students[j + 1].averageGradeFinals)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
}

Student* getStudentsSortedByGradesAvg(const int& studentsAmount)
{
    std::ifstream inFile(FILE_PATH, std::ios::binary);
    if (!inFile.is_open())
        std::cout << "Input file not open\n";

    Student* tempStudents = new Student[studentsAmount];
    for (int i = 0; i < studentsAmount; i++)
       inFile.read(reinterpret_cast<char*>(&tempStudents[i]), sizeof(tempStudents[i]));

    bubbleSortStudentsDescending(tempStudents, studentsAmount);
    return tempStudents;
}

void printSortedFacultyNums(const Student* students, const int& studentsAmount)
{
    for (int i = 0; i < studentsAmount; i++)
        std::cout << students[i].facultyNumber << '\n';
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
    Student* sortedStudents = getStudentsSortedByGradesAvg(studentsAmount);
    printSortedFacultyNums(sortedStudents, studentsAmount);

    delete[] students;
    delete[] sortedStudents;
    return 0;
}
