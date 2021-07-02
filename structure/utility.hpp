#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

std::vector<std::string> split(std::string& s);
std::vector<std::string> frame(const std::vector<std::string> v);

// template <class T> T median(const std::vector<T>& v);
template <class T>
decltype(auto)
median(std::vector<T>& v)
{
    typedef typename std::vector<T>::size_type sz;

    sz middle = v.size() / 2;

    sort(v.begin(), v.end());

    auto it = v.begin() + middle;
    
    return it;
}

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

template <typename Iterator, class T>
decltype(auto)
find_value (Iterator begin, Iterator end, T value)
{
    if (begin == end)
        return end;
    
    while (begin != end)
    {
        if (*begin == value)
            return begin;
        else
            ++begin;
    }

    return end;
}

template <class Bi>
void swap(Bi& begin, Bi& end)
{
    auto temp2 = end;
    end = begin;
    begin = temp2;

    return;
}

template <class Bi>
void reverse_vector(Bi begin, Bi end)
{
    while (begin != end)
    {
        --end;
        if (begin != end)
        {
            swap(*begin++, *end);
            // auto temp2 = *end;
            // *end = *begin;
            // *begin = temp2;
            // begin++;
        }
    }
}

void populateGrades(char* inFile, char* outFile);

#endif