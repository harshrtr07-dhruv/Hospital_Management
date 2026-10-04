#ifndef HOSPITAL_WARD_H
#define HOSPITAL_WARD_H

#include "Patient.h"
#include "Exceptions.h"
#include <string>
using namespace std;

class HospitalWard {
private:
    int wardId;
    string wardName;
    int maxCapacity;
    int patientCount;
    Patient** admittedPatients;

public:
    HospitalWard(int id, const string& name, int capacity = 5);
    ~HospitalWard();

    inline int getWardId() const { return wardId; }
    inline string getWardName() const { return wardName; }
    inline int getMaxCapacity() const { return maxCapacity; }
    inline int getPatientCount() const { return patientCount; }

    void admitPatient(Patient* newPatient);
    void dischargePatient(int patientId);
    Patient* findPatient(int patientId) const;

    void displayWard() const;
};

#endif
