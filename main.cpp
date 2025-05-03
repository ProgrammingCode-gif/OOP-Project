#include <iostream>
#include "People.h"
#include "other.h"

using namespace std;

int main() {
    Grade g01(1, "Calculus", 99, "20.03.25");
    Grade g02(2, "OOP", 99, "21.04.25");
    Grade g11(1, "Calculus", 60, "18.03.25");
    Grade g12(2, "OOP", 50, "19.04.25");
    Grade* grades1 = new Grade[2]{g01, g02};
    Grade* grades2 = new Grade[2]{g11, g12};
    Student s1(243, "Shahzod", "Tashev", grades1, 2);
    Student s2(243, "Marat", "Turakulov", grades2, 2);
    Student* students1=new Student[2]{s1,s2};
    Group group1(students1, 2);
    int groups[5] = {1, 2, 3, 4, 5};
    Teacher t1(007, "Sarvar", "ya xz", 02, "i.t. IT", groups);
    //t1.show_all();
    //s1.Log();
    //group1.log();
    delete[] grades1;
    delete[] grades2;
    delete[] students1;
    return 0;
}