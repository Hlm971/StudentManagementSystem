#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
using namespace std;

class Student : public Person {
private:
    double gpa;
    string major;
public:
    Student(string id = "", string name = "", string major = "", double gpa = 0.0);
    void setGPA(double g);
    void setMajor(const string& m);
    double getGPA() const;
    string getMajor() const;
    void display() const override;
};

#endif