#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include "utility.hpp"

struct StudentInfo
{
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool loadGrades(std::fstream*, std::vector<StudentInfo>&);
bool importStudent(std::vector<StudentInfo>& students, std::vector<std::string>& s);
double getFinalGrade(StudentInfo& student, double homeworkMethod(const std::vector<double>&));
double calculateHomeworkPoints(std::vector<double>&, double calculateMethod(const std::vector<double>&));
bool passed(StudentInfo& student, double homeworkMethod(const std::vector<double>&));
void rangeStatistics(std::vector<StudentInfo>& students);
std::vector<StudentInfo> getFailingStudentsAverage(std::vector<StudentInfo>& students);
std::vector<StudentInfo> extractFailsAverage(std::vector<StudentInfo>& students);
std::vector<StudentInfo> extractFailsKeepOriginalAverage(std::vector<StudentInfo>& students);
std::vector<StudentInfo> getFailingStudentsMedian(std::vector<StudentInfo>& students);
std::vector<StudentInfo> extractFailsMedian(std::vector<StudentInfo>& students);
std::vector<StudentInfo> extractFailsKeepOriginalMedian(std::vector<StudentInfo>& students);
double optimisticMedian(const StudentInfo& s);
double medianAnalysis(const std::vector<StudentInfo>& students);

#endif