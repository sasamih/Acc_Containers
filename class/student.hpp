#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

typedef enum
{
    EXCELENT_R = 10,
    EXCELENT = 9,
    VERY_GODD = 8,
    GOOD = 7,
    SUFFICIENT = 6,
    INSUFFICIENT = 5
} Grade;

class StudentInfo
{
    private:
        std::string name;
        double midterm, final;
        std::vector<double> homework;
        double homeworkPoints;
        double points;
        Grade grade;

    public:
        StudentInfo(std::string, double, double, std::vector<double>);

        Grade gradeStudent();
        bool valid();

        std::string getName();
        std::vector<double> getHomework();
        double calculateHomework(double homeworkMethod(const std::vector<double>&));
        double getHomeworkPoints();
        double getPoints();
        Grade getGrade();
        
        friend std::vector<std::string> getStatistics(std::vector<StudentInfo>&, std::ostream&);
};

#endif