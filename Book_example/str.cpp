#include "str.hpp"

Str operator+(const Str& s1, const Str& s2)
{
    Str r = s1;
    r += s2;
    return r;
}

char& Str::operator[](size_type i)
{
    return data[i];
}

const char& Str::operator[](size_type i) const
{
    return data[i];
}

Str& Str::operator+=(const Str& s)
{
    // for (Str::size_type i = 0; i < s.size(); i++)
    // {
    //     data.push_back(s[i]);
    // }
    std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));

    return *this;
}

std::istream& operator>>(std::istream& in, Str& s)
{
    s.data.clear();
    char c;

    while(in.get(c) && isspace(c));

    if (in)
    {
        do s.data.push_back(c);
        while(in.get(c) && !isspace(c));

        if (in)
            in.unget();
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Str& s)
{
    for (Str::size_type i = 0; i != s.size(); i++)
    {
        out << s[i];
    }

    return out;
}

bool compare(const Str& s1, const Str& s2)
{
    if ((s1.size() < s2.size()) || (s1.size() > s2.size()))
    {
        return false;
    }
    else
    {
        for (Str::size_type i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                return false;
        }
        return true;
    }
}

bool Str::operator==(const Str& s)
{
    return compare(*this, s);
}


int main()
{
    Str s, t, p;
    Str r;

    std::cin >> s;
    std::cin >> t;
    std::cin >> p;

    // r = s + t + p + "!";
    bool comp = (s == t);
    std::cout << comp << std::endl;
    // std::cout << t;

    return 0;
}