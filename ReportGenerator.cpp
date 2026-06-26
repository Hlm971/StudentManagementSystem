#include "ReportGenerator.h"
#include <iostream>

using namespace std;

void ReportGenerator::generateStudentTranscript(const Student* student, const vector<Grade*>& allGrades) const
{
    if (!student) {
        cout << "Error: Invalid student data." << endl;
        return;
    }

    cout << "BANG DIEM SINH VIEN" << endl;
    student->display(); 
    
    bool hasGrades = false;
    for (const Grade* g : allGrades)
    {
        if (g->getStudent() != nullptr && g->getStudent()->getID() == student->getID())
        {
            cout << "Course: " << g->getCourseID() 
                 << "\tScore: " << g->getScore() 
                 << "\tGrade: " << g->getLetterGrade() << endl;
            hasGrades = true;
        }
    }

    if (!hasGrades)
    {
        cout << "No grades recorded for this student." << endl;
    }
    cout << "=======================================\n" << endl;
}

void ReportGenerator::generateCourseAttendanceReport(const string& courseID, const vector<Attendance*>& allAttendances) const
{
    // ... (Giữ nguyên như cũ vì hàm này chỉ so sánh courseID) ...
    cout << "=======================================" << endl;
    cout << "      ATTENDANCE REPORT FOR COURSE     " << endl;
    cout << "Course ID: " << courseID << endl;
    cout << "=======================================" << endl;

    bool hasRecords = false;
    for (const Attendance* a : allAttendances)
    {
        if (a->getCourseID() == courseID)
        {
            a->display();
            cout << endl;
            hasRecords = true;
        }
    }

    if (!hasRecords)
    {
        cout << "No attendance records found for this course." << endl;
    }
    cout << "=======================================\n" << endl;
}