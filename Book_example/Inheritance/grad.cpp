#include "grad.hpp"
#include <algorithm>

Grad::Grad() : thesis(0)
{

}

Grad::Grad(std::istream& in)
{
    read(in);
}

bool Grad::valid() const
{
    if (Core::valid() && (thesis != 0.0))
        return true;
    return false;
}

double Grad::grade()
{
    return std::min(Core::grade(), thesis);
}

void Grad::regrade(double m, double f)
{
    Core::regrade(m, m);
    thesis = f;
}

std::istream& Grad::read(std::istream& in)
{
    readCommon(in);
    in >> thesis;
    readHw(in, homework);
    return in;
}