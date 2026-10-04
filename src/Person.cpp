#include "../include/Person.h"
#include <iostream>
using namespace std;

Person::Person() {
    id = 0;
    name = "Unknown";
    age = 0;
    gender = "Not Specified";
    contactNumber = "N/A";
}

Person::Person(int id, const string& name, int age, const string& gender, const string& contact) {
    this->id = id;
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->contactNumber = contact;
}

Person::~Person() {
}

int Person::getId() const {
    return id;
}

string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

string Person::getGender() const {
    return gender;
}

string& Person::getContactNumberRef() {
    return contactNumber;
}

const string& Person::getContactNumber() const {
    return contactNumber;
}

void Person::setContactNumber(const string& newContact) {
    this->contactNumber = newContact;
}

void Person::display() const {
    cout << "ID: " << id 
         << " | Name: " << name 
         << " | Age: " << age 
         << " | Gender: " << gender 
         << " | Contact: " << contactNumber << "\n";
}
