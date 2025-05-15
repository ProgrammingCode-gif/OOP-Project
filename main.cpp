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
    const int gradeCount = 4;
    const int studentCount = 4;
    Grade *allGrades[studentCount];
    loadAllGrades(allGrades, gradeCount, studentCount);

    file.open("Data/student.dat", ios::in | ios::out | ios::binary);

    Student *allStudents = new Student[4]{};

    for (int i = 0; i < 4; ++i)
    {
        read_student(file, allStudents[i], allGrades[i], 4);
    }
    file.close();

    Student *students1 = new Student[2]{allStudents[0], allStudents[1]};
    Student *students2 = new Student[2]{allStudents[2], allStudents[3]};

    Group group0(students1, 9, 2);
    Group group1(students2, 10, 2);
    Group *groupAll = new Group[2]{group0, group1};
    cout << groupAll[0].get_ID();
    file.open("Data/attendence.dat", ios::in | ios::out | ios::binary);

    const int attendenceCount = 32;
    Attendence *allAttendence = new Attendence[attendenceCount];

    for (int i = 0; i < attendenceCount; ++i)
    {
        allAttendence[i].read_data(file);
        if ((i / 4) % 2 == 0)
            allAttendence[i].set_group(groupAll[0]);
        else
            allAttendence[i].set_group(groupAll[1]);
    }

    Attendence *OOP_att = new Attendence[12];
    Attendence *Calc_att = new Attendence[12];
    Attendence *Physics_att = new Attendence[12];
    Attendence *Academic_att = new Attendence[12];
    for (int i = 0; i < 8; ++i)
    {
        OOP_att[i] = allAttendence[i];           // 0 - 7
        Calc_att[i] = allAttendence[i + 8];      // 8 - 15
        Physics_att[i] = allAttendence[i + 16];  // 16 - 23
        Academic_att[i] = allAttendence[i + 24]; // 24 - 31
    }
    Attendence **allSubjects = new Attendence *[4];
    allSubjects[0] = OOP_att;
    allSubjects[1] = Calc_att;
    allSubjects[2] = Physics_att;
    allSubjects[3] = Academic_att;

    int att_arr[4] = {8, 8, 8, 8};
    file.close();

    file.open("Data/teacher.dat", ios::in | ios::out | ios::binary);

    Teacher *allTeachers = new Teacher[4]{};
    for (int i = 0; i < 4; ++i)
    {
        allTeachers[i].read_data(file);
    }
    file.close();
    int log_in = 2;
    int person_numb = 0;
    string id;
    string password;
    // cout<<"Welcome to Eclass, please log in\n Enter your ID:";
    // cin >> id;
    // cout<<"Enter your password:";
    // cin >> password;
    // if(id[0] == 'P'|| id[0] == 'p'){
    //     for (int i = 0; i < 4; i++)
    //     {
    //         id[0] = 'P';
    //         if(allTeachers[i].get_id() == id&& allTeachers[i].get_password() == password){
    //             person_numb = i;
    //             log_in = 2;
    //         }
    //     }
    // }else if(id[0] == 'S'|| id[0] == 's'){
    //         for (int i = 0; i < 4; i++)
    //     {
    //         id[0] = 'S';
    //         if(allStudents[i].get_id() == id&& allStudents[i].get_password() == password){
    //             person_numb = i;
    //             log_in = 3;
    //             break;
    //         }
    //     }
    // }else{
    //     cout<<"WRONG3!\n";
    // }

    switch (log_in)
    {
    case 2:
        teacher_menu(allTeachers, allSubjects, groupAll, person_numb, att_arr);
        break;
    case 3:
        student_menu(students1, OOP_att, Calc_att, Physics_att, Academic_att, allTeachers, person_numb);
        break;
    default:
        cout << "Invalid input.\n";
    }

    delete[] OOP_att;
    delete[] Calc_att;
    delete[] allGrades;
    delete[] students1;
    delete[] students2;
    delete[] groupAll;
    return 0;
}