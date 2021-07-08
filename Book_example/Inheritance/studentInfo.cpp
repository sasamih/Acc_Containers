#include "studentInfo.hpp"

#include <algorithm>

std::istream& StudentInfo::read(std::istream& in)
{
    char c;
    in >> c;

    if (c == 'U')
    {
        cp = new Core(in);
    }
    else
    {
        cp = new Grad(in);
    }

    return in;
}

std::string StudentInfo::getName() const
{
    return cp->getName();
}

double StudentInfo::grade()
{
    return cp->grade();
}

bool StudentInfo::compare(const StudentInfo& s1, const StudentInfo& s2)
{
    return s1.getName() > s2.getName();
}

Handle<Core>& StudentInfo::getHandler()
{
    return cp;
}