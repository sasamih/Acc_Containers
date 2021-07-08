#ifndef STUDENT_INFO_HPP
#define STUDENT_INFO_HPP

#include <iostream>
#include <string>

#include "core.hpp"
#include "grad.hpp"
#include "handle.hpp"

class StudentInfo
{
    private:
        Handle<Core> cp;

    public:
        StudentInfo() { }
        StudentInfo(std::istream& in) { read(in); }
        // StudentInfo(const StudentInfo&);
        // ~StudentInfo() { delete cp; }
        // StudentInfo& operator=(const StudentInfo&);

        std::istream& read(std::istream&);
        std::string getName() const;
        double grade();
        Handle<Core>& getHandler();
        static bool compare(const StudentInfo&, const StudentInfo&);
};

#endif