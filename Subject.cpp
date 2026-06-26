#include "Subject.h"

Subject::Subject() : subjectId(""), subjectName(""), credits(0) {}
Subject::Subject(string id, string name, int cred) : subjectId(id), subjectName(name), credits(cred) {}

void Subject::setSubjectId(const string& id) { subjectId = id; }
void Subject::setSubjectName(const string& name) { subjectName = name; }
void Subject::setCredits(int c) { credits = c; }
string Subject::getSubjectId() const { return subjectId; }
string Subject::getSubjectName() const { return subjectName; }
int Subject::getCredits() const { return credits; }

void Subject::display() const {
    cout << "Subject ID: " << subjectId << " | Name: " << subjectName << " | Credits: " << credits;
}