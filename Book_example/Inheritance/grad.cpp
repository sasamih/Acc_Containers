#include "grad.hpp"
#include <algorithm>

Grad::Grad() : thesis(0)
{

}

Grad::Grad(std::istream& in)
{
    read(in);
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