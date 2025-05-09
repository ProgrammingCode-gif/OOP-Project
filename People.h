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

    string get_name(){
        return name;
    }
    void show_name(){
        cout<<name;
    }

    virtual void Log() {
        cout << "ID: " << id << " Name: " << name << " Surname: " << surname << endl;
    }
};

class Student : public Person {
    Grade* grades;
    int gradesCount;

public:
    Student() {
        grades = nullptr;
        gradesCount = 0;
    }
    Student(int newId, string newName, string newSurname, Grade* newGrades, int count)
        : Person(newId, newName, newSurname) {
            grades = new Grade[count];
            for (int i = 0; i < count; ++i) {
                grades[i] = newGrades[i];
            }
            gradesCount = count;    
    }
    ~Student() {
        delete[] grades;
    }

    void add_grade(const Grade& g) {
        Grade* newGrades = new Grade[gradesCount + 1];
        for (int i = 0; i < gradesCount; ++i) {
            newGrades[i] = grades[i];
        }
        newGrades[gradesCount] = g;

        delete[] grades;
        grades = newGrades;
        gradesCount++;
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
    Group(){};
    Group(Student* newStudents,int NewGroupId, int count){
        GroupId=NewGroupId;
        students=newStudents;
        numberOfStudents=count;
    };
    int get_id(){
        return GroupId;
    }
    Student get_student(int student_numb){
        // if (student_numb < 0 || student_numb >= numberOfStudents) {
        //     cout << "Invalid student index!\n";
        //     return students[0]; // return default-constructed student
        // }
        return students[student_numb];
    }
    void show_name(int student_numb){
        students[student_numb].show_name();
    }
    int get_Number_of(){
        return numberOfStudents;
    }
    void log(){
        for (int i = 0; i < numberOfStudents; i++)
        {
            students[i].Person::Log();
        }
        
    };
};

class Attendence{
    string date;
    Group group;
    int subjID;
    bool attend[2]={true,true};//Надо либо сделать что бы подстраивалось под количество в группе либо одинаковое количество всегда
    public:
    Attendence(){};
    Attendence(string newDate,Group newGroup, int newSubjID){
        date=newDate;
        group=newGroup;
        subjID=newSubjID;
    }
    void Log_teacher(){
        int count = group.get_Number_of();
        cout<<"Name\t"<<date<<endl;


        for (int i = 0; i < count; i++)
        {
            group.show_name(i);
            cout<<"\t";
            // if (attend[i])
            // {
            //     cout<<"yes";
            // }else{
                cout<<"no";
            // }
            cout<<endl;
            
        }
        
    }
    void Log_student(int student_numb){

        cout<<date<<"\t";

        if (attend[student_numb])
        {
            cout<<"yes";
        }else{
            cout<<"no";
        }
        cout<<endl;
    }
    void check_attend(int stud_numb){

    }
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
        int arrSize = 2;
        for (int i = 0; i < arrSize; i++)
        {
            cout << i + 1 << ") " <<"Group number "<< groups[i].get_id() << endl;
        }
        cout<<endl;
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
        groups[group_numb-1].get_student(student_numb-1).Log();
        add_grade(groups[group_numb-1].get_student(student_numb-1));
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