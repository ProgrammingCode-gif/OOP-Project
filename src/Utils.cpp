#include "../include/Utils.h"
#include <iostream>
#include <fstream>
using namespace std;

void handle_course(Student &student, Attendence *attendenceArray, int subjectId, const string &courseName, int person_numb)
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
            attendenceArray[i].Log_student(person_numb % 2); // Здесь можно сделать гибким выбор студента
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

void add_grade2(Group &group, int subjectID)
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
    add_grade(group.get_student_ref(choosing - 1), group.get_student_ref(choosing - 1).get_grade(subjectID).get_subj_ID(), group.get_student_ref(choosing - 1).get_grade(subjectID).get_subj_name(), score, date);
    cout << subjectID << endl;
    group.get_student_ref(choosing - 1).get_Grades_by_Subject(subjectID + 1);
}

void loadAllGrades(Grade **allGrades, int gradeCount, int studentCount)
{
    fstream file("Data/grade.dat", ios::in | ios::out | ios::binary);
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return;
    }

    for (int i = 0; i < studentCount; ++i)
    {
        allGrades[i] = new Grade[gradeCount]{};
        for (int j = 0; j < gradeCount; ++j)
        {
            allGrades[i][j].read_data(file);
        }
    }

    file.close();
}

void read_student(fstream &file, Student &student, Grade *grades, int gradeCount)
{
    student = Student(grades, gradeCount);
    student.read_data(file);
}

void add_attendence(Attendence *attArray, Group *group0, int groupCount, int count)
{
    string date;
    bool attend[2] = {false, false};
    cout << "Enter date of the attendence: ";
    cin >> date;

    for (int i = 0; i < 2; i++)
    {
        cout << "Enter attendence for student (1 for present, 0 for absent): ";
        group0[groupCount].get_student(i).Person::Log();
        cout << "Enter:";
        cin >> attend[i];
    }

    Attendence a1(date, group0[groupCount], 1, attend);

    attArray[count] = a1;
    cout << "Attendence added successfully!" << endl;
}

void teacher_menu(Teacher *allTeachers, Attendence **attendence, Group *groupAll, int person_numb, int att_arr[])
{
    int choosing, exit = 1;

    while (exit != 0)
    {
        cout << "\nWelcome to Eclass, choose group to manage, or enter 0 to exit:\n";
        allTeachers[person_numb].show_all_groups();
        cout << "Enter: ";
        cin >> choosing;
        int groupIndex = choosing - 1;
        if (choosing == 0)
            break;

        Group &selectedGroup = groupAll[choosing - 1];
        cout << "You chose group " << selectedGroup.get_ID() << ". What do you want to do?\n";
        cout << "1) Check Attendance\n2) Add Grade\n0) Back\nEnter: ";
        cin >> choosing;

        if (choosing == 0)
            continue;

        switch (choosing)
        {
        case 1:
            for (int i = 0; i < att_arr[choosing]; i++)
            {
                if (attendence[person_numb + 1][i].get_group().get_ID() == selectedGroup.get_ID())
                {
                    attendence[person_numb][i].Log_teacher();
                }
                else
                {

                    // // cout << attendence[person_numb][i].get_group().get_ID()<<"searching\n";
                    // // cout << selectedGroup.get_ID()<<"selected\n";
                    // cout<<"WRONG---------------------------------------------------------------------";
                    // attendence[person_numb][i].Log_teacher();
                    // cout<<"WRONG---------------------------------------------------------------------";
                }
            }

            cout << "Add attendance?\n1)Yes\n2)No\nEnter: ";
            cout << "\n"
                 << person_numb;
            cin >> choosing;
            if (choosing == 1)
            {
                add_attendence(attendence[person_numb], groupAll, groupIndex, att_arr[person_numb]);
                att_arr[person_numb]++;
            }
            break;
        case 2:
            add_grade2(selectedGroup, person_numb);
            break;
        default:
            cout << "Invalid option.\n";
        }
    }
}

void student_menu(Student *students, Attendence *OOP_att, Attendence *Calc_att, Attendence *Phys_att, Attendence *AE_att, Teacher *allTeachers, int person_numb)
{
    int choosing;

    while (true)
    {
        cout << "\nWelcome to Eclass, choose course to check:\n";
        cout << "1) Objective Oriented Programming\n2) Calculus\n3) Physics\n4) Academic English\n0) Back\nEnter: ";
        cin >> choosing;

        if (choosing == 0)
            break;

        Attendence *att = nullptr;
        switch (choosing)
        {
        case 1:
            att = OOP_att;
            break;
        case 2:
            att = Calc_att;
            break;
        case 3:
            att = Phys_att;
            break;
        case 4:
            att = AE_att;
            break;
        default:
            cout << "Invalid option.\n";
            continue;
        }

        handle_course(students[person_numb], att, allTeachers[choosing].get_subjectID(), allTeachers[choosing].get_subjectName(), person_numb);
    }
}
