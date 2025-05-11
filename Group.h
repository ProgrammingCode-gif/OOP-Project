#pragma once
#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

class Group
{
public:
    int numberOfStudents;
    Student *students;
    int GroupId;
    Group() {};
    Group(Student *newStudents, int NewGroupId, int count)
    {
        GroupId = NewGroupId;
        students = newStudents;
        numberOfStudents = count;
    };
    int get_id()
    {
        return GroupId;
    }
    Student get_student(int student_numb)
    {
        // if (student_numb < 0 || student_numb >= numberOfStudents) {
        //     cout << "Invalid student index!\n";
        //     return students[0]; // return default-constructed student
        // }
        return students[student_numb];
    }
    Student &get_student_ref(int index)
    {
        return students[index];
    }
    void show_name(int student_numb)
    {
        students[student_numb].show_name();
    }
    int get_Number_of()
    {
        return numberOfStudents;
    }
    void log()
    {
        for (int i = 0; i < numberOfStudents; i++)
        {
            students[i].Person::Log();
        }
    };
};