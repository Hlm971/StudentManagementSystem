#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <string>
using namespace std;

class Subject {
private:
    string subjectId;
    string subjectName;
    int credits;
public:
    Subject();
    Subject(string id, string name, int cred);
    void setSubjectId(const string& id);
    void setSubjectName(const string& name);
    void setCredits(int c);
    string getSubjectId() const;
    string getSubjectName() const;
    int getCredits() const;
    void display() const;
};

#endif