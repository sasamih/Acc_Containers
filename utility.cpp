#include "utility.hpp"

std::vector<std::string> split(std::string& s)
{
    typedef std::string::size_type string_size;
    string_size i = 0, j = 0;
    std::vector<std::string> words;

    while (i != s.size())
    {
        while ((i != s.size()) && isspace(s[i]))
        {
            i++;
        }
        j = i;

        while ((j != s.size()) && !isspace(s[j]))
        {
            j++;
        }

        if (i != j)
        {
            words.push_back(s.substr(i, j-i));
            i = j;
        }
    }

    return words;
}

std::string::size_type width(const std::vector<std::string>& v)
{
    std::string::size_type maxlen = 0;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        maxlen = (maxlen < it->size())? it->size() : maxlen;
    }
    return maxlen;
}

std::vector<std::string> frame(const std::vector<std::string> v)
{

    std::vector<std::string> ret;
    std::string::size_type maxlen = width(v);
    std::string border(maxlen + 4, '*');

    ret.push_back(border);

    for (auto it = v.begin(); it != v.end(); it++)
    {
        ret.push_back("* " + *it + std::string(maxlen - it->size(), ' ') + " *");
    }

    ret.push_back(border);
    return ret;
}

void populateGrades(char* inFile, char* outFile)
{
    std::fstream in;
    std::fstream out;
    std::string line;
    std::vector<std::string> students;

    in.open(inFile, std::ios::in);
    out.open(outFile, std::ios::out);

    if (out.is_open() && in.is_open())
    {
        while(!in.eof())
        {
            getline(in, line);
            for (int i = 0; i < 12; i++)
            {
                int points = rand() % 101;
                line += " " + std::to_string(points);
            }
            students.push_back(line);
        }

        auto it = students.begin();
        for (; it != students.end(); it++)
        {
            out << *it << std::endl;
        }
    }
}

double median(const std::vector<double>& v)
{
    int middle = v.size() / 2;
    double homworkMedian = 0.0;

    auto it = v.begin();
    it += middle;
    
    return *it;
}