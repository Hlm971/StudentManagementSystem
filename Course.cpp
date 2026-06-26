#include "Course.h"

Course::Course(string cId, string sId, string semId, string lId, int max)
    : courseId(cId), subjectId(sId), semesterId(semId), lecturerId(lId), maxStudents(max) {
}

void Course::setCourseId(const string& id) { courseId = id; }
void Course::setSubjectId(const string& id) { subjectId = id; }
void Course::setSemesterId(const string& id) { semesterId = id; }
void Course::setLecturerId(const string& id) { lecturerId = id; }
void Course::setMaxStudents(int max) { maxStudents = max; }

string Course::getCourseId() const { return courseId; }
string Course::getSubjectId() const { return subjectId; }
string Course::getSemesterId() const { return semesterId; }
string Course::getLecturerId() const { return lecturerId; }
int Course::getMaxStudents() const { return maxStudents; }

void Course::display() const {
    cout << "Course ID: " << courseId
        << " | Subject: " << subjectId
        << " | Semester: " << semesterId
        << " | Lecturer: " << lecturerId
        << " | Max: " << maxStudents;
}