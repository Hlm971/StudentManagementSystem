#pragma once
#include <string>
using namespace std;

class Validator
{
public:
    bool isNotEmpty(const string& s) const;
    bool isValidID(const string& s) const;
    bool isValidName(const string& s) const;
    bool isValidCredits(int credits) const;
    bool isValidGPA(double gpa) const;
    bool isValidScore(double score) const;
    bool isValidPercent(int value) const;
    bool isValidPositiveInt(int value) const;
};
