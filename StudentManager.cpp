#include "StudentManager.h"
#include <iostream>
using namespace std;

void StudentManager::addStudent(const Student& s)
{
    if (!isStudentExist(s.getID()))
        students.push_back(s);
}

bool StudentManager::removeStudent(const string& id)
{
    for (size_t i = 0; i < students.size(); ++i)
    {
        if (students[i].getID() == id)
        {
            students.erase(students.begin() + i);
            return true;
        }
    }
    return false;
}

Student* StudentManager::findStudent(const string& id)
{
    for (size_t i = 0; i < students.size(); ++i)
        if (students[i].getID() == id) return &students[i];
    return 0;
}

const Student* StudentManager::findStudent(const string& id) const
{
    for (size_t i = 0; i < students.size(); ++i)
        if (students[i].getID() == id) return &students[i];
    return 0;
}

bool StudentManager::updateStudent(const string& id, const Student& s)
{
    Student* p = findStudent(id);
    if (p)
    {
        *p = s;
        return true;
    }
    return false;
}

void StudentManager::showAllStudents() const
{
    cout << "\n===== STUDENT LIST =====\n";
    if (students.empty()) { cout << "Empty.\n"; return; }
    for (size_t i = 0; i < students.size(); ++i)
    {
        students[i].display();
        cout << endl;
    }
}

bool StudentManager::isStudentExist(const string& id) const
{
    return findStudent(id) != 0;
}

vector<Student>& StudentManager::getStudents() { return students; }
const vector<Student>& StudentManager::getStudents() const { return students; }
