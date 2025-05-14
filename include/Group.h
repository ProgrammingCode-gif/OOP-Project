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
    int get_id()//получить номер группы
    {
        return GroupId;
    }
    Student get_student(int student_numb)//получить обьект студента 
    {
        // if (student_numb < 0 || student_numb >= numberOfStudents) {
        //     cout << "Invalid student index!\n";
        //     return students[0]; // return default-constructed student
        // }
        return students[student_numb];
    }
    Student &get_student_ref(int index)//получить ссылку на обьект студента
    {
        return students[index];
    }
    void show_name(int student_numb)//показать имя студента
    {
        students[student_numb].show_name();
    }
    int get_Number_of()//получить количество студентов
    {
        return numberOfStudents;
    }
    int get_groupID()//получить номер группы
    {
        return GroupId;
    }
    void log()//вывести каждого студента
    {
        for (int i = 0; i < numberOfStudents; i++)
        {
            students[i].Person::Log();
        }
    };
};