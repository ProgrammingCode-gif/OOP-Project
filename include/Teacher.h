#pragma once
#include <iostream>
#include <string>
#include <fstream>
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
    Teacher(string newId, string newName, string newSurname, int newSubjectID, string newSubjectName, Group *newGroups,string newPassword="password")
        : Person(newId, newName, newSurname, newPassword)
    {
        subjectID = newSubjectID;
        subjectName = newSubjectName;
        groups = newGroups;
    }
    void show_subjectID()// выводит ID предмета
    {
        cout << subjectID<<endl;
    }
    void show_subjectName()// выводит название предмета
    {
        cout << subjectName<<endl;
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
    
    void read_data (fstream &file)
    {
        Person::read_data(file);
        file.read((char*)&subjectID, sizeof(subjectID));
        subjectName = read_string(file);  
    }
    void write_data(fstream &file) {
        Person::write_data(file);
        file.write((char*)&subjectID, sizeof(subjectID));
        write_string(file, subjectName);
    }
private:
        string read_string(fstream &file){
            int len;
            file.read((char*)&len, sizeof(len)); 
            char* buffer = new char[len + 1];  
            file.read(buffer, len);  
            buffer[len] = '\0';  
            std::string result(buffer); 
            delete[] buffer;  
            return result;
        }
        void write_string(fstream &file, string &str) {
            int len = str.length();
            file.write((char*)&len, sizeof(len));
            file.write(str.c_str(), len);
        }
};