#pragma once
#include <vector>
#include <string>
#include "Student.h"
#include "Grade.h"
#include "Attendance.h"

class ReportGenerator
{
public:
    ReportGenerator() = default;
    ~ReportGenerator() = default;

    void generateStudentTranscript(const Student* student, const vector<Grade*>& allGrades) const;

    void generateCourseAttendanceReport(const string& courseID, const vector<Attendance*>& allAttendances) const;
};