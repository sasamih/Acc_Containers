#include <iostream>
#include <vector>
#include <fstream>

#include "student.hpp"

static std::vector<std::string> split(std::string& s)
{
    typedef std::string::size_type string_size;
    string_size i = 0, j = 0;
    std::vector<std::string> words;

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
            words.push_back(s.substr(i, j-i));
            i = j;
        }
    }

    return words;
}

std::vector<double> getPoints(std::vector<std::string>& s)
{

    std::vector<double> points;

    for (auto it = s.begin() + 1; it != s.end(); it++)
    {
        points.push_back(std::stoi(*it));
    }

    return points;
}

static bool loadGrades(std::fstream* fs, std::vector<StudentInfo>& students)
{
    std::string line;
    int non_valid = 0;

    if (fs->is_open())
    {
        while (!fs->eof())
        {
            getline(*fs, line);
            std::vector<std::string> s = split(line);
            std::vector<double> points = getPoints(s);
            std::vector<double> hw;
            std::copy(points.begin() + 2, points.end(), back_inserter(hw));
            StudentInfo student(s[0], points[0], points[1], hw);
            if (student.valid())
                students.push_back(student);
            else
                non_valid++;
        }
        // std::cout << "Non valid: " << non_valid << std::endl;
       

        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        std::fstream in;
        std::vector<StudentInfo> students;

        in.open(argv[1], std::ios::in);
        loadGrades(&in, students);
        in.close();

        int failed = 0;
        int passed = 0;
        for (auto it = students.begin(); it != students.end(); it++)
        {
            if (it->getGrade() == INSUFFICIENT)
            {
                failed++;
            }
            else
            {
                passed++;
            }
        }

        // std::cout << "Total failed: " << failed << std::endl;
        // std::cout << "Total passed: " << passed << std::endl;

        getStatistics(students, std::cout);
    }

    return 0;
}