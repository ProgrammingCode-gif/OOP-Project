#include <iostream>
#include "People.h"
#include "other.h"
using namespace std;


int main() {
    


    Grade g01(1, "OOP", 100, "21.04.25");//первое цифра это какой ученик, вторая это какая оценка по счету
    Grade g02(2, "Calculus", 99, "21.03.25");
    Grade g03(3, "Physics", 98, "21.02.25");
    Grade g04(4, "AE", 97, "21.01.25");
    Grade g11(1, "OOP", 96, "21.04.25");
    Grade g12(2, "Calculus", 95, "21.03.25");
    Grade g13(3, "Physics", 94, "21.02.25");
    Grade g14(4, "AE", 93, "21.01.25");
    Grade g21(1, "OOP", 92, "21.04.25");
    Grade g22(2, "Calculus", 91, "21.03.25");
    Grade g23(3, "Physics", 90, "21.02.25");
    Grade g24(4, "AE", 89, "21.01.25");
    Grade g31(1, "OOP", 88, "21.04.25");
    Grade g32(2, "Calculus", 87, "21.03.25");
    Grade g33(3, "Physics", 86, "21.02.25");
    Grade g34(4, "AE", 85, "21.01.25");
    
    Grade* grades0 = new Grade[4]{g01, g02, g03, g04};
    Grade* grades1 = new Grade[4]{g11, g12, g13, g14};
    Grade* grades2 = new Grade[4]{g21, g22, g23, g24};
    Grade* grades3 = new Grade[4]{g31, g32, g33, g34};
    
    Student s0(243, "Shahzod", "Tashev", grades0, 4);
    Student s1(250, "Marat", "Turakulov", grades1, 4);
    Student s2(228, "Timur", "Shomuratov", grades2, 4);
    Student s3(237, "Bulat", "Tsoy", grades3, 4);
    Student* students1=new Student[2]{s0,s1};
    Student* students2=new Student[2]{s2,s3};
    
    Group group0(students1,9, 2);
    Group group1(students2,10, 2);
    Group* groupAll=new Group[2]{group0, group1};

    Attendence d1g1s1("21.04.25",group0,1);//d-day g-group s-subject
    Attendence d1g2s1("21.04.25",group1,1);
    Attendence d1g1s2("21.04.25",group0,2);
    Attendence d1g2s2("21.04.25",group1,2);
    Attendence d2g1s1("21.06.25",group0,1);
    Attendence d2g2s1("21.06.25",group1,1);
    Attendence d2g1s2("21.06.25",group0,2);
    Attendence d2g2s2("21.06.25",group1,2);

    Teacher t0(007, "Sarvar", "ya xz", 02, "i.t. IT", groupAll);


    int log_in;
    int choosing;
    cout<<"what you want to be logged in?\n1)Admin\n2)Teacher\n3)Student\nEnter:";
    cin>>log_in;
    switch(log_in) {
        case 1:
        
        break;
        // case 2:
        // cout<<"Welcome to Eclass, choose group to make changes\n";
        // t0.show_all_groups();
        // cin>>choosing;
        //     switch (choosing)
        //     {
        //     case 0:
                
        //         break;
            
        //     default:
        //         break;
        //     }
        // break;
        case 3:
        cout<<"Welcome to Eclass, choose course you want check\n1)Objective Oriented Programming\n2)Calculus\n3)Physics\n4)Academic English\nEnter:";
        cin>>choosing;    
            switch (choosing)
            {
                case 1://oop
                    cout<<"What you want to check for this course?\n1)Marks\n2)Attendence\nEnter:";
                    cin>>choosing;    
                    switch (choosing)
                    {
                    case 1:
                    s1.get_OOP_Grades();//потом надо будет сделать flexible под любого студента через log_in

                    
                    break;
                    case 2:
                    
                    break;
                    default:
                    cout<<"Wrong!";
                        break;
                    }
                break;
                case 2://calc
                    cout<<"What you want to check for this course?\n1)Marks\n2)Attendence\nEnter:";
                    cin>>choosing;   
                    switch (choosing)
                    {
                    case 1:
                    s1.get_calc_Grades();

                    
                    break;
                    case 2:
                    
                    break;
                    default:
                    cout<<"Wrong!";
                        break;
                    } 
                break;
                case 3://phys
                    cout<<"What you want to check for this course?\n1)Marks\n2)Attendence";
                    cin>>choosing;   
                    switch (choosing)
                    {
                    case 1:
                    s1.get_phys_Grades();

                    
                    break;
                    case 2:
                    
                    break;
                    default:
                    cout<<"Wrong!";
                        break;
                    } 
                case 4://AE
                    cout<<"What you want to check for this course?\n1)Marks\n2)Attendence";
                    cin>>choosing;   
                    switch (choosing)
                    {
                    case 1:
                    s1.get_AE_Grades();

                    
                    break;
                    case 2:
                    
                    break;
                    default:
                    cout<<"Wrong!";
                        break;
                    } 
                
                break;//ae
        
        default:
        cout<<"Wrong!";
            break;
        }        
          break;
        default:
          cout<<"Wrong!";
      };
    // t0.show_all();
    // s1.Log();
    // group1.log();
    //  t0.choose_group(2);
    delete[] grades1;
    delete[] grades2;
    delete[] students1;
    return 0;
}