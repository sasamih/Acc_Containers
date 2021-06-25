#include "student.hpp"

bool importStudent(std::vector<StudentInfo>& students, std::vector<std::string>& s)
{
    StudentInfo tempS;
    auto it = s.begin();
    std::stringstream ss;
    int points;

    int i = 0;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (i == 0)
        {
            tempS.name = *it;
        }
        else
        {
            int pt = std::stoi(*it);
            if (i == 1)
            {
                tempS.midterm = (double)pt;
            }
            else if (i == 2)
            {
                tempS.final = (double)pt;
            }
            else
            {
                tempS.homework.push_back(double(pt));
            }
        }
        i++;
    }

    students.push_back(tempS);

    return true;
}

bool loadGrades(std::fstream* fs, std::vector<StudentInfo>& students)
{
    std::string line;

    if (fs->is_open())
    {
        int i = 0;
        while (!fs->eof())
        {
            getline(*fs, line);
            std::vector<std::string> s = split(line);
            importStudent(students, s);

            i++;
        }

        return true;
    }
    else
    {
        return false;
    }
}

double getFinalGrade(StudentInfo& student)
{
    double homeworkSum = 0.0;
    double homeworkAverage = 0.0;
    double final = 0.0;

    for (auto it = student.homework.begin(); it != student.homework.end(); it++)
    {
        homeworkSum += *it;
    }

    // std::cout << "Sum: " << homeworkSum << std::endl;
    homeworkAverage = homeworkSum / student.homework.size();

    final = (0.2 * student.midterm) + (0.4 * student.final) + (0.4 * homeworkAverage);

    // std::cout << student.name << " " << final << std::endl; 
    return final;

}

bool passed(StudentInfo& student)
{
    if (getFinalGrade(student) > 50)
        return true;
    else
        return false;
}

std::vector<StudentInfo> getFailingStudents(std::vector<StudentInfo>& students)
{
    std::vector<StudentInfo> fail;

    for (auto it = students.begin(); it != students.end(); it++)
    {
        if (!passed(*it))
        {
            fail.push_back(*it);
        }
    }

    return fail;
}

std::vector<StudentInfo> extractFails(std::vector<StudentInfo>& students)
{
    std::vector<StudentInfo> fails;
    std::vector<StudentInfo> pass;

    for (auto it = students.begin(); it != students.end(); it++)
    {
        if (passed(*it))
        {
            pass.push_back(*it);
        }
        else
        {
            fails.push_back(*it);
        }
    }

    students = pass;
    return fails;
}

std::vector<StudentInfo> extractFailsKeepOriginal(std::vector<StudentInfo>& students)
{
    std::vector<StudentInfo> fails;

    int i = 0;
    for (auto it = students.begin(); it != students.end(); it++, i++)
    {
        if (passed(*it))
        {
            // pass.push_back(*it);
            students.insert(students.begin(),*it);
            it = students.erase(students.begin() + i);
        }
        else
        {
            fails.push_back(*it);
        }
    }
    return fails;
}

double calculateAverageHomework(std::vector<double>& homework)
{
    double homeworkSum = 0.0;
    double homeworkAverage = 0.0;

    for (auto it = homework.begin(); it != homework.end(); it++)
    {
        homeworkSum += *it;
    }
    homeworkAverage = homeworkSum / homework.size();
    
    return homeworkAverage;
}

double optimisticMedian(const StudentInfo& s)
{
    std::vector<double> nonzero;

    for (auto it = s.homework.begin(); it != s.homework.end(); it++)
    {
        if (*it > 0)
        {
            nonzero.push_back(*it);
        }
    }
    std::sort(nonzero.begin(), nonzero.end());

    return median(nonzero);
}

double medianAnalysis(const std::vector<StudentInfo>& students)
{
    std::vector<double>grades;

    std::transform(students.begin(), students.end(), std::back_inserter(grades), optimisticMedian);

    // for (auto it = grades.begin(); it != grades.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }

    std::sort(grades.begin(), grades.end());
    return median(grades);
}