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
    bool attend[2] = {false, false}; // Надо либо сделать что бы подстраивалось под количество в группе либо одинаковое количество всегда
public:// буллевый массив для посещаемости 1 булеан для 1 студента из массива group
    Attendence() {};
    Attendence(string newDate, Group newGroup, int newSubjID)
    {
        date = newDate;
        group = newGroup;
        subjID = newSubjID;
    }
    Attendence(string newDate, Group newGroup, int newSubjID, bool newAttend[])
    {
        date = newDate;
        group = newGroup;
        subjID = newSubjID;
        for (int i = 0; i < group.get_Number_of(); i++)
        {
            attend[i] = newAttend[i];
        }
    }

    void set_group(Group newGroup)// устанавливает группу
    {
        group = newGroup;
    }

    void Log_teacher()// выводит посещаемость студентов для учителя
    {
        int count = group.get_Number_of();
        cout << "Name\t" << date << endl;

        for (int i = 0; i < count; i++)
        {
            group.show_name(i);
            cout << "\t";
            if (attend[i])
            {
                cout<<"yes";
            }else{
            cout << "no";
            }
            cout << endl;
        }
    }
    void Log_student(int student_numb)// выводит посещаемость для студента
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
    void check_attend(int stud_numb)// что-бы поменять посещаемость студента
    {
    }
    void Log()// выводит информацию о посещаемости
    {
        
        cout << "ID: " << subjID << " Date: " << date << endl;
        cout << "Attendence: ";
        for (int i = 0; i < 32; i++)
        {
            if (attend[i])
            {
                cout << "yes ";
            }
            else
            {
                cout << "no ";
            }

            
        }
    }
        void read_data(fstream &file)
    {
        file.read((char*)&subjID, sizeof(subjID));
        file.read((char*)&attend, sizeof(attend));

        date = read_string(file); 
    }
        void write_data(fstream &file) {
            file.write((char*)&subjID, sizeof(subjID));
            file.write((char*)&attend, sizeof(attend));
            write_string(file, date);
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