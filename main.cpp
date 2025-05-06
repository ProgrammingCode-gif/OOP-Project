#include <iostream>
#include "People.h"
#include "other.h"

using namespace std;

int main() {
    Grade g01(1, "Calculus", 99, "20.03.25");//первое цифра это какой ученик, вторая это какая оценка по счету
    Grade g02(2, "OOP", 99, "21.04.25");
    Grade g11(1, "Calculus", 98, "18.03.25");
    Grade g12(2, "OOP", 98, "19.04.25");
    Grade g21(1, "Calculus", 97, "18.03.25");
    Grade g22(2, "OOP", 97, "19.04.25");
    Grade g31(1, "Calculus", 96, "18.03.25");
    Grade g32(2, "OOP", 96, "19.04.25");

    Grade* grades0 = new Grade[2]{g01, g02};
    Grade* grades1 = new Grade[2]{g11, g12};
    Grade* grades2 = new Grade[2]{g21, g22};
    Grade* grades3 = new Grade[2]{g31, g32};

    Student s0(243, "Shahzod", "Tashev", grades0, 2);
    Student s1(250, "Marat", "Turakulov", grades1, 2);
    Student s2(228, "Timur", "Shomuratov", grades2, 2);
    Student s3(237, "Bulat", "Tsoy", grades3, 2);
    Student* students1=new Student[2]{s0,s1};
    Student* students2=new Student[2]{s2,s3};

    Group group0(students1, 2);
    Group group1(students2, 2);
    Group* groupAll=new Group[2]{group0, group1};
    Teacher t0(007, "Sarvar", "ya xz", 02, "i.t. IT", groupAll);
    //t1.show_all();
    s1.Log();
    //group1.log();
    t0.choose_group(2);
    delete[] grades1;
    delete[] grades2;
    delete[] students1;
    return 0;
}