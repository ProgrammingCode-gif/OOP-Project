#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person
{
    string id;//also login
    string name;
    string surname;
    string password;
public:
    Person() {};
    Person(string newId, string newName, string newSurname, string newPassword)
    {
        id = newId;
        name = newName;
        surname = newSurname;
        password = newPassword;
    }

    string get_id()//установить ID
    {
        return id;
    }
    string get_password()//установить ID
    {
        return password;
    }

    string get_name()//получить имя
    {
        return name;
    }
    void show_name()//показать имя
    {
        cout << name;
    }

    virtual void Log()//вывод информации о человеке
    {
        cout << "ID: " << id << " Name: " << name << " Surname: " << surname << endl;
    }

        void read_data(fstream &file)
    {
        id = read_string(file); 
        name = read_string(file); 
        surname = read_string(file);  
        password = read_string(file);  
    }
        void write_data(fstream &file) {
            write_string(file, id);
            write_string(file, name);
            write_string(file, surname);
            write_string(file, password);
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