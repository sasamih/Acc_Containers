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

    for (auto it = student.begin(); it != student.end(); it++)
    {
        std::cout << " // " + *it; 
    }
    std::cout << std::endl;

    return student;
}

bool importStudent(std::vector<StudentInfo>& students, std::vector<std::string>& s)
{
    StudentInfo tempS;
    auto it = s.begin();
    std::stringstream ss;
    int points;

    for (auto it = s.begin(); it != s.end(); it++)
    {
        std::cout << " // " + *it; 
    }
    std::cout << std::endl;

    // tempS.name = *it;
    

    // it++;
    // ss << *it;
    // ss >> points;
    // tempS.final = (double)points;

    int i = 0;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (i == 0)
        {
            tempS.name = *it;
        }
        else
        {
            ss << *it;
            ss >> points;
            if (i == 1)
            {
                tempS.midterm = (double)points;
            }
            else if (i == 2)
            {
                tempS.final = (double)points;
            }
            else
            {
                tempS.homework.push_back(double(points));
            }
        }
        i++;
    }

    students.push_back(tempS);

    // std::cout << tempS.name << " // " << tempS.midterm << " // " << tempS.final; 
    // for (auto it = tempS.homework.begin(); it != tempS.homework.end(); it++)
    // {
    //     std::cout << " // " << *it;
    // }
    // std::cout << std::endl;

    return true;
}

bool loadGrades(std::fstream* fs, std::vector<StudentInfo>& students)
{
    std::string line;

    if (fs->is_open())
    {
        int i = 0;
        while (i < 10) //(!fs->eof())
        {
            getline(*fs, line);
            std::vector<std::string> s = split(line);
            importStudent(students, s);

            i++;
        }

        // auto it = students.begin();
        // std::cout << it->name << " " << it->midterm << " " << it->final;
        // for (auto it2 = it->homework.begin(); it2 != it->homework.end(); it2++)
        // {
        //     std::cout << " " << *it2;
        // }
        // std::cout << std::endl;

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
        std::cout << "Sum: " << std::setprecision(5) << *it << std::endl;
    }
    homeworkAverage = homeworkSum / student.homework.size();

    final = (0.2 * student.midterm) + (0.4 * student.final) + (0.4 * homeworkAverage);

    std::cout << student.name << " " << final << std::endl; 
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