#include "Validator.h"

bool Validator::isNotEmpty(const string& s) const
{
    return s.find_first_not_of(" \t\r\n") != string::npos;
}
bool Validator::isValidID(const string& s) const
{
    return isNotEmpty(s) && s.find_first_of(" \t\r\n") == string::npos;
}
bool Validator::isValidName(const string& s) const
{
    return isNotEmpty(s);
}
bool Validator::isValidCredits(int credits) const
{
    return credits > 0;
}
bool Validator::isValidGPA(double gpa) const
{
    return gpa >= 0.0 && gpa <= 4.0;
}
bool Validator::isValidScore(double score) const
{
    return score >= 0.0 && score <= 10.0;
}
bool Validator::isValidPercent(int value) const
{
    return value >= 0 && value <= 100;
}
bool Validator::isValidPositiveInt(int value) const
{
    return value >= 0;
}
