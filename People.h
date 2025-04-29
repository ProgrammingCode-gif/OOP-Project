#include <iostream>
#include"other.h"
using namespace std;



class Person {
    int id;
    string name;
    string surname;

public:
    Person() {};
    Person(int newId, string newName, string newSurname) {
        id = newId;
        name = newName;
        surname = newSurname;
    }
    virtual void Log() {
        cout << "ID: " << id << " Name: " << name << " Surname: " << surname << endl;
    }
};

class Student : public Person {
    Grade* grades;
    int gradesCount;

public:
    Student(int newId, string newName, string newSurname, Grade* newGrades, int count)
        : Person(newId, newName, newSurname) {
        grades = newGrades;
        gradesCount = count;
    }

    void Log() override {
        Person::Log();
        for (int i = 0; i < gradesCount; i++) {
            cout << grades[i].subjectName << " - " << grades[i].score << " - " << grades[i].date << endl;
        }
    }
};
class Teacher : public Person {
    int subjectID;
    string subjectName;
    int groups[5];//хз сколько групп будет
public:
    Teacher() {};
    Teacher(int newId, string newName, string newSurname, int newSubjectID, string newSubjectName, int newGroups[])
        :Person(newId, newName, newSurname) {
        subjectID = newSubjectID;
        subjectName = newSubjectName;
        cout << newGroups << "sdjkhakjshdkahsdjk" << endl;
        for (int i = 0; i < 5; ++i) {
            groups[i] = newGroups[i];
        }
    }
    void show_subjectID() {
        cout << subjectID;
    }
    void show_subjectName() {
        cout << subjectName;
    }
    void show_all_groups() {
        int arrSize = sizeof(groups) / sizeof(groups[0]);
        cout << "groups that you have\n";
        for (int i = 0; i < arrSize; i++)
        {
            cout << i + 1 << ") " << groups[i] << endl;
        }
    }
    void show_all() {
        Person::Log();
        show_all_groups();
        show_subjectName();
        show_subjectID();
    }
};