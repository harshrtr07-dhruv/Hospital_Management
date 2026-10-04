#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <string>
#include <exception>
using namespace std;

class HospitalException : public exception {
protected:
    string message;
public:
    HospitalException(const string& msg) : message(msg) {}
    
    // Exception specification as per CO4 (using noexcept for C++11+ compatibility)
    virtual const char* what() const noexcept {
        return message.c_str();
    }
};

class WardFullException : public HospitalException {
public:
    WardFullException(const string& msg) : HospitalException("Ward Full - " + msg) {}
};

class PatientNotFoundException : public HospitalException {
public:
    PatientNotFoundException(const string& msg) : HospitalException("Patient Not Found - " + msg) {}
};

#endif
