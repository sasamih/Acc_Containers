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

double getFinalGrade(StudentInfo& student, double homeworkMethod(const std::vector<double>&))
{
    double homeworkPoints = 0.0;
    double final = 0.0;

    homeworkPoints = calculateHomeworkPoints(student.homework, homeworkMethod);

    final = (0.2 * student.midterm) + (0.4 * student.final) + (0.4 * homeworkPoints);

    // std::cout << student.name << " " << final << " " << homeworkPoints << std::endl; 
    return final;

}

bool passed(StudentInfo& student, double homeworkMethod(const std::vector<double>&))
{
    if (getFinalGrade(student, homeworkMethod) > 50)
        return true;
    else
        return false;
}

void rangeStatistics(std::vector<StudentInfo>& students)
{
    std::map<std::string, int> grades;
    grades.insert(std::pair<std::string, int>("A 90-100", 0));
    grades.insert(std::pair<std::string, int>("B 80-89", 0));
    grades.insert(std::pair<std::string, int>("C 70-79", 0));
    grades.insert(std::pair<std::string, int>("D 60-69", 0));
    grades.insert(std::pair<std::string, int>("F <60", 0));

    for (auto it = students.begin(); it != students.end(); it++)
    {
        double g = getFinalGrade(*it, average);
        
        if (g >= 90.0)
        {
            ++grades["A 90-100"];
        }
        else if (g >= 80.0 && g < 90.0)
        {
            ++grades["B 80-89"];
        }
        else if (g >= 70.0 && g < 80.0)
        {
            ++grades["C 70-79"];
        }
        else if (g >= 60.0 && g < 70.0)
        {
            ++grades["D 60-69"];
        }
        else
        {
            ++grades["F <60"];
        }
    }

    for (auto it = grades.begin(); it != grades.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }

    return;
}

double calculateHomeworkPoints(std::vector<double>& v, double calculateMethod(const std::vector<double>&))
{
    return calculateMethod(v);
}

std::vector<StudentInfo> getFailingStudentsAverage(std::vector<StudentInfo>& students)
{
    std::vector<StudentInfo> fail;

    for (auto it = students.begin(); it != students.end(); it++)
    {
        if (!passed(*it, average))
        {
            fail.push_back(*it);
        }
    }

    return fail;
}

std::vector<StudentInfo> getFailingStudentsMedian(std::vector<StudentInfo>& students)
{
    std::vector<StudentInfo> fail;

    for (auto it = students.begin(); it != students.end(); it++)
    {
        if (!passed(*it, median))
        {
            fail.push_back(*it);
        }
    }

    return fail;
}

std::vector<StudentInfo> extractFailsAverage(std::vector<StudentInfo>& students)
{
    std::vector<StudentInfo> fails;
    std::vector<StudentInfo> pass;

    for (auto it = students.begin(); it != students.end(); it++)
    {
        if (passed(*it, average))
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

std::vector<StudentInfo> extractFailsMedian(std::vector<StudentInfo>& students)
{
    std::vector<StudentInfo> fails;
    std::vector<StudentInfo> pass;

    for (auto it = students.begin(); it != students.end(); it++)
    {
        if (passed(*it, median))
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

std::vector<StudentInfo> extractFailsKeepOriginalAverage(std::vector<StudentInfo>& students)
{
    std::vector<StudentInfo> fails;

    int i = 0;
    for (auto it = students.begin(); it != students.end(); it++, i++)
    {
        if (passed(*it, average))
        {
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

std::vector<StudentInfo> extractFailsKeepOriginalMedian(std::vector<StudentInfo>& students)
{
    std::vector<StudentInfo> fails;

    int i = 0;
    for (auto it = students.begin(); it != students.end(); it++, i++)
    {
        if (passed(*it, median))
        {
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

    std::sort(grades.begin(), grades.end());
    return median(grades);
}