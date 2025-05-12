#include <iostream>
#include "./include/Group.h"
#include "./include/Attendence.h"
#include "./include/Student.h"
#include "./include/Teacher.h"
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

void add_grade(Student &stud, int newSubjectId, string newSubjectName, int newScore, string newDate)
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
    cout << "Enter";
    cin >> date;
    cout << "Enter date of the mark:";
    cin >> score;
    cout << "Enter score of the mark:";
    add_grade(group.get_student_ref(choosing - 1), 1, "OOP", score, date);
    group.get_student_ref(choosing - 1).Log();
    group.get_student_ref(choosing - 1).Log();
    cout << "dsds";
};

// void get_marks(){

// }

int main()
{

    Grade g0(1, "OOP", 100, "21.04.25");
    Grade g1(1, "OOP", 96, "21.04.25");
    Grade g2(1, "OOP", 92, "21.04.25");
    Grade g3(1, "OOP", 88, "21.04.25");

    Grade *grades0 = new Grade[1]{g0};
    Grade *grades1 = new Grade[1]{g1};
    Grade *grades2 = new Grade[1]{g2};
    Grade *grades3 = new Grade[1]{g3};

    Student s0(243, "Shahzod", "Tashev", grades0, 1);
    Student s1(250, "Marat", "Turakulov", grades1, 1);
    Student s2(228, "Timur", "Shomuratov", grades2, 1);
    Student s3(237, "Bulat", "Tsoy", grades3, 1);

    add_grade(s0, 2, "Calculus", 99, "21.03.25");
    add_grade(s0, 3, "Physics", 98, "21.02.25");
    add_grade(s0, 4, "AE", 97, "21.01.25");

    add_grade(s1, 2, "Calculus", 95, "21.03.25");
    add_grade(s1, 3, "Physics", 94, "21.02.25");
    add_grade(s1, 4, "AE", 93, "21.01.25");

    add_grade(s2, 2, "Calculus", 91, "21.03.25");
    add_grade(s2, 3, "Physics", 90, "21.02.25");
    add_grade(s2, 4, "AE", 89, "21.01.25");

    add_grade(s3, 2, "Calculus", 87, "21.03.25");
    add_grade(s3, 3, "Physics", 86, "21.02.25");
    add_grade(s3, 4, "AE", 85, "21.01.25");

    Student *students1 = new Student[2]{s0, s1};
    Student *students2 = new Student[2]{s2, s3};

    Group group0(students1, 9, 2);
    Group group1(students2, 10, 2);
    Group *groupAll = new Group[2]{group0, group1};

    Attendence d1g1s1("21.04.25", group0, 1); // d-day g-group s-subject
    Attendence d1g2s1("21.04.25", group1, 1);
    Attendence d1g1s2("21.04.25", group0, 2);
    Attendence d1g2s2("21.04.25", group1, 2);
    Attendence d2g1s1("21.06.25", group0, 1);
    Attendence d2g2s1("21.06.25", group1, 1);
    Attendence d2g1s2("21.06.25", group0, 2);
    Attendence d2g2s2("21.06.25", group1, 2);

    Attendence *OOP_att = new Attendence[4]{d1g1s1, d1g2s1, d2g1s1, d2g2s1};
    Attendence *Calc_att = new Attendence[4]{d1g1s2, d1g2s2, d2g1s2, d2g2s2};

    Teacher t0(007, "Sarvar", "ya xz", 02, "i.t. IT", groupAll);

    int log_in;
    int choosing;
    string date;
    int score;
    cout << "what you want to be logged in?\n1)Admin\n2)Teacher\n3)Student\nEnter:";
    cin >> log_in;
    switch (log_in)
    {
    case 1:

        break;
    case 2:
        cout << "Welcome to Eclass, choose group to make changes\n";
        t0.show_all_groups();
        cout << "Enter:";
        cin >> choosing;
        switch (choosing)
        {
        case 1: // group 9
            cout << "You chose group 9. What you want to do?\n1)Check attendence\n2)Add grade\nEnter:";
            cin >> choosing;
            switch (choosing)
            {
            case 1:
                cout << "Group 9 attendence list:\n";
                for (int i = 0; i < 4; i += 2)
                {
                    OOP_att[i].Log_teacher();
                }
                break;
            case 2:
                add_grade2(group0);
            default:
                break;
            }
            break;
        case 2: // group 10
            cout << "You chose group 10. What you want to do?\n1)Check attendence\n2)Add grade\nEnter:";
            cin >> choosing;
            switch (choosing)
            {
            case 1:
                cout << "Group 10 attendence list:\n";
                for (int i = 1; i < 4; i += 2)
                {
                    OOP_att[i].Log_teacher();
                }
                break;
            case 2:
                add_grade2(group1);
            default:
                break;
            }
            break;
        default:
            break;
        }

        break;
        case 3:
        cout << "Welcome to Eclass, choose course you want to check\n1)Objective Oriented Programming\n2)Calculus\n3)Physics\n4)Academic English\nEnter:";
        cin >> choosing;
    
        switch (choosing)
        {
        case 1: // OOP
            handle_course(s1, OOP_att, 1, "Objective Oriented Programming");
            break;
        case 2: // Calculus
            handle_course(s1, Calc_att, 2, "Calculus");
            break;
        case 3: // Physics
            handle_course(s1, Calc_att, 3, "Physics");
            break;
        case 4: // Academic English
            handle_course(s1, Calc_att, 4, "Academic English");
            break;
        default:
            cout << "Wrong!";
            break;
        }
        break;
    default:
        cout << "Wrong!";
    };
    // t0.show_all();
    // s1.Log();
    // group1.log();
    //  t0.choose_group(2);

    delete[] OOP_att;
    delete[] Calc_att;
    delete[] grades0;
    delete[] grades1;
    delete[] grades2;
    delete[] grades3;
    delete[] students1;
    delete[] students2;
    delete[] groupAll;
    return 0;
}