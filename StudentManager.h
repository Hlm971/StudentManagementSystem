#pragma once
#include <vector>
#include <string>
#include "Student.h"
using namespace std;

class StudentManager
{
private:
    vector<Student> students;
public:
    void addStudent(const Student& s);
    bool removeStudent(const string& id);
    Student* findStudent(const string& id);
    const Student* findStudent(const string& id) const;
    bool updateStudent(const string& id, const Student& s);
    void showAllStudents() const;
    bool isStudentExist(const string& id) const;
    vector<Student>& getStudents();
    const vector<Student>& getStudents() const;
};
