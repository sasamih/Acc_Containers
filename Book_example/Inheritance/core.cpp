#include "core.hpp"

Core::Core() : midterm(0), final(0)
{

}

Core::Core(std::istream& in)
{
    read(in);
}

std::string Core::getName() const
{
    return name;
}

std::istream& Core::readCommon(std::istream& in)
{
    in >> name >> midterm >> final;
    return in;
}

std::istream& Core::read(std::istream& in)
{
    readCommon(in);
    readHw(in, homework);
    return in;
}

std::istream& Core::readHw(std::istream& in, std::vector<double>& hw)
{
    if (in)
    {
        hw.clear();

        double x;
        while (in >> x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}

double median(std::vector<double>& v)
{
    typedef typename std::vector<double>::size_type sz;

    sz middle = v.size() / 2;
    std::sort(v.begin(), v.end());
    auto it = v.begin() + middle;

    return *it;
}

bool Core::valid() const
{
    if ((!homework.empty()) && (midterm != 0.0) && (final != 0.0))
        return true;
    return false;
}

double Core::grade()
{
    return grade(midterm, final, homework);
}

double Core::grade(double m, double f, std::vector<double>& hw)
{
    return grade(m, f, hw, median);
}

double Core::grade(double m, double f, std::vector<double>& hw, double homeworkMethod(std::vector<double>&))
{
    return (0.2 * midterm) + (0.4 * final) + (0.4 * homeworkMethod(hw));
}

void Core::regrade(double m, double f)
{
    midterm = m;
    final = f;
}