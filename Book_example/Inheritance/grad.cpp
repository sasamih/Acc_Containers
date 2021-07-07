#include "grad.hpp"
#include <algorithm>

Grad::Grad() : thesis(0)
{
    std::cerr << "Grad()" << std::endl;
}

Grad::Grad(std::istream& in)
{
    read(in);
    std::cerr << "Grad(istream&)" << std::endl;
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

std::istream& Grad::read(std::istream& in)
{
    readCommon(in);
    in >> thesis;
    readHw(in, homework);
    return in;
}