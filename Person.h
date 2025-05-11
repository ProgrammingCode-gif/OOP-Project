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

    string get_name()
    {
        return name;
    }
    void show_name()
    {
        cout << name;
    }

    virtual void Log()
    {
        cout << "ID: " << id << " Name: " << name << " Surname: " << surname << endl;
    }
};