#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;
    int age;
    string gender;
    string contactNumber;

public:
    Person();
    Person(int id, const string& name, int age, const string& gender, const string& contact = "N/A");
    virtual ~Person();

    int getId() const;
    string getName() const;
    int getAge() const;
    string getGender() const;
    
    string& getContactNumberRef();
    const string& getContactNumber() const;

    void setContactNumber(const string& newContact);

    virtual void display() const;
};

#endif
