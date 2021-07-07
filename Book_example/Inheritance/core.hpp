#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



class Core
{
    private:
        std::string name;

    protected:
        std::istream& readCommon(std::istream&);
        double midterm, final;
        std::vector<double> homework;

    public:
        Core();
        Core(std::istream&);
        virtual ~Core() { }
        std::string getName() const;
        virtual std::istream& read(std::istream&);
        std::istream& readHw(std::istream&, std::vector<double>&);
        virtual double grade();
        double grade(double, double, std::vector<double>&);
        double grade(double, double, std::vector<double>&, double homeworkMethod(std::vector<double>&));

        virtual Core* clone() const { return new Core(*this); }
        friend class StudentInfo;
};

template <class T>
T average(const std::vector<T>& v)
{
    double sum = 0.0;

    for (auto it = v.begin(); it != v.end(); it++)
    {
        sum += *it;
    }

    return sum / v.size();
}

#endif