#pragma once
#include <string>
#include <iostream>
#include "Student.h"

using namespace std;

class Grade
{
private:
    Student* student;
    string courseID;
    double score;

public:
    Grade(Student* student = nullptr, string courseID = "", double score = 0.0);

    void setStudent(Student* student);
    void setCourseID(const string& id);
    void setScore(double score);

    Student* getStudent() const;
    string getCourseID() const;
    double getScore() const;
    
    string getLetterGrade() const; 

    void display() const;
};