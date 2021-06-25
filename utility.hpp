#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> split(std::string& s);
std::vector<std::string> frame(const std::vector<std::string> v);

double median(const std::vector<double>& v);
double average(const std::vector<double>& v);

void populateGrades(char* inFile, char* outFile);

#endif