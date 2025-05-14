#pragma once

#include "Student.h"
#include "Group.h"
#include "Attendence.h"
#include <string>

void handle_course(Student &student, Attendence *attendenceArray, int subjectId, const std::string &courseName);

void add_grade(Student &stud, int newSubjectId, const std::string &newSubjectName, int newScore, const std::string &newDate);

void add_grade2(Group &group);

void read_student(std::fstream &file, Student &student, Grade *grades, int gradeCount);

void loadAllGrades(Grade **allGrades, int gradeCount, int studentCount);