#include "CourseManager.h"
#include <algorithm>

// ==================== Course ====================
void CourseManager::addCourse(const Course& c) {
    if (findCourse(c.getCourseId()) == nullptr)
        courses.push_back(c);
}
bool CourseManager::removeCourse(const string& courseID) {
    for (size_t i = 0; i < courses.size(); ++i)
        if (courses[i].getCourseId() == courseID) {
            courses.erase(courses.begin() + i);
            return true;
        }
    return false;
}
Course* CourseManager::findCourse(const string& courseID) {
    for (auto& c : courses)
        if (c.getCourseId() == courseID) return &c;
    return nullptr;
}
const Course* CourseManager::findCourse(const string& courseID) const {
    for (const auto& c : courses)
        if (c.getCourseId() == courseID) return &c;
    return nullptr;
}
void CourseManager::showAllCourses() const {
    cout << "\n===== COURSE LIST =====\n";
    if (courses.empty()) { cout << "Empty.\n"; return; }
    for (const auto& c : courses) {
        c.display();
        cout << endl;
    }
}
vector<Course>& CourseManager::getCourses() { return courses; }
const vector<Course>& CourseManager::getCourses() const { return courses; }

// ==================== Subject ====================
void CourseManager::addSubject(const Subject& s) {
    if (findSubject(s.getSubjectId()) == nullptr)
        subjects.push_back(s);
}
bool CourseManager::removeSubject(const string& subjectID) {
    for (size_t i = 0; i < subjects.size(); ++i)
        if (subjects[i].getSubjectId() == subjectID) {
            subjects.erase(subjects.begin() + i);
            return true;
        }
    return false;
}
Subject* CourseManager::findSubject(const string& subjectID) {
    for (auto& s : subjects)
        if (s.getSubjectId() == subjectID) return &s;
    return nullptr;
}
const Subject* CourseManager::findSubject(const string& subjectID) const {
    for (const auto& s : subjects)
        if (s.getSubjectId() == subjectID) return &s;
    return nullptr;
}
void CourseManager::showAllSubjects() const {
    cout << "\n===== SUBJECT LIST =====\n";
    if (subjects.empty()) { cout << "Empty.\n"; return; }
    for (const auto& s : subjects) {
        s.display();
        cout << endl;
    }
}
vector<Subject>& CourseManager::getSubjects() { return subjects; }
const vector<Subject>& CourseManager::getSubjects() const { return subjects; }

// ==================== Semester ====================
void CourseManager::addSemester(const Semester& s) {
    if (findSemester(s.getSemesterID()) == nullptr)
        semesters.push_back(s);
}
bool CourseManager::removeSemester(const string& semesterID) {
    for (size_t i = 0; i < semesters.size(); ++i)
        if (semesters[i].getSemesterID() == semesterID) {
            semesters.erase(semesters.begin() + i);
            return true;
        }
    return false;
}
Semester* CourseManager::findSemester(const string& semesterID) {
    for (auto& s : semesters)
        if (s.getSemesterID() == semesterID) return &s;
    return nullptr;
}
const Semester* CourseManager::findSemester(const string& semesterID) const {
    for (const auto& s : semesters)
        if (s.getSemesterID() == semesterID) return &s;
    return nullptr;
}
void CourseManager::showAllSemesters() const {
    cout << "\n===== SEMESTER LIST =====\n";
    if (semesters.empty()) { cout << "Empty.\n"; return; }
    for (const auto& s : semesters) {
        s.display();
        cout << endl;
    }
}
vector<Semester>& CourseManager::getSemesters() { return semesters; }
const vector<Semester>& CourseManager::getSemesters() const { return semesters; }

// ==================== Department ====================
void CourseManager::addDepartment(const Department& d) {
    if (findDepartment(d.getDepartmentID()) == nullptr)
        departments.push_back(d);
}
bool CourseManager::removeDepartment(const string& departmentID) {
    for (size_t i = 0; i < departments.size(); ++i)
        if (departments[i].getDepartmentID() == departmentID) {
            departments.erase(departments.begin() + i);
            return true;
        }
    return false;
}
Department* CourseManager::findDepartment(const string& departmentID) {
    for (auto& d : departments)
        if (d.getDepartmentID() == departmentID) return &d;
    return nullptr;
}
const Department* CourseManager::findDepartment(const string& departmentID) const {
    for (const auto& d : departments)
        if (d.getDepartmentID() == departmentID) return &d;
    return nullptr;
}
void CourseManager::showAllDepartments() const {
    cout << "\n===== DEPARTMENT LIST =====\n";
    if (departments.empty()) { cout << "Empty.\n"; return; }
    for (const auto& d : departments) {
        d.display();
        cout << endl;
    }
}
vector<Department>& CourseManager::getDepartments() { return departments; }
const vector<Department>& CourseManager::getDepartments() const { return departments; }

