#include "../include/Utils.h"
#include <iostream>
#include <fstream>
using namespace std;

void handle_course(Student &student, Attendence *attendenceArray, int subjectId, const string &courseName)
{
    int choosing;
    cout << "What you want to check for " << courseName << "?\n1)Marks\n2)Attendence\nEnter: ";
    cin >> choosing;

    switch (choosing)
    {
    case 1:
        student.get_Grades_by_Subject(subjectId);
        break;
    case 2:
        cout << "Date\t\t Attendence\n";
        for (int i = 0; i < 4; i += 2)
        {
            attendenceArray[i].Log_student(0); // Здесь можно сделать гибким выбор студента
        }
        break;
    default:
        cout << "Wrong!";
        break;
    }
}

void add_grade(Student &stud, int newSubjectId, const string &newSubjectName, int newScore, const string &newDate)
{
    Grade g(newSubjectId, newSubjectName, newScore, newDate);
    stud.add_grade(g);
}

void add_grade2(Group &group)
{
    int score, choosing;
    string date;
    group.log();
    cout << "Choose student to add mark:\n";
    cin >> choosing;
    cout << "Enter date of the mark: ";
    cin >> date;
    cout << "Enter score of the mark: ";
    cin >> score;
    add_grade(group.get_student_ref(choosing - 1), 1, "OOP", score, date);
    group.get_student_ref(choosing - 1).Log();
}

void read_grades(fstream &file, Grade *grades, int count)
{
    for (int i = 0; i < count; ++i)
    {
        Grade g;
        g.read_data(file);
        grades[i] = g;
    }
}

void read_student(fstream &file, Student &student, Grade *grades, int gradeCount)
{
    student = Student(grades, gradeCount);
    student.read_data(file);
}