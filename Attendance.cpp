#include "Attendance.h"

Attendance::Attendance(Student* student, string courseID, string date, bool isPresent)
{
    this->student = student;
    this->courseID = courseID;
    this->date = date;
    this->isPresent = isPresent;
}

void Attendance::setStudent(Student* student) { this->student = student; }
void Attendance::setCourseID(const string& id) { courseID = id; }
void Attendance::setDate(const string& date) { this->date = date; }
void Attendance::setStatus(bool isPresent) { this->isPresent = isPresent; }

Student* Attendance::getStudent() const { return student; }
string Attendance::getCourseID() const { return courseID; }
string Attendance::getDate() const { return date; }
bool Attendance::getStatus() const { return isPresent; }

void Attendance::display() const
{
    string id = (student != nullptr) ? student->getID() : "Unknown";

    cout << "Date: " << date 
         << " | Student ID: " << id 
         << " | Course ID: " << courseID 
         << " | Status: " << (isPresent ? "Present" : "Absent");
}