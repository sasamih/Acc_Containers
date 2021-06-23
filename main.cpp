#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "student.hpp"

static void populateGrades()
{
    std::fstream in;
    std::fstream out;
    std::string line;
    std::vector<std::string> students;

    in.open("students.txt", std::ios::in);
    out.open("grades.txt", std::ios::out);

    if (out.is_open() && in.is_open())
    {
        while(!in.eof())
        {
            getline(in, line);
            for (int i = 0; i < 12; i++)
            {
                int points = rand() % 101;
                line += " " + std::to_string(points);
            }
            students.push_back(line);
        }

        auto it = students.begin();
        for (; it != students.end(); it++)
        {
            out << *it << std::endl;
        }
    }
}

int main()
{
    std::fstream in;

    in.open("grades.txt", std::ios::in);

    std::vector<StudentInfo> students;

    loadGrades(&in, students);

    in.close();

    std::vector<StudentInfo> fail = getFailingStudents(students);

    for (auto it = fail.begin(); it != fail.end(); it++)
    {
        std::cout << it->name << std::endl;
    }

    std::cout << "Total: " << fail.size() << std::endl;

    return 0;
}