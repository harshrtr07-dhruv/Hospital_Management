#ifndef INPATIENT_H
#define INPATIENT_H

#include "Patient.h"
#include <iostream>
#include <string>
using namespace std;

class InPatient : public Patient {
private:
    int roomNumber;
    int daysStayed;
    double dailyRoomRate;
    double surgeryCharges;
    double medicationCharges;

public:
    InPatient();
    InPatient(int id, const string& name, int age, const string& gender,
              const string& contact, const string& bloodGroup,
              const string& disease, const VitalSigns& v,
              int roomNum, int days, double roomRate, double surgeryFee = 0.0, double medFee = 0.0);
    virtual ~InPatient();

    inline int getRoomNumber() const { return roomNumber; }
    inline int getDaysStayed() const { return daysStayed; }
    inline double getDailyRoomRate() const { return dailyRoomRate; }
    inline double getSurgeryCharges() const { return surgeryCharges; }
    inline double getMedicationCharges() const { return medicationCharges; }

    inline void setRoomNumber(int r) { roomNumber = r; }
    inline void setDaysStayed(int d) { daysStayed = d; }
    inline void setSurgeryCharges(double s) { surgeryCharges = s; }
    inline void setMedicationCharges(double m) { medicationCharges = m; }

    double calculateTotalBill() const override;
    void generateSummary() const override;
    void display() const override;

    InPatient operator+(double extraMedicationFee) const;
};

#endif
