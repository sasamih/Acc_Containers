#ifndef STR_HPP
#define STR_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <iterator>

#include "vec.hpp"
#include "vec.cpp"

class Str
{
    private:
        Vec<char> data;

    public:
        typedef Vec<char>::size_type size_type;
        typedef char* str_iterator;

        Str() {}
        Str(size_type s, char c) : data(s, c) {}
        Str(const char* cp)
        {
            std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
        }
        template<class In> Str(In b, In e)
        {
            std::copy(b, e, std::back_inserter(data));
        }

        template<typename T> void insert(T b, T e)
        {
            std::copy(b, e, std::back_inserter(data));
        }

        char& operator[](size_type);
        const char& operator[](size_type) const;
        const size_type size() const { return data.size(); }
        Str& operator+=(const Str&);
        bool operator==(const Str&);
        bool operator!=(const Str&);
        explicit operator bool();

        str_iterator begin()
        {
            return &data[0];
        }

        str_iterator end()
        {
            return &data[size()];
        }


        friend std::istream& operator>>(std::istream&, Str&);
        friend std::ostream& operator<<(std::ostream&, Str&);
        friend std::istream& getline(std::istream&, Str&);
};

#endif