// ==================== Lecturer ====================
void CourseManager::addLecturer(const Lecturer& l) {
    if (findLecturer(l.getID()) == nullptr)
        lecturers.push_back(l);
}
bool CourseManager::removeLecturer(const string& lecturerID) {
    for (size_t i = 0; i < lecturers.size(); ++i)
        if (lecturers[i].getID() == lecturerID) {
            lecturers.erase(lecturers.begin() + i);
            return true;
        }
    return false;
}
Lecturer* CourseManager::findLecturer(const string& lecturerID) {
    for (auto& l : lecturers)
        if (l.getID() == lecturerID) return &l;
    return nullptr;
}
const Lecturer* CourseManager::findLecturer(const string& lecturerID) const {
    for (const auto& l : lecturers)
        if (l.getID() == lecturerID) return &l;
    return nullptr;
}
void CourseManager::showAllLecturers() const {
    cout << "\n===== LECTURER LIST =====\n";
    if (lecturers.empty()) { cout << "Empty.\n"; return; }
    for (const auto& l : lecturers) {
        l.display();
        cout << endl;
    }
}
vector<Lecturer>& CourseManager::getLecturers() { return lecturers; }
const vector<Lecturer>& CourseManager::getLecturers() const { return lecturers; }

// ==================== Enrollment ====================
void CourseManager::addEnrollment(const Enrollment& e) {
    if (findEnrollment(e.getEnrollmentId()) == nullptr)
        enrollments.push_back(e);
}
bool CourseManager::removeEnrollment(const string& enrollmentID) {
    for (size_t i = 0; i < enrollments.size(); ++i)
        if (enrollments[i].getEnrollmentId() == enrollmentID) {
            enrollments.erase(enrollments.begin() + i);
            return true;
        }
    return false;
}
Enrollment* CourseManager::findEnrollment(const string& enrollmentID) {
    for (auto& e : enrollments)
        if (e.getEnrollmentId() == enrollmentID) return &e;
    return nullptr;
}
const Enrollment* CourseManager::findEnrollment(const string& enrollmentID) const {
    for (const auto& e : enrollments)
        if (e.getEnrollmentId() == enrollmentID) return &e;
    return nullptr;
}
void CourseManager::showAllEnrollments() const {
    cout << "\n===== ENROLLMENT LIST =====\n";
    if (enrollments.empty()) { cout << "Empty.\n"; return; }
    for (const auto& e : enrollments) {
        e.display();
        cout << endl;
    }
}
vector<Enrollment>& CourseManager::getEnrollments() { return enrollments; }
const vector<Enrollment>& CourseManager::getEnrollments() const { return enrollments; }

// ==================== Grade ====================
void CourseManager::addGrade(const Grade& g) {
    // Kiểm tra xem đã có Grade cho Student* và courseID này chưa
    Student* stu = g.getStudent();
    string cid = g.getCourseID();
    if (findGrade(stu, cid) == nullptr)
        grades.push_back(g);
}

bool CourseManager::removeGrade(Student* student, const string& courseID) {
    for (size_t i = 0; i < grades.size(); ++i) {
        if (grades[i].getStudent() == student && grades[i].getCourseID() == courseID) {
            grades.erase(grades.begin() + i);
            return true;
        }
    }
    return false;
}

Grade* CourseManager::findGrade(Student* student, const string& courseID) {
    for (auto& g : grades)
        if (g.getStudent() == student && g.getCourseID() == courseID)
            return &g;
    return nullptr;
}

const Grade* CourseManager::findGrade(Student* student, const string& courseID) const {
    for (const auto& g : grades)
        if (g.getStudent() == student && g.getCourseID() == courseID)
            return &g;
    return nullptr;
}

void CourseManager::showAllGrades() const {
    cout << "\n===== GRADE LIST =====\n";
    if (grades.empty()) { cout << "Empty.\n"; return; }
    for (const auto& g : grades) {
        g.display();
        cout << endl;
    }
}

vector<Grade>& CourseManager::getGrades() { return grades; }
const vector<Grade>& CourseManager::getGrades() const { return grades; }

// ==================== Attendance ====================
void CourseManager::addAttendance(const Attendance& a) {
    Student* stu = a.getStudent();
    string cid = a.getCourseID();
    if (findAttendance(stu, cid) == nullptr)
        attendances.push_back(a);
}

bool CourseManager::removeAttendance(Student* student, const string& courseID) {
    for (size_t i = 0; i < attendances.size(); ++i) {
        if (attendances[i].getStudent() == student && attendances[i].getCourseID() == courseID) {
            attendances.erase(attendances.begin() + i);
            return true;
        }
    }
    return false;
}

Attendance* CourseManager::findAttendance(Student* student, const string& courseID) {
    for (auto& a : attendances)
        if (a.getStudent() == student && a.getCourseID() == courseID)
            return &a;
    return nullptr;
}

const Attendance* CourseManager::findAttendance(Student* student, const string& courseID) const {
    for (const auto& a : attendances)
        if (a.getStudent() == student && a.getCourseID() == courseID)
            return &a;
    return nullptr;
}

void CourseManager::showAllAttendances() const {
    cout << "\n===== ATTENDANCE LIST =====\n";
    if (attendances.empty()) { cout << "Empty.\n"; return; }
    for (const auto& a : attendances) {
        a.display();
        cout << endl;
    }
}

vector<Attendance>& CourseManager::getAttendances() { return attendances; }
const vector<Attendance>& CourseManager::getAttendances() const { return attendances; }