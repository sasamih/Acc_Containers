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

std::ostream& operator<<(std::ostream& out, Str& s)
{
    std::ostream_iterator<char> oit (out);

    for (Str::size_type i = 0; i != s.size(); i++)
    {
        *oit++ = s[i];
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

bool Str::operator!=(const Str& s)
{
    return !compare(*this, s);
}

Str::operator bool()
{
    if (size() == 0)
        return false;
    return true;
}

std::istream& getline(std::istream& in, Str& s)
{
    char c;
    s.data.clear();

    while (in.get(c) && isspace(c));

    if (in)
    {
        do s.data.push_back(c);
        while (in.get(c) && (c != '\n'));
    }

    return in;
}

int main()
{
    Str s, t;

    getline(std::cin, s);
    std::cin >> t;

    s.insert(t.begin(), t.end());

    std::cout << "Linija:" << s << std::endl;

    return 0;
}