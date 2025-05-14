#include <iostream>
#include <fstream>
#include <string>
#include "./include/Group.h"
#include "./include/Attendence.h"
#include "./include/Student.h"
#include "./include/Teacher.h"
#include <cstdlib>
#include <ctime>
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
    cout << "Enter date of the mark:";
    cin >> date;
    cout << "Enter score of the mark:";
    cin >> score;
    add_grade(group.get_student_ref(choosing - 1), 1, "OOP", score, date);
    group.get_student_ref(choosing - 1).Log();
    group.get_student_ref(choosing - 1).Log();
};
void read_grades(fstream &file, Grade* grades, int count) {
    for (int i = 0; i < count; ++i) {
        Grade g;
        g.read_data(file);
        grades[i] = g;
    }
}
void read_student(fstream &file, Student &student, Grade* grades, int gradeCount) {
    student = Student(grades, gradeCount);
    student.read_data(file);
}



int main()
{

    fstream file;
    file.open("Data/grade.dat", ios::in | ios::out | ios::binary);

    const int gradeCount = 4;
    Grade* allGrades[4] = {
    new Grade[gradeCount]{},
    new Grade[gradeCount]{},
    new Grade[gradeCount]{},
    new Grade[gradeCount]{}
    };

    for (int i = 0; i < 4; ++i) {
        read_grades(file, allGrades[i], gradeCount);
    }
    file.close();

    file.open("Data/student.dat", ios::in| ios::out| ios::binary);

    Student* allStudents = new Student[4]{};

    for (int i = 0; i < 4; ++i) {
        read_student(file, allStudents[i], allGrades[i], 4);
    }
    file.close();
    
    Student* students1 = new Student[2]{ allStudents[0], allStudents[1] };
    Student* students2 = new Student[2]{ allStudents[2], allStudents[3] };

    Group group0(students1, 9, 2);
    Group group1(students2, 10, 2);
    Group *groupAll = new Group[2]{group0, group1};
    srand(static_cast<unsigned>(time(0)));
    
    file.open("Data/attendence.dat", ios::in | ios::out | ios::binary);

    const int attendenceCount = 32;
    Attendence* allAttendence = new Attendence[attendenceCount];

    for (int i = 0; i < attendenceCount; ++i) {
        allAttendence[i].read_data(file);
    }

    for (int i = 0; i < 32; ++i) {
        if ((i / 4) % 2 == 0) 
            allAttendence[i].set_group(groupAll[0]);
        else 
            allAttendence[i].set_group(groupAll[1]);
    }

    Attendence* OOP_att = new Attendence[8];
    Attendence* Calc_att = new Attendence[8];
    Attendence* Physics_att = new Attendence[8];
    Attendence* Academic_att = new Attendence[8];

    for (int i = 0; i < 8; ++i) {
        OOP_att[i] = allAttendence[i * 4 + 0];     
        Calc_att[i] = allAttendence[i * 4 + 1];     
        Physics_att[i] = allAttendence[i * 4 + 2];  
        Academic_att[i] = allAttendence[i * 4 + 3]; 
    }

    file.close();

    Teacher t0(001, "Sharof", "Suvanov", 02, "i.t. IT", groupAll);
    Teacher t1(002, "Steftcho", "Dokov", 02, "i.t. IT", groupAll);

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
                for (int i = 0; i < 8; i += 2)
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
                for (int i = 1; i < 8; i += 2)
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
            handle_course(students1[0], OOP_att, 1, "Objective Oriented Programming");
            break;
        case 2: // Calculus
            handle_course(students1[0], Calc_att, 2, "Calculus");
            break;
        case 3: // Physics
            handle_course(students1[0], Calc_att, 3, "Physics");
            break;
        case 4: // Academic English
            handle_course(students1[0], Calc_att, 4, "Academic English");
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
    delete[] allGrades;
    delete[] students1;
    delete[] students2;
    delete[] groupAll;
    return 0;
}