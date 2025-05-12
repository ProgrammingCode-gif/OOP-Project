#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
    int id;
    string name;
    string surname;

public:
    Person() {};
    Person(int newId, string newName, string newSurname)
    {
        id = newId;
        name = newName;
        surname = newSurname;
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
};