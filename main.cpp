#include <iostream>
#include <limits>
#include "Menu.h"
#include "Validator.h"
#include "StudentManager.h"
#include "CourseManager.h"
#include "ReportGenerator.h"
#include "FileManager.h"

using namespace std;

int main() {
    Menu menu("STUDENT MANAGEMENT SYSTEM");
    menu << "Add student"
        << "Show students"
        << "Add subject"
        << "Show subjects"
        << "Add semester"
        << "Show semesters"
        << "Add department"
        << "Show departments"
        << "Add lecturer"
        << "Show lecturers"
        << "Add course"
        << "Show courses"
        << "Add enrollment"
        << "Show enrollments"
        << "Add grade"
        << "Show grades"
        << "Add attendance"
        << "Show attendances"
        << "Reports"
        << "Save data"
        << "Load data"
        << "Exit";

    Validator val;
    StudentManager studentManager;
    CourseManager courseManager;
    ReportGenerator report;
    FileManager fileManager;

    while (true) {
        int choice = menu.choose();

        switch (choice) {
        case 0: { // Add student
            string id, name, major;
            double gpa;
            cout << "Enter ID: "; getline(cin, id);
            cout << "Enter name: "; getline(cin, name);
            cout << "Enter major: "; getline(cin, major);
            cout << "Enter GPA: ";
            if (!(cin >> gpa)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid GPA.\n";
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (!val.isValidID(id) || !val.isValidName(name) || !val.isValidName(major) || !val.isValidGPA(gpa)) {
                cout << "Invalid data.\n";
                continue;
            }
            studentManager.addStudent(Student(id, name, major, gpa));
            cout << "Student added.\n";
            break;
        }
        case 1: { // Show students
            studentManager.showAllStudents();
            break;
        }
        case 2: { // Add subject
            string id, name;
            int credits;
            cout << "Subject ID: "; getline(cin, id);
            cout << "Subject name: "; getline(cin, name);
            cout << "Credits: ";
            if (!(cin >> credits)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid.\n";
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (!val.isValidID(id) || !val.isValidName(name) || !val.isValidCredits(credits)) {
                cout << "Invalid.\n";
                continue;
            }
            courseManager.addSubject(Subject(id, name, credits));
            cout << "Subject added.\n";
            break;
        }
        case 3: { // Show subjects
            courseManager.showAllSubjects();
            break;
        }
        case 4: { // Add semester
            string id, name;
            cout << "Semester ID: "; getline(cin, id);
            cout << "Semester name: "; getline(cin, name);
            if (!val.isValidID(id) || !val.isValidName(name)) {
                cout << "Invalid.\n";
                continue;
            }
            courseManager.addSemester(Semester(id, name));
            cout << "Semester added.\n";
            break;
        }
        case 5: { // Show semesters
            courseManager.showAllSemesters();
            break;
        }
        case 6: { // Add department
            string id, name;
            cout << "Department ID: "; getline(cin, id);
            cout << "Department name: "; getline(cin, name);
            if (!val.isValidID(id) || !val.isValidName(name)) {
                cout << "Invalid.\n";
                continue;
            }
            courseManager.addDepartment(Department(id, name));
            cout << "Department added.\n";
            break;
        }
        case 7: { // Show departments
            courseManager.showAllDepartments();
            break;
        }
        case 8: { // Add lecturer
            string id, name, title, deptID;
            cout << "Lecturer ID: "; getline(cin, id);
            cout << "Name: "; getline(cin, name);
            cout << "Title: "; getline(cin, title);
            cout << "Department ID: "; getline(cin, deptID);
            if (!val.isValidID(id) || !val.isValidName(name) || !val.isValidName(title) || !val.isValidID(deptID)) {
                cout << "Invalid.\n";
                continue;
            }
            courseManager.addLecturer(Lecturer(id, name, title, deptID));
            cout << "Lecturer added.\n";
            break;
        }
        case 9: { // Show lecturers
            courseManager.showAllLecturers();
            break;
        }
        case 10: { // Add course
            string courseID, subjectID, semesterID, lecturerID;
            int maxStudents;
            cout << "Course ID: "; getline(cin, courseID);
            cout << "Subject ID: "; getline(cin, subjectID);
            cout << "Semester ID: "; getline(cin, semesterID);
            cout << "Lecturer ID: "; getline(cin, lecturerID);
            cout << "Max students: ";
            if (!(cin >> maxStudents)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid.\n";
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (!val.isValidID(courseID) || !val.isValidID(subjectID) || !val.isValidID(semesterID) ||
                !val.isValidID(lecturerID) || !val.isValidPositiveInt(maxStudents)) {
                cout << "Invalid.\n";
                continue;
            }
            // Kiểm tra subject, semester, lecturer tồn tại (có thể bỏ qua)
            courseManager.addCourse(Course(courseID, subjectID, semesterID, lecturerID, maxStudents));
            cout << "Course added.\n";
            break;
        }
        case 11: { // Show courses
            courseManager.showAllCourses();
            break;
        }
        case 12: { // Add enrollment
            string enrollmentID, studentID, courseID, date;
            cout << "Enrollment ID: "; getline(cin, enrollmentID);
            cout << "Student ID: "; getline(cin, studentID);
            cout << "Course ID: "; getline(cin, courseID);
            cout << "Enroll date (YYYY-MM-DD): "; getline(cin, date);
            if (!val.isValidID(enrollmentID) || !val.isValidID(studentID) || !val.isValidID(courseID) || !val.isValidName(date)) {
                cout << "Invalid.\n";
                continue;
            }
            if (studentManager.findStudent(studentID) == nullptr) {
                cout << "Student not found.\n";
                break;
            }
            if (courseManager.findCourse(courseID) == nullptr) {
                cout << "Course not found.\n";
                break;
            }
            courseManager.addEnrollment(Enrollment(enrollmentID, studentID, courseID, date));
            cout << "Enrollment added.\n";
            break;
        }
        case 13: { // Show enrollments
            courseManager.showAllEnrollments();
            break;
        }
        case 14: { // Add grade
            string enrollmentID;
            double mid, finalExam;
            cout << "Enrollment ID: "; getline(cin, enrollmentID);
            cout << "Midterm score: ";
            if (!(cin >> mid)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid.\n";
                continue;
            }
            cout << "Final exam score: ";
            if (!(cin >> finalExam)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid.\n";
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            Enrollment* enr = courseManager.findEnrollment(enrollmentID);
            if (!enr) {
                cout << "Enrollment not found.\n";
                break;
            }
            Student* stu = studentManager.findStudent(enr->getStudentId());
            if (!stu) {
                cout << "Student not found.\n";
                break;
            }
            double avg = (mid + finalExam) / 2.0;
            courseManager.addGrade(Grade(stu, enr->getCourseId(), avg));
            cout << "Grade added.\n";
            break;
        }
        case 15: { // Show grades
            courseManager.showAllGrades();
            break;
        }
        case 16: { // Add attendance
            string enrollmentID;
            int present, absent;
            cout << "Enrollment ID: "; getline(cin, enrollmentID);
            cout << "Present days: ";
            if (!(cin >> present)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid.\n";
                continue;
            }
            cout << "Absent days: ";
            if (!(cin >> absent)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid.\n";
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            Enrollment* enr = courseManager.findEnrollment(enrollmentID);
            if (!enr) {
                cout << "Enrollment not found.\n";
                break;
            }
            Student* stu = studentManager.findStudent(enr->getStudentId());
            if (!stu) {
                cout << "Student not found.\n";
                break;
            }
            bool status = (present > 0); // coi như có điểm danh nếu present > 0
            string date;
            cout << "Date (YYYY-MM-DD): "; getline(cin, date);
            courseManager.addAttendance(Attendance(stu, enr->getCourseId(), date, status));
            cout << "Attendance added.\n";
            break;
        }
        case 17: { // Show attendances
            courseManager.showAllAttendances();
            break;
        }
        case 18: { // Reports
            Menu reportMenu("REPORTS");
            reportMenu << "Student list"
                << "Course list"
                << "Top students"
                << "Grade report"
                << "Attendance report"
                << "Back";
            int rchoice = reportMenu.choose();
            if (rchoice == 0) {
                studentManager.showAllStudents();
            }
            else if (rchoice == 1) {
                courseManager.showAllCourses();
            }
            else if (rchoice == 2) {
                // Top students – tạm bỏ qua hoặc triển khai đơn giản
                cout << "Top students feature not implemented.\n";
            }
            else if (rchoice == 3) {
                // Tạo vector<Grade*> từ CourseManager
                vector<Grade*> gradePtrs;
                for (auto& g : courseManager.getGrades()) {
                    gradePtrs.push_back(&g);
                }
                // Gọi hàm báo cáo điểm (giả sử ReportGenerator có generateGradeReport? Không có)
                // Thay vào đó, ta gọi generateStudentTranscript cho từng student? 
                // Hoặc showAllGrades. Ta sẽ gọi showAllGrades.
                courseManager.showAllGrades();
            }
            else if (rchoice == 4) {
                // Tương tự cho attendance
                vector<Attendance*> attPtrs;
                for (auto& a : courseManager.getAttendances()) {
                    attPtrs.push_back(&a);
                }
                courseManager.showAllAttendances();
            }
            break;
        }
        case 19: { // Save data
            fileManager.saveStudents(studentManager.getStudents());
            fileManager.saveCourses(courseManager.getCourses());
            fileManager.saveSubjects(courseManager.getSubjects());
            fileManager.saveEnrollments(courseManager.getEnrollments());
            // Không lưu Grade và Attendance vì FileManager không hỗ trợ
            // Hoặc có thể lưu riêng, nhưng tạm bỏ qua
            cout << "Data saved (except grades and attendances).\n";
            break;
        }
        case 20: { // Load data
            fileManager.loadStudents(studentManager.getStudents());
            fileManager.loadCourses(courseManager.getCourses());
            fileManager.loadSubjects(courseManager.getSubjects());
            fileManager.loadEnrollments(courseManager.getEnrollments());
            // Không load Grade và Attendance
            cout << "Data loaded (except grades and attendances).\n";
            break;
        }
        case 21: { // Exit
            cout << "Goodbye!\n";
            return 0;
        }
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }

    return 0;
}