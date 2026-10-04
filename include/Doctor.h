#ifndef DOCTOR_H
#define DOCTOR_H

#include "Staff.h"
#include "Patient.h"
#include <string>
using namespace std;

class Doctor : public Staff {
protected:
    string specialization;
    string licenseNumber;
    double consultationFee;
    int consultationCount;

public:
    Doctor();
    Doctor(int id, const string& name, int age, const string& gender,
           const string& contact, const string& empId, const string& dept,
           double salary, const string& specialization,
           const string& license, double fee = 500.0);
    virtual ~Doctor();

    inline string getSpecialization() const { return specialization; }
    inline string getLicenseNumber() const { return licenseNumber; }
    inline double getConsultationFee() const { return consultationFee; }
    inline int getConsultationCount() const { return consultationCount; }
    inline void setConsultationFee(double newFee) { consultationFee = newFee; }

    void performConsultation(Patient& patient, const string& notes);

    void display() const override;
};

#endif
