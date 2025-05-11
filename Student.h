#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Grade.h"
using namespace std;

class Student : public Person
{
    Grade *grades;
    int gradesCount;

public:
    Student()
    {
        grades = nullptr;
        gradesCount = 0;
    }
    Student(int newId, string newName, string newSurname, Grade *newGrades, int count)
        : Person(newId, newName, newSurname)
    {
        grades = new Grade[count];
        for (int i = 0; i < count; ++i)
        {
            grades[i] = newGrades[i];
        }
        gradesCount = count;
    }
    Student(const Student &other)
        : Person(other), gradesCount(other.gradesCount)
    {
        grades = new Grade[gradesCount];
        for (int i = 0; i < gradesCount; ++i)
            grades[i] = other.grades[i];
    }

    // оператор присваивания
    Student &operator=(const Student &other)
    {
        if (this != &other)
        {
            Person::operator=(other);
            delete[] grades;

            gradesCount = other.gradesCount;
            grades = new Grade[gradesCount];
            for (int i = 0; i < gradesCount; ++i)
                grades[i] = other.grades[i];
        }
        return *this;
    }
    ~Student()
    {
        delete[] grades;
    }

    void add_grade(const Grade &g)
    {
        Grade *newGrades = new Grade[gradesCount + 1];
        for (int i = 0; i < gradesCount; ++i)
        {
            newGrades[i] = grades[i];
        }
        newGrades[gradesCount] = g;

        delete[] grades;
        grades = newGrades;
        gradesCount++;
    }

    void get_OOP_Grades()
    {
        for (int i = 0; i < gradesCount; i++)
        {
            if (grades[i].get_subj_ID() == 1)
            {
                grades[i].Log();
            }
        }
    }
    void get_calc_Grades()
    {
        for (int i = 0; i < gradesCount; i++)
        {
            if (grades[i].get_subj_ID() == 2)
            {
                grades[i].Log();
            }
        }
    }
    void get_phys_Grades()
    {
        for (int i = 0; i < gradesCount; i++)
        {
            if (grades[i].get_subj_ID() == 3)
            {
                grades[i].Log();
            }
        }
    }
    void get_AE_Grades()
    {
        for (int i = 0; i < gradesCount; i++)
        {
            if (grades[i].get_subj_ID() == 4)
            {
                grades[i].Log();
            }
        }
    }

    void Log() override
    {
        Person::Log();
        for (int i = 0; i < gradesCount; i++)
        {
            grades[i].Log();
        }
    }
};