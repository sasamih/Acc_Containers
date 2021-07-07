#include "studentInfo.hpp"

#include <algorithm>

StudentInfo::StudentInfo(const StudentInfo& s)
{
    if (s.cp)
        cp = s.cp->clone();
}

StudentInfo& StudentInfo::operator=(const StudentInfo& s)
{
    if (&s != this)
    {
        delete cp;
        if (s.cp)
        {
            cp = s.cp->clone();
        }
        else
        {
            cp = 0;
        }
    }
    return *this;
}

std::istream& StudentInfo::read(std::istream& in)
{
    delete cp;

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