#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Grade
{
    int subjectId;
    string subjectName;
    int score;
    string date;

public:
    Grade() {};
    Grade(int newSubjectId, string newSubjectName, int newScore, string newDate)
    {
        subjectId = newSubjectId;
        subjectName = newSubjectName;
        score = newScore;
        date = newDate;
    }
    void Log()// выводит информацию о оценке
    {
        cout << subjectName << " - " << score << " - " << date << endl;
    }
    void set_data(int newSubjectId, string newSubjectName, int newScore, string newDate)
    {
        subjectId = newSubjectId;
        subjectName = newSubjectName;
        score = newScore;
        date = newDate;
    }
    int get_subj_ID()// возвращает ID предмета
    {
        return subjectId;
    }
    void read_data(fstream &file)
    {
        file.read((char*)&subjectId, sizeof(subjectId));
        file.read((char*)&score, sizeof(score));

        subjectName = read_string(file);  // Read the subject name string
        date = read_string(file);  // Read the date string
    }
    // void write_data(fstream &file) {
    //     file.write((char*)&subjectId, sizeof(subjectId));
    //     file.write((char*)&score, sizeof(score));
    //     write_string(file, subjectName);
    //     write_string(file, date);
    // }
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
    // void write_string(fstream &file, string &str) {
    //     int len = str.length();
    //     file.write((char*)&len, sizeof(len));
    //     file.write(str.c_str(), len);
    // }
};