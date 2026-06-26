#pragma once
#include <string>
using namespace std;

struct DeptInfo {
    string id;
    string name;
};

class Department {
private:
    DeptInfo info;

public:
    Department(string id = "", string name = "");
    void setDepartmentID(const string& id);
    void setDepartmentName(const string& name);
    string getDepartmentID() const;
    string getDepartmentName() const;
    void display() const;
};