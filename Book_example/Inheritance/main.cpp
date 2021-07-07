#include <iostream>

#include "core.hpp"
#include "grad.hpp"

bool compareGrades(Core& c1, Core& c2)
{
    return (c1.grade() > c2.grade());
}

int main()
{
    Core c;
    c.read(std::cin);

    Grad g;
    g.read(std::cin);

    std::cout << c.grade() << std::endl;
    std::cout << g.grade() << std::endl;
    std::cout << compareGrades(c, g) << std::endl;
}