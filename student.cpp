#include "student.hpp"

static std::vector<std::string> split(std::string& s)
{
    typedef std::string::size_type string_size;
    string_size i = 0, j = 0;
    std::vector<std::string> student;

    while (i != s.size())
    {
        while ((i != s.size()) && isspace(s[i]))
        {
            i++;
        }
        j = i;

        while ((j != s.size()) && !isspace(s[j]))
        {
            j++;
        }

        if (i != j)
        {
            student.push_back(s.substr(i, j-i));
            i = j;
        }
    }

    return student;
}

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