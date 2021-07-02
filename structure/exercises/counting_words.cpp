#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "../utility.hpp"

static void countingWords()
{
    std::string s;
    std::map<std::string, int> counters;

    while (std::cin >> s)
        ++counters[s];

    std::vector<std::pair<int, std::string> > items;

    for (auto it = counters.begin(); it != counters.end(); it++)
    {
        std::pair<int, std::string> temp(it->second, it->first);
        items.push_back(temp);
    }

    std::sort(items.begin(), items.end());

    for (auto it = items.begin(); it != items.end(); ++it)
    {
        std::cout << it->second << "\t" << it->first << std::endl;
    }
}

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

std::map<std::string, std::vector<int> > xref(std::istream& in, std::vector<std::string> find_words(std::string&))
{
    std::string line;
    int line_number = 0;
    std::map<std::string, std::vector<int> > ret;

    while (getline(in, line))
    {
        ++line_number;
        std::vector<std::string> words = find_words(line);
        sort(words.begin(), words.end());

        auto it1 = words.begin();
        for (auto it = words.begin() + 1; it != words.end(); ++it)
        {
            if (*it1 == *it)
            {
                it1 = words.erase(it1);
                it = it1;
            }
            else
            {
                it1++;
            }
        }

        for (auto it = words.begin(); it != words.end(); it++)
        {
            ret[*it].push_back(line_number);
        }
    }

    return ret;
}

int main()
{
    xref(std::cin, split);

    return 0;
}