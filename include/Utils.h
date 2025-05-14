#pragma once

#include "Student.h"
#include "Group.h"
#include "Attendence.h"
#include "Teacher.h"
#include <string>

void handle_course(Student &student, Attendence *attendenceArray, int subjectId, const std::string &courseName);

void add_grade(Student &stud, int newSubjectId, const std::string &newSubjectName, int newScore, const std::string &newDate);

void add_grade2(Group &group);

void read_student(std::fstream &file, Student &student, Grade *grades, int gradeCount);

void loadAllGrades(Grade **allGrades, int gradeCount, int studentCount);

void add_attendence(Attendence* attArray, Group *group0, int groupCount);

void teacher_menu(Teacher* allTeachers, Attendence** attendence, Group* groupAll, int person_numb);

void student_menu(Student* students, Attendence* OOP_att, Attendence* Calc_att, Attendence* Phys_att, Attendence* AE_att, Teacher* allTeachers, int person_numb);

