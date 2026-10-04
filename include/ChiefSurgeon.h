#ifndef CHIEF_SURGEON_H
#define CHIEF_SURGEON_H

#include "Doctor.h"
#include "EmergencyLead.h"
#include <string>
#include <iostream>
using namespace std;

class ChiefSurgeon : public Doctor, public EmergencyLead {
private:
    int successfulSurgeries;
    double emergencyAllowance;

public:
    ChiefSurgeon();
    ChiefSurgeon(int id, const string& name, int age, const string& gender,
                 const string& contact, const string& empId, const string& dept,
                 double salary, const string& specialization,
                 const string& license, double fee,
                 const string& pager, const string& traumaLvl,
                 int surgeries, double allowance);
    virtual ~ChiefSurgeon();

    inline int getSuccessfulSurgeries() const { return successfulSurgeries; }
    inline double getEmergencyAllowance() const { return emergencyAllowance; }

    void performEmergencyOperation(Patient& patient, const string& surgeryDetails);

    void display() const override;
};

#endif
