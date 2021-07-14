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

double median(const std::vector<double>& v)
{
    typedef typename std::vector<double>::size_type sz;

    std::vector<double> t;
    std::copy(v.begin(), v.end(), std::back_inserter(t));

    sz middle = t.size() / 2;
    std::sort(t.begin(), t.end());
    auto it = t.begin() + middle;

    return *it;
}

bool Core::valid() const
{
    if ((!homework.empty()) && (midterm != 0.0) && (final != 0.0))
        return true;
    return false;
}

const double Core::grade() const
{
    return grade(midterm, final, homework);
}

const double Core::grade(const double m, const double f, const std::vector<double>& hw) const
{
    return grade(m, f, hw, median);
}

const double Core::grade(const double m, const double f, const std::vector<double>& hw,
                        double homeworkMethod(const std::vector<double>&)) const
{
    return (0.2 * midterm) + (0.4 * final) + (0.4 * homeworkMethod(hw));
}

void Core::regrade(double m, double f)
{
    midterm = m;
    final = f;
}