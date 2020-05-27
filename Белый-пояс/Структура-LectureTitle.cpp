#include <iostream>
#include <string>
using namespace std;

struct Specialization {
    string word;
    explicit Specialization(const string& new_specialization) {
        word = new_specialization;
    }
};

struct Course {
    string word;
    explicit Course(const string& new_course) {
        word = new_course;
    }
};

struct Week {
    string word;
    explicit Week(const string& new_week) {
        word = new_week;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(const Specialization& new_specialization, const Course& new_course, const Week& new_week) {
        specialization = new_specialization.word;
        course = new_course.word;
        week = new_week.word;
    }
};

int main() {
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );
    cout << title.specialization << ": " << title.course << " - " << title.week;
    return 0;
}
