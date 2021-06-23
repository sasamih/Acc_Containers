#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>

struct StudentInfo
{
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool loadGrades(std::fstream*, std::vector<StudentInfo>&);
bool importStudent(std::vector<StudentInfo>& students, std::vector<std::string>& s);
double getFinalGrade(StudentInfo& student);
bool passed(StudentInfo& student);
std::vector<StudentInfo> getFailingStudents(std::vector<StudentInfo>& students);

#endif