#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
using namespace std;

class Course {
private:
    string courseId;
    string subjectId;
    string semesterId;
    string lecturerId;
    int maxStudents;
public:
    Course(string cId = "", string sId = "", string semId = "", string lId = "", int max = 0);
    void setCourseId(const string& id);
    void setSubjectId(const string& id);
    void setSemesterId(const string& id);
    void setLecturerId(const string& id);
    void setMaxStudents(int max);
    string getCourseId() const;
    string getSubjectId() const;
    string getSemesterId() const;
    string getLecturerId() const;
    int getMaxStudents() const;
    void display() const;
};

#endif