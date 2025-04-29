#include <iostream>
using namespace std;

class Grade {
public:
    int subjectId;
    string subjectName;
    int score;
    string date;
    Grade() {};
    Grade(int newSubjectId, string newSubjectName, int newScore, string newDate) {
        subjectId = newSubjectId;
        subjectName = newSubjectName;
        score = newScore;
        date = newDate;
    }
};