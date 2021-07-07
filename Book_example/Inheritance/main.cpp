#include <iostream>
#include <iomanip>

#include "core.hpp"
#include "grad.hpp"
#include "studentInfo.hpp"

bool compareGrades(Core& c1, Core& c2)
{
    return (c1.grade() > c2.grade());
}

// int main()
// {
//     Core c;
//     c.read(std::cin);

//     Grad g;
//     g.read(std::cin);

//     std::cout << c.grade() << std::endl;
//     std::cout << g.grade() << std::endl;
//     std::cout << compareGrades(c, g) << std::endl;
// }

int main()
{
    std::vector<StudentInfo> students;
    StudentInfo record;
    std::string::size_type maxlen = 0;

    while(record.read(std::cin))
    {
        maxlen = std::max(maxlen, record.getName().size());
        students.push_back(record);
    }

    std::sort(students.begin(), students.end(), StudentInfo::compare);

    for (std::vector<StudentInfo>::size_type i = 0; i != students.size(); i++)
    {
        std::cout << students[i].getName() << " ";
        std::cout << std::setprecision(3) << students[i].grade() << std::endl;
    }

    return 0;
}