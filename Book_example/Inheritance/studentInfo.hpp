#ifndef STUDENT_INFO_HPP
#define STUDENT_INFO_HPP

#include <iostream>
#include <string>

#include "core.hpp"
#include "grad.hpp"

class StudentInfo
{
    private:
        Core* cp;

    public:
        StudentInfo() : cp(0) { }
        StudentInfo(std::istream& in) : cp(0) { read(in); }
        StudentInfo(const StudentInfo&);
        ~StudentInfo() { delete cp; }
        StudentInfo& operator=(const StudentInfo&);

        std::istream& read(std::istream&);
        std::string getName() const;
        double grade();
        static bool compare(const StudentInfo&, const StudentInfo&);
};

#endif