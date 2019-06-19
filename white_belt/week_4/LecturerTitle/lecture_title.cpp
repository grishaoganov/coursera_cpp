#include <string>
using namespace std;

struct Specialization{
    string value;
    explicit Specialization(const string& s){
        value = s;
    }
};

struct Course{
    string value;
    explicit Course(const string& s){
        value = s;
    }
};

struct Week{
    string value;
    explicit Week(const string& s){
        value = s;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(const Specialization& new_spec, const Course& new_course, const Week& new_week){
        specialization = new_spec.value;
        course = new_course.value;
        week = new_week.value;
    }
};