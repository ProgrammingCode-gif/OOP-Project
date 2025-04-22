#include <iostream>
using namespace std;

class Grade {
public: 
    int subjectId;
    string subjectName;
    int score;
    string date;

    Grade(int newSubjectId, string newSubjectName, int newScore, string newDate) {
        subjectId = newSubjectId;
        subjectName = newSubjectName;
        score = newScore;
        date = newDate;
    }
};

class Person {
    int id;
    string name;
    string surname;

public:
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
        for(int i = 0; i < gradesCount; i++) {
            cout << grades[i].subjectName << " - " << grades[i].score << " - " << grades[i].date << endl;
        }
    }
};