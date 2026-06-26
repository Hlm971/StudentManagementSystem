#pragma once
#include <string>
#include <iostream>
#include "Student.h"

using namespace std;

class Attendance
{
private:
    Student* student;
    string courseID;
    string date; 
    bool isPresent; 

public:
    Attendance(Student* student = nullptr, string courseID = "", string date = "", bool isPresent = false);

    void setStudent(Student* student);
    void setCourseID(const string& id);
    void setDate(const string& date);
    void setStatus(bool isPresent);

    Student* getStudent() const;
    string getCourseID() const;
    string getDate() const;
    bool getStatus() const;

    void display() const;
};