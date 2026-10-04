#ifndef STAFF_H
#define STAFF_H

#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

class Staff : public Person {
protected:
    string employeeId;
    string department;
    double baseSalary;

public:
    Staff();
    Staff(int id, const string& name, int age, const string& gender,
          const string& contact, const string& empId,
          const string& dept, double salary);
    virtual ~Staff();

    inline string getEmployeeId() const { return employeeId; }
    inline string getDepartment() const { return department; }
    inline double getBaseSalary() const { return baseSalary; }

    inline void setBaseSalary(double s) { baseSalary = s; }

    void display() const override;
};

#endif
