#include <iostream>
#include"other.h"
using namespace std;


class Grade {
    int subjectId;
    string subjectName;
    int score;
    string date;
    public:
        Grade() {};
        Grade(int newSubjectId, string newSubjectName, int newScore, string newDate) {
            subjectId = newSubjectId;
            subjectName = newSubjectName;
            score = newScore;
            date = newDate;
        }
    void Log(){
        cout << subjectName << " - " << score << " - " << date << endl;
    }
    int get_subj_ID(){
        return subjectId;
    }
    };


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
    
    void get_OOP_Grades(){
        for (int i = 0; i < gradesCount; i++) {
            if (grades[i].get_subj_ID()==1)
            {
                grades[i].Log();
            }
            
        }
    }
    void get_calc_Grades(){
        for (int i = 0; i < gradesCount; i++) {
            if (grades[i].get_subj_ID()==2)
            {
                grades[i].Log();
            }
            
        }
    }
    void get_phys_Grades(){
        for (int i = 0; i < gradesCount; i++) {
            if (grades[i].get_subj_ID()==3)
            {
                grades[i].Log();
            }
            
        }
    }
    void get_AE_Grades(){
        for (int i = 0; i < gradesCount; i++) {
            if (grades[i].get_subj_ID()==4)
            {
                grades[i].Log();
            }
            
        }
    }

    void Log() override {
        Person::Log();
        for (int i = 0; i < gradesCount; i++) {
            grades[i].Log();
        }
    }
    
};
class Group{
    public:
    int numberOfStudents;
    Student* students;
    int GroupId;
    Group(Student* newStudents, int count){
        students=newStudents;
        numberOfStudents=count;
    };
    int get_id(){
        return GroupId;
    }
    Student get_student(int student_numb){
        return students[student_numb-1];
    }
    void log(){
        for (int i = 0; i < numberOfStudents; i++)
        {
            students[i].Person::Log();
        }
        
    };
};
class Teacher : public Person {
    int subjectID;
    string subjectName;
    Group* groups;
public:
    Teacher() {};
    Teacher(int newId, string newName, string newSurname, int newSubjectID, string newSubjectName, Group* newGroups)
        :Person(newId, newName, newSurname) {
        subjectID = newSubjectID;
        subjectName = newSubjectName;
        groups = newGroups;
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
            cout << i + 1 << ") " << groups[i].get_id() << endl;
        }
    }
    void show_all() {
        Person::Log();
        show_all_groups();
        show_subjectName();
        show_subjectID();
    }
    void add_grade(Student student){

    }
    void choose_student(int group_numb,int student_numb){
        groups[group_numb-1].get_student(student_numb).Log();
        add_grade(groups[group_numb-1].get_student(student_numb));
    }
    void choose_group(int group_numb){
        int student_numb;
        cout<<"Students of "<< group_numb<< " group\n";
        groups[group_numb-1].log();
        cout<<"choose student number:";//not ID
        cin>>student_numb;
        choose_student(group_numb,student_numb);
    }
    void add_grade(){

    }
};