#include <iostream>
#include "People.h"
#include "other.h"

using namespace std;

int main() {
    Grade g1(1, "Calculus", 99, "20.03.25");
    Grade g2(2, "OOP", 100, "21.04.25");
    Grade* grades = new Grade[2]{g1, g2};
    Student s1(243, "Shahzod", "Tashev", grades, 2);
    int groups = [1, 2, 3, 4, 5];
    Teacher t1(007, "Sarvar", "ya xz", 02, "i.t. IT", groups);
    t1.show_all();
    //s1.Log();

    delete[] grades;
    return 0;
}