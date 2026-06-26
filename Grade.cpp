#include "Grade.h"

Grade::Grade(Student* student, string courseID, double score)
{
    this->student = student;
    this->courseID = courseID;
    this->score = score;
}

void Grade::setStudent(Student* student) { this->student = student; }
void Grade::setCourseID(const string& id) { courseID = id; }
void Grade::setScore(double score) { this->score = score; }

Student* Grade::getStudent() const { return student; }
string Grade::getCourseID() const { return courseID; }
double Grade::getScore() const { return score; }

string Grade::getLetterGrade() const
{
    if (score >= 8.5) return "A";
    if (score >= 7.0) return "B";
    if (score >= 5.5) return "C";
    if (score >= 4.0) return "D";
    return "F";
}

void Grade::display() const
{
    string id = (student != nullptr) ? student->getID() : "Unknown";
    string name = (student != nullptr) ? student->getName() : "Unknown";

    cout << "Student: " << name << " (" << id << ")"
         << " | Course ID: " << courseID 
         << " | Score: " << score 
         << " (" << getLetterGrade() << ")";
}