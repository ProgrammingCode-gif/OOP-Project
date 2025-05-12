#pragma once
#include <iostream>
#include <string>
using namespace std;

class Grade
{
    int subjectId;
    string subjectName;
    int score;
    string date;

public:
    Grade() {};
    Grade(int newSubjectId, string newSubjectName, int newScore, string newDate)
    {
        subjectId = newSubjectId;
        subjectName = newSubjectName;
        score = newScore;
        date = newDate;
    }
    void Log()// выводит информацию о оценке
    {
        cout << subjectName << " - " << score << " - " << date << endl;
    }
    int get_subj_ID()// возвращает ID предмета
    {
        return subjectId;
    }
};