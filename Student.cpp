#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string id, string name, string major, double gpa)
    : Person(id, name), major(major), gpa(gpa) {
}

void Student::setGPA(double g) { gpa = g; }
void Student::setMajor(const string& m) { major = m; }
double Student::getGPA() const { return gpa; }
string Student::getMajor() const { return major; }

void Student::display() const {
    cout << "ID: " << id << " | Name: " << name << " | Major: " << major << " | GPA: " << gpa;
}