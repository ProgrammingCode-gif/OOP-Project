#include <iostream>
#include "People.h"

using namespace std;

int main() {
    Grade g1(1, "Calculus", 100);
    Grade g2(2, "OOP", 100);
    Grade* grades = new Grade[2]{g1, g2};
    Student s1(243, "Shahzod", "Tashev", grades, 2);

    s1.Log();

    delete[] grades;
    return 0;
}