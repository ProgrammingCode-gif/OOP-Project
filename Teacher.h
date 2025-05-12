#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Group.h"
using namespace std;

class Teacher : public Person
{
    int subjectID;
    string subjectName;
    Group *groups;

public:
    Teacher() {};
    Teacher(int newId, string newName, string newSurname, int newSubjectID, string newSubjectName, Group *newGroups)
        : Person(newId, newName, newSurname)
    {
        subjectID = newSubjectID;
        subjectName = newSubjectName;
        groups = newGroups;
    }
    void show_subjectID()// выводит ID предмета
    {
        cout << subjectID;
    }
    void show_subjectName()// выводит название предмета
    {
        cout << subjectName;
    }
    void show_all_groups()// Выводит все группы
    {
        int arrSize = 2;
        for (int i = 0; i < arrSize; i++)
        {
            cout << i + 1 << ") " << "Group number " << groups[i].get_id() << endl;
        }
        cout << endl;
    }
    void show_all()//все перечисленное выше выводит на экран
    {
        Person::Log();
        show_all_groups();
        show_subjectName();
        show_subjectID();
    }
    // void add_grade(Student student)
    // {
    // }
    void choose_student(int group_numb, int student_numb)//выводит студентов для выбора
    {
        groups[group_numb - 1].get_student(student_numb - 1).Log();
        //add_grade(groups[group_numb - 1].get_student(student_numb - 1));
    }
    void choose_group(int group_numb)//выводит группу для выбора
    {
        int student_numb;
        cout << "Students of " << group_numb << " group\n";
        groups[group_numb - 1].log();
        cout << "choose student number:"; // not ID
        cin >> student_numb;
        choose_student(group_numb, student_numb);
    }

};