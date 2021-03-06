#include "student.hpp"

int StudentInfo::constructor = 0;
int StudentInfo::copy = 0;
int StudentInfo::destructor = 0;
int StudentInfo::assignment = 0;

template <class T>
T average(const std::vector<T>& v)
{
    double sum = 0.0;

    for (auto it = v.begin(); it != v.end(); it++)
    {
        sum += *it;
    }

    return sum / v.size();
}

template <class T>
T median(std::vector<T>& v)
{
    typedef typename std::vector<T>::size_type sz;

    sz middle = v.size() / 2;
    std::sort(v.begin(), v.end());
    auto it = v.begin() + middle;
    
    return *it;
}

StudentInfo::StudentInfo()
{
    constructor++;
}

StudentInfo::StudentInfo(std::string n, double m, double f, std::vector<double> h): name(n), midterm(m), final(f), homework(h)
{
    try
    {
        homeworkPoints = calculateHomework(median);
        grade = gradeStudent();
    }
    catch(const char* msg)
    {
        std::cerr << msg << std::endl;
    }
    constructor++; 
}

StudentInfo::StudentInfo(const StudentInfo& s) : name(s.name)
{
    midterm = s.midterm;
    final = s.final;
    homework = s.homework;
    homeworkPoints = s.homeworkPoints;
    points = s.points;
    grade = s.grade;

    copy++;
}

StudentInfo::~StudentInfo()
{
    name = "";
    homework.clear();
    midterm = final = homeworkPoints = points = 0.0;
    grade = INSUFFICIENT;
    destructor++;
}
        
StudentInfo& StudentInfo::operator=(const StudentInfo& rhs)
{
    if (&rhs != this)
    {
        name = rhs.name;
        final = rhs.final;
        homework = rhs.homework;
        homeworkPoints = rhs.homeworkPoints;
        points = rhs.points;
        grade = rhs.grade;
    }
    assignment++;
    return *this;
}

Grade StudentInfo::gradeStudent()
{
    points = (0.2 * midterm) + (0.4 * final) + (0.4 * homeworkPoints);

    if (points > 91)
    { 
        grade = EXCELENT_R;
    }
    else if (points > 81)
    {
        grade = EXCELENT;
    }
    else if (points > 71)
    {
        grade = VERY_GODD;
    }
    else if (points > 61)
    {
        grade = GOOD;
    }
    else if (points > 50)
    {
        grade = SUFFICIENT;
    }
    else
    {
        grade = INSUFFICIENT;
    }

    return grade;
}

double StudentInfo::calculateHomework(double homeworkMethod(std::vector<double>&))
{
    // if (homework.empty())
    //     throw "Homework not loaded";

    homeworkPoints = homeworkMethod(homework);

    return homeworkPoints;
}

std::tuple<std::string, int, std::string> StudentInfo::getStudentInfo()
{
    std::string mark;

    switch (grade)
    {
        case INSUFFICIENT:
            mark = "F";
            break;
        
        case SUFFICIENT:
            mark = "E";
            break;

        case GOOD:
            mark = "D";
            break;

        case VERY_GODD:
            mark = "C";
            break;

        case EXCELENT:
            mark = "B";
            break;

        case EXCELENT_R:
            mark = "A";
            break;

        default:
            break;
    }

    return std::make_tuple(name, points, mark);
}

std::vector<std::string> getStatistics(std::vector<StudentInfo>& studs, std::ostream& os)
{
    std::map<Grade, int> marks;
    std::vector<std::string> out;

    marks.insert(std::pair<Grade, int>(EXCELENT_R, 0));
    marks.insert(std::pair<Grade, int>(EXCELENT, 0));
    marks.insert(std::pair<Grade, int>(VERY_GODD, 0));
    marks.insert(std::pair<Grade, int>(GOOD, 0));
    marks.insert(std::pair<Grade, int>(SUFFICIENT, 0));
    marks.insert(std::pair<Grade, int>(INSUFFICIENT, 0));    

    for (auto it = studs.begin(); it != studs.end(); it++)
    {
        switch (it->getGrade())
        {
            case INSUFFICIENT:
                marks[INSUFFICIENT]++;
                break;
            
            case SUFFICIENT:
                marks[SUFFICIENT]++;
                break;

            case GOOD:
                marks[GOOD]++;
                break;

            case VERY_GODD:
                marks[VERY_GODD]++;
                break;

            case EXCELENT:
                marks[EXCELENT]++;
                break;

            case EXCELENT_R:
                marks[EXCELENT_R]++;
                break;

            default:
                break;
        }
    }

    for (auto it = marks.begin(); it != marks.end(); it++)
    {
        switch (it->first)
        {
            case INSUFFICIENT:
                os << "F: " << it->second << std::endl;
                break;
            
            case SUFFICIENT:
                os << "E: " << it->second << std::endl;
                break;

            case GOOD:
                os << "D: " << it->second << std::endl;
                break;

            case VERY_GODD:
                os << "C: " << it->second << std::endl;
                break;

            case EXCELENT:
                os << "B: " << it->second << std::endl;
                break;

            case EXCELENT_R:
                os << "A: " << it->second << std::endl;
                break;

            default:
                break;
        }
    }

    return out;
}


bool StudentInfo::valid()
{
    // if ((!homework.empty()) && (midterm != 0.0) && (final != 0.0))
        return true;
    // return false;
}

std::string StudentInfo::getName()
{
    return name;
}

std::vector<double> StudentInfo::getHomework()
{
    return homework;
}

double StudentInfo::getHomeworkPoints()
{
    return homeworkPoints;
}

double StudentInfo::getPoints()
{
    return points;
}

Grade StudentInfo::getGrade()
{
    return grade;
}

void StudentInfo::setHomeworkPoints(double pt)
{
    homeworkPoints = pt;
}