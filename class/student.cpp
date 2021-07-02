#include "student.hpp"

template <class T>
T average(const std::vector<T>& v)
{
    double sum = 0.0;

    for (auto it = v.begin(); it != v.end(); it++)
    {
        sum += *it;
    }

    return sum / v.size();
}

StudentInfo::StudentInfo(std::string n, double m, double f, std::vector<double> h): name(n), midterm(m), final(f), homework(h)
{
    try
    {
        homeworkPoints = calculateHomework(average);
        grade = gradeStudent();
    }
    catch(const char* msg)
    {
        std::cerr << msg << std::endl;
    }
    
}

Grade StudentInfo::gradeStudent()
{
    points = (0.2 * midterm) + (0.4 * final) + (0.4 * homeworkPoints);

    if (points > 91)
    { 
        grade = EXCELENT_R;
    }
    else if (points > 81)
    {
        grade = EXCELENT;
    }
    else if (points > 71)
    {
        grade = VERY_GODD;
    }
    else if (points > 61)
    {
        grade = GOOD;
    }
    else if (points > 50)
    {
        grade = SUFFICIENT;
    }
    else
    {
        grade = INSUFFICIENT;
    }

    return grade;
}

double StudentInfo::calculateHomework(double homeworkMethod(const std::vector<double>&))
{
    // if (homework.empty())
    //     throw "Homework not loaded";

    homeworkPoints = homeworkMethod(homework);

    return homeworkPoints;
}

bool StudentInfo::valid()
{
    if ((!homework.empty()) && (midterm != 0.0) && (final != 0.0))
        return true;
    return false;
}

std::string StudentInfo::getName()
{
    return name;
}

std::vector<double> StudentInfo::getHomework()
{
    return homework;
}

double StudentInfo::getHomeworkPoints()
{
    return homeworkPoints;
}

double StudentInfo::getPoints()
{
    return points;
}

Grade StudentInfo::getGrade()
{
    return grade;
}