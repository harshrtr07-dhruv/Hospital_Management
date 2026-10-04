#include "../include/Staff.h"
#include <iostream>
using namespace std;

Staff::Staff() : Person() {
    employeeId = "EMP-000";
    department = "General Administration";
    baseSalary = 3000.0;
}

Staff::Staff(int id, const string& name, int age, const string& gender,
             const string& contact, const string& empId,
             const string& dept, double salary)
    : Person(id, name, age, gender, contact) {
    this->employeeId = empId;
    this->department = dept;
    this->baseSalary = salary;
}

Staff::~Staff() {
}

void Staff::display() const {
    Person::display();
    cout << "  -> [Staff] Emp ID: " << employeeId 
         << " | Dept: " << department 
         << " | Salary: $" << baseSalary << "\n";
}
