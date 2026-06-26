#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// ---- Students ----
void FileManager::saveStudents(const vector<Student>& students, const string& filename) const {
    ofstream fout(filename.c_str());
    if (!fout) { cerr << "Cannot open " << filename << " for writing.\n"; return; }
    for (const auto& s : students)
        fout << s.getID() << '|' << s.getName() << '|' << s.getMajor() << '|' << s.getGPA() << '\n';
    fout.close();
}

void FileManager::loadStudents(vector<Student>& students, const string& filename) const {
    ifstream fin(filename.c_str());
    if (!fin) { cerr << "Cannot open " << filename << " for reading.\n"; return; }
    students.clear();
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        string id, name, major, gpaStr;
        stringstream ss(line);
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, major, '|');
        getline(ss, gpaStr);
        double gpa = 0;
        stringstream(gpaStr) >> gpa;
        students.push_back(Student(id, name, major, gpa));
    }
    fin.close();
}

// ---- Courses ----
void FileManager::saveCourses(const vector<Course>& courses, const string& filename) const {
    ofstream fout(filename.c_str());
    if (!fout) { cerr << "Cannot open " << filename << " for writing.\n"; return; }
    for (const auto& c : courses)
        fout << c.getCourseId() << '|' << c.getSubjectId() << '|'
        << c.getSemesterId() << '|' << c.getLecturerId() << '|' << c.getMaxStudents() << '\n';
    fout.close();
}

void FileManager::loadCourses(vector<Course>& courses, const string& filename) const {
    ifstream fin(filename.c_str());
    if (!fin) { cerr << "Cannot open " << filename << " for reading.\n"; return; }
    courses.clear();
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        string cId, sId, semId, lId, maxStr;
        stringstream ss(line);
        getline(ss, cId, '|');
        getline(ss, sId, '|');
        getline(ss, semId, '|');
        getline(ss, lId, '|');
        getline(ss, maxStr);
        int max = 0;
        stringstream(maxStr) >> max;
        courses.push_back(Course(cId, sId, semId, lId, max));
    }
    fin.close();
}

// ---- Subjects ----
void FileManager::saveSubjects(const vector<Subject>& subjects, const string& filename) const {
    ofstream fout(filename.c_str());
    if (!fout) { cerr << "Cannot open " << filename << " for writing.\n"; return; }
    for (const auto& s : subjects)
        fout << s.getSubjectId() << '|' << s.getSubjectName() << '|' << s.getCredits() << '\n';
    fout.close();
}

void FileManager::loadSubjects(vector<Subject>& subjects, const string& filename) const {
    ifstream fin(filename.c_str());
    if (!fin) { cerr << "Cannot open " << filename << " for reading.\n"; return; }
    subjects.clear();
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        string id, name, credStr;
        stringstream ss(line);
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, credStr);
        int cred = 0;
        stringstream(credStr) >> cred;
        subjects.push_back(Subject(id, name, cred));
    }
    fin.close();
}

// ---- Enrollments ----
void FileManager::saveEnrollments(const vector<Enrollment>& enrollments, const string& filename) const {
    ofstream fout(filename.c_str());
    if (!fout) { cerr << "Cannot open " << filename << " for writing.\n"; return; }
    for (const auto& e : enrollments)
        fout << e.getEnrollmentId() << '|' << e.getStudentId() << '|'
        << e.getCourseId() << '|' << e.getEnrollDate() << '\n';
    fout.close();
}

void FileManager::loadEnrollments(vector<Enrollment>& enrollments, const string& filename) const {
    ifstream fin(filename.c_str());
    if (!fin) { cerr << "Cannot open " << filename << " for reading.\n"; return; }
    enrollments.clear();
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        string eId, sId, cId, date;
        stringstream ss(line);
        getline(ss, eId, '|');
        getline(ss, sId, '|');
        getline(ss, cId, '|');
        getline(ss, date);
        enrollments.push_back(Enrollment(eId, sId, cId, date));
    }
    fin.close();
}

// ---- Grades ----
void FileManager::saveGrades(const vector<Grade>& grades, const string& filename) const {
    ofstream fout(filename.c_str());
    if (!fout) { cerr << "Cannot open " << filename << " for writing.\n"; return; }
    for (const auto& g : grades) {
        Student* stu = g.getStudent();
        string studentID = (stu ? stu->getID() : "");
        fout << studentID << '|' << g.getCourseID() << '|' << g.getScore() << '\n';
    }
    fout.close();
}

void FileManager::loadGrades(vector<Grade>& grades, const string& filename) const {
    ifstream fin(filename.c_str());
    if (!fin) { cerr << "Cannot open " << filename << " for reading.\n"; return; }
    grades.clear();
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        string studentID, courseID, scoreStr;
        stringstream ss(line);
        getline(ss, studentID, '|');
        getline(ss, courseID, '|');
        getline(ss, scoreStr);
        double score = 0;
        stringstream(scoreStr) >> score;
        grades.push_back(Grade(nullptr, courseID, score));
    }
}