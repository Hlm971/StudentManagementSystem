#pragma once
#include "Person.h"

struct LecturerInfo {
    string title;
    string departmentID;
};

class Lecturer : public Person {
private:
    LecturerInfo info; 

public:
    Lecturer(string id = "", string name = "", string title = "", string deptID = "");

    void setTitle(const string& title);
    void setDepartmentID(const string& deptID);

    string getTitle() const;
    string getDepartmentID() const;

    void display() const override;
};