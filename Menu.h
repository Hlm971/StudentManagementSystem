#pragma once
#include <string>
#include <vector>
using namespace std;

class Menu
{
private:
    string title;
    vector<string> options;
public:
    Menu(string title = "");
    Menu& operator<<(const string& option);
    void display() const;
    int choose() const;
};
