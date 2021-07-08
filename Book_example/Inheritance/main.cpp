#include <iostream>
#include <iomanip>

#include "core.hpp"
#include "grad.hpp"
#include "studentInfo.hpp"
#include "handle.hpp"

bool compareGrades(Core& c1, Core& c2)
{
    return (c1.grade() > c2.grade());
}

int main()
{
    // std::vector<StudentInfo> students;
    // StudentInfo record;
    // std::string::size_type maxlen = 0;

    // while(record.read(std::cin))
    // {
    //     maxlen = std::max(maxlen, record.getName().size());
    //     students.push_back(record);
    // }

    // std::sort(students.begin(), students.end(), StudentInfo::compare);

    // for (std::vector<StudentInfo>::size_type i = 0; i != students.size(); i++)
    // {
    //     std::cout << students[i].getName() << " ";
    //     std::cout << std::setprecision(3) << students[i].grade() << std::endl;
    // }

    // StudentInfo s = students[1];
    // s.getHandler()->regrade(10, 10);

    // std::cout << students[1].getName() << ":: ";
    // std::cout << std::setprecision(3) << students[1].grade() << std::endl;

    StudentInfo s1;
    s1.read(std::cin);
    StudentInfo s2 = s1;
    s2.read(std::cin);

    std::cout << s1.getName() << " ";
    std::cout << std::setprecision(3) << s1.grade() << std::endl;



    return 0;
}