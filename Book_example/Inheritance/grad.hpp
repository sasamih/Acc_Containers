#ifndef GRAD_HPP
#define GRAD_HPP

#include <iostream>
#include <string>
#include <vector>

#include "core.hpp"

class Grad : public Core
{
    private:
        double thesis;

    public:
        Grad();
        Grad(std::istream&);
        double grade();
        std::istream& read(std::istream&);

        Grad* clone() const { return new Grad(*this); }
};

#endif