#pragma once
#include <iostream>
#include <string>
#include "Group.h"
using namespace std;

class Attendence
{
    string date;
    Group group;
    int subjID;
    bool attend[2] = {true, true}; // Надо либо сделать что бы подстраивалось под количество в группе либо одинаковое количество всегда
public:
    Attendence() {};
    Attendence(string newDate, Group newGroup, int newSubjID)
    {
        date = newDate;
        group = newGroup;
        subjID = newSubjID;
    }
    void Log_teacher()
    {
        int count = group.get_Number_of();
        cout << "Name\t" << date << endl;

        for (int i = 0; i < count; i++)
        {
            group.show_name(i);
            cout << "\t";
            // if (attend[i])
            // {
            //     cout<<"yes";
            // }else{
            cout << "no";
            // }
            cout << endl;
        }
    }
    void Log_student(int student_numb)
    {

        cout << date << "\t";

        if (attend[student_numb])
        {
            cout << "yes";
        }
        else
        {
            cout << "no";
        }
        cout << endl;
    }
    void check_attend(int stud_numb)
    {
    }
};