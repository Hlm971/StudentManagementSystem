#include "Enrollment.h"

Enrollment::Enrollment(string eId, string sId, string cId, string date)
    : enrollmentId(eId), studentId(sId), courseId(cId), enrollDate(date) {
}

void Enrollment::setEnrollmentId(const string& id) { enrollmentId = id; }
void Enrollment::setStudentId(const string& id) { studentId = id; }
void Enrollment::setCourseId(const string& id) { courseId = id; }
void Enrollment::setEnrollDate(const string& date) { enrollDate = date; }

string Enrollment::getEnrollmentId() const { return enrollmentId; }
string Enrollment::getStudentId() const { return studentId; }
string Enrollment::getCourseId() const { return courseId; }
string Enrollment::getEnrollDate() const { return enrollDate; }

void Enrollment::display() const {
    cout << "Enrollment ID: " << enrollmentId
        << " | Student: " << studentId
        << " | Course: " << courseId
        << " | Date: " << enrollDate;
}