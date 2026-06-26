#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string id;
    string name;

public:
    Person(string id = "", string name = "");
    virtual ~Person() {}

    void setID(const string& id);
    void setName(const string& name);

    string getID() const;
    string getName() const;

    virtual void display() const = 0;
};
