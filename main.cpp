#include <iostream>
#include <fstream>
#include <string>
#include "./include/Group.h"
#include "./include/Attendence.h"
#include "./include/Student.h"
#include "./include/Teacher.h"
#include "./include/Utils.h"
using namespace std;

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
    // file.open("Data/student.dat", ios::in | ios::out | ios::binary);
    // Student s0("S243", "Shahzod", "Tashev", allGrades[0], 1, "qwerty243");
    // Student s1("S250", "Marat", "Turakulov", allGrades[0], 1, "qwerty250");
    // Student s2("S228", "Timur", "Shomuratov", allGrades[0], 1, "qwerty228");
    // Student s3("S237", "Bulat", "Tsoy", allGrades[0], 1, "qwerty237");

    // s0.write_data(file);
    // s1.write_data(file);
    // s2.write_data(file);
    // s3.write_data(file);
    // file.close();
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

    
    Teacher t0("P001", "Sharof", "Suvanov", 02, "i.t. IT", groupAll, "password");
    Teacher t1("P002", "Steftcho", "Dokov", 02, "i.t. IT", groupAll, "password");

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
    
    delete[] OOP_att;
    delete[] Calc_att;
    delete[] allGrades;
    delete[] students1;
    delete[] students2;
    delete[] groupAll;
    return 0;
}