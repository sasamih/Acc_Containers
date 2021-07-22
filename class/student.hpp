#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>

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
        static int constructor;
        static int copy;
        static int assignment;
        static int destructor;
        StudentInfo();  
        StudentInfo(std::string, double, double, std::vector<double>);
        StudentInfo(const StudentInfo&);
        ~StudentInfo();
        
        StudentInfo& operator=(const StudentInfo&);

        Grade gradeStudent();
        bool valid();

        std::string getName();
        std::vector<double> getHomework();
        double calculateHomework(double homeworkMethod(std::vector<double>&));
        double getHomeworkPoints();
        double getPoints();
        Grade getGrade();

        void setHomeworkPoints(double);
        
        std::tuple<std::string, int, std::string> getStudentInfo();
        friend std::vector<std::string> getStatistics(std::vector<StudentInfo>&, std::ostream&);
};

#endif