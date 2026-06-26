#include "Department.h"
#include <iostream>

Department::Department(string id, string name) {
    info.id = id;
    info.name = name;
}

void Department::setDepartmentID(const string& id) { info.id = id; }
void Department::setDepartmentName(const string& name) { info.name = name; }
string Department::getDepartmentID() const { return info.id; }
string Department::getDepartmentName() const { return info.name; }

void Department::display() const {
    cout << "Department ID: " << info.id << " | Name: " << info.name << endl;
}
