#include <iostream>

struct Gradebook
{
    char name[32];
    char facultyNum[16];
    int gradesCount = 0;
    double* grades;
};

void initializeStudent(Gradebook& gradebook)
{
    std::cout << "Enter student's name:\n";
    std::cin >> gradebook.name;

    std::cout << "Enter " << gradebook.name << "'s faculty number:\n";
    std::cin >> gradebook.facultyNum;
}

void printStudent(const Gradebook& gradebook)
{
    std::cout << gradebook.name << '\n' << gradebook.facultyNum << '\n';
    for (int i = 0; i < gradebook.gradesCount; i++)
        std::cout << gradebook.grades[i] << " ";
    std::cout << '\n';
}

void addGrades(Gradebook& gradebook)
{
    std::cout << "How many grades does " << gradebook.name << " have?\n";
    std::cin >> gradebook.gradesCount;

    gradebook.grades = new double[gradebook.gradesCount];
    std::cout << "Enter " << gradebook.name << "'s grades:\n";
    for (int i = 0; i < gradebook.gradesCount; i++)
        std::cin >> gradebook.grades[i];
}

void sortGradesDescending(Gradebook& gradebook)
{
    for (int i = 1; i < gradebook.gradesCount; i++)
    {
        double temp = gradebook.grades[i];
        int count = i - 1;;

        while (temp > gradebook.grades[count] && count >= 0)
        {
            gradebook.grades[count + 1] = gradebook.grades[count];
            --count;
        }
        gradebook.grades[count + 1] = temp;
    }
}

double getAverageGrades(const Gradebook& gradebook)
{
    if (gradebook.gradesCount > 0)
    {
        double sum = 0;
        for (int i = 0; i < gradebook.gradesCount; i++)
            if (gradebook.grades[i] >= 3)
                sum += gradebook.grades[i];
        return sum / gradebook.gradesCount;
    }
    return -1;
}

bool canStudentPass(const Gradebook& gradebook)
{
    if (gradebook.gradesCount < 4)
        return false;

    int failedExamsCount = 0;
    for (int i = 0; i < gradebook.gradesCount; i++)
        if (gradebook.grades[i] < 3)
            failedExamsCount++;

    if (failedExamsCount < 4)
        return true;
    else if (failedExamsCount > 4)
        return false;
    else
    {
        if (getAverageGrades(gradebook) >= 4)
            return true;
        return false;
    }
}

bool canStudentGetStipend(const Gradebook& gradebook)
{
    for (int i = 0; i < gradebook.gradesCount; i++)
        if (gradebook.grades[i] < 3)
            return false;
    if (getAverageGrades(gradebook) < 5)
        return false;
    return true;
}

int main()
{
    Gradebook gradebook;
    initializeStudent(gradebook);
    addGrades(gradebook);

    sortGradesDescending(gradebook);
    printStudent(gradebook);
    std::cout << gradebook.name << "'s average is " << getAverageGrades(gradebook) << '\n';
    std::cout << gradebook.name << " can pass to next course " << std::boolalpha << canStudentPass(gradebook) << '\n';
    std::cout << gradebook.name << " will be able to get a stipend " << std::boolalpha << canStudentGetStipend(gradebook);

    delete[] gradebook.grades;
    return 0;
}
