#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Course.h"
#include "Subject.h"
#include "Department.h"
#include "Lecturer.h"
#include "Enrollment.h"
#include "Grade.h"
#include "Attendance.h"
#include "Student.h"

using namespace std;

// Lớp Semester (giữ nguyên)
class Semester {
private:
    string id;
    string name;
public:
    Semester(string i = "", string n = "") : id(i), name(n) {}
    void setSemesterID(const string& i) { id = i; }
    void setSemesterName(const string& n) { name = n; }
    string getSemesterID() const { return id; }
    string getSemesterName() const { return name; }
    void display() const {
        cout << "Semester ID: " << id << " | Name: " << name;
    }
};

class CourseManager {
private:
    vector<Course> courses;
    vector<Subject> subjects;
    vector<Semester> semesters;
    vector<Department> departments;
    vector<Lecturer> lecturers;
    vector<Enrollment> enrollments;
    vector<Grade> grades;
    vector<Attendance> attendances;

public:
    // Course
    void addCourse(const Course& c);
    bool removeCourse(const string& courseID);
    Course* findCourse(const string& courseID);
    const Course* findCourse(const string& courseID) const;
    void showAllCourses() const;
    vector<Course>& getCourses();
    const vector<Course>& getCourses() const;

    // Subject
    void addSubject(const Subject& s);
    bool removeSubject(const string& subjectID);
    Subject* findSubject(const string& subjectID);
    const Subject* findSubject(const string& subjectID) const;
    void showAllSubjects() const;
    vector<Subject>& getSubjects();
    const vector<Subject>& getSubjects() const;

    // Semester
    void addSemester(const Semester& s);
    bool removeSemester(const string& semesterID);
    Semester* findSemester(const string& semesterID);
    const Semester* findSemester(const string& semesterID) const;
    void showAllSemesters() const;
    vector<Semester>& getSemesters();
    const vector<Semester>& getSemesters() const;

    // Department
    void addDepartment(const Department& d);
    bool removeDepartment(const string& departmentID);
    Department* findDepartment(const string& departmentID);
    const Department* findDepartment(const string& departmentID) const;
    void showAllDepartments() const;
    vector<Department>& getDepartments();
    const vector<Department>& getDepartments() const;

    // Lecturer
    void addLecturer(const Lecturer& l);
    bool removeLecturer(const string& lecturerID);
    Lecturer* findLecturer(const string& lecturerID);
    const Lecturer* findLecturer(const string& lecturerID) const;
    void showAllLecturers() const;
    vector<Lecturer>& getLecturers();
    const vector<Lecturer>& getLecturers() const;

    // Enrollment
    void addEnrollment(const Enrollment& e);
    bool removeEnrollment(const string& enrollmentID);
    Enrollment* findEnrollment(const string& enrollmentID);
    const Enrollment* findEnrollment(const string& enrollmentID) const;
    void showAllEnrollments() const;
    vector<Enrollment>& getEnrollments();
    const vector<Enrollment>& getEnrollments() const;

    // Grade - dùng Student* và courseID để xác định duy nhất
    void addGrade(const Grade& g);
    bool removeGrade(Student* student, const string& courseID);
    Grade* findGrade(Student* student, const string& courseID);
    const Grade* findGrade(Student* student, const string& courseID) const;
    void showAllGrades() const;
    vector<Grade>& getGrades();
    const vector<Grade>& getGrades() const;

    // Attendance - dùng Student* và courseID để xác định duy nhất
    void addAttendance(const Attendance& a);
    bool removeAttendance(Student* student, const string& courseID);
    Attendance* findAttendance(Student* student, const string& courseID);
    const Attendance* findAttendance(Student* student, const string& courseID) const;
    void showAllAttendances() const;
    vector<Attendance>& getAttendances();
    const vector<Attendance>& getAttendances() const;
};