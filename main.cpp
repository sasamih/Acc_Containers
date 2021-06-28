#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "student.hpp"
#include "utility.hpp"

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        std::fstream in;

        in.open(argv[1], std::ios::in);

        std::vector<StudentInfo> students;

        loadGrades(&in, students);

        in.close();

        rangeStatistics(students);
        // std::vector<StudentInfo> fail = extractFailsKeepOriginalAverage(students);

        // std::cout << "Total passed: " << students.size() << std::endl;
        // std::cout << "Average method - Total failed: " << fail.size() << std::endl;

        // fail = extractFailsKeepOriginalMedian(students);
        // std::cout << "Median method - Total failed: " << fail.size() << std::endl;
    }
    else
    {
        std::vector<std::string> v;
        
        std::string in;
        getline(std::cin, in);
        v = split(in);

        std::vector<std::string> r = frame(v);

        for (auto it = r.begin(); it != r.end(); it++)
        {
            std::cout << *it << std::endl;
        }
    }
    return 0;
}