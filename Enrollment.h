#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include <string>
#include <iostream>
using namespace std;

class Enrollment {
private:
    string enrollmentId;
    string studentId;
    string courseId;
    string enrollDate;
public:
    Enrollment(string eId = "", string sId = "", string cId = "", string date = "");
    void setEnrollmentId(const string& id);
    void setStudentId(const string& id);
    void setCourseId(const string& id);
    void setEnrollDate(const string& date);
    string getEnrollmentId() const;
    string getStudentId() const;
    string getCourseId() const;
    string getEnrollDate() const;
    void display() const;
};

#endif