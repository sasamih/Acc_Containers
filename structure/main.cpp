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

        std::vector<double> v = {25.2, 1.2, 67.5, 13.5, 10.2, 36.7};

        // std::cout << *(find_value(v.begin(), v.end(), 10.2)) << std::endl;

        // std::cout << *(median(v)) << std::endl;

        reverse_vector(v.begin(), v.end());

        for (auto it = v.begin(); it != v.end(); it++)
        {
            std::cout << *it << std::endl;
        }

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