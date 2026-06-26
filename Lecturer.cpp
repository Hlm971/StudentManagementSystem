#include "Lecturer.h"
#include <iostream>

Lecturer::Lecturer(string id, string name, string title, string deptID)
    : Person(id, name) {
    info.title = title;
    info.departmentID = deptID;
}

void Lecturer::setTitle(const string& title) { info.title = title; }
void Lecturer::setDepartmentID(const string& deptID) { info.departmentID = deptID; }

string Lecturer::getTitle() const { return info.title; }
string Lecturer::getDepartmentID() const { return info.departmentID; }

void Lecturer::display() const {
    cout << "ID: " << id << " | Name: " << name
        << " | Title: " << info.title
        << " | Dept: " << info.departmentID << endl;
}