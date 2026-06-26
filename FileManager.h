#pragma once
#include <string>
#include <vector>
#include "Student.h"
#include "Course.h"
#include "Subject.h"
#include "Enrollment.h"
#include "Grade.h"
#include "Attendance.h"
using namespace std;

class FileManager {
public:
    // Students
    void saveStudents(const vector<Student>& students, const string& filename = "students.txt") const;
    void loadStudents(vector<Student>& students, const string& filename = "students.txt") const;

    // Courses
    void saveCourses(const vector<Course>& courses, const string& filename = "courses.txt") const;
    void loadCourses(vector<Course>& courses, const string& filename = "courses.txt") const;

    // Subjects
    void saveSubjects(const vector<Subject>& subjects, const string& filename = "subjects.txt") const;
    void loadSubjects(vector<Subject>& subjects, const string& filename = "subjects.txt") const;

    // Enrollments
    void saveEnrollments(const vector<Enrollment>& enrollments, const string& filename = "enrollments.txt") const;
    void loadEnrollments(vector<Enrollment>& enrollments, const string& filename = "enrollments.txt") const;

    // Grades (lưu studentID, courseID, score)
    void saveGrades(const vector<Grade>& grades, const string& filename = "grades.txt") const;
    void loadGrades(vector<Grade>& grades, const string& filename = "grades.txt") const;

    // Attendances (lưu studentID, courseID, date, status)
    void saveAttendances(const vector<Attendance>& attendances, const string& filename = "attendances.txt") const;
    void loadAttendances(vector<Attendance>& attendances, const string& filename = "attendances.txt") const;
};