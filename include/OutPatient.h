#ifndef OUTPATIENT_H
#define OUTPATIENT_H

#include "Patient.h"
#include <iostream>
#include <string>
using namespace std;

class OutPatient : public Patient {
private:
    double consultationFee;
    double diagnosticLabFee;
    double prescriptionCharges;

public:
    OutPatient();
    OutPatient(int id, const string& name, int age, const string& gender,
               const string& contact, const string& bloodGroup,
               const string& disease, const VitalSigns& v,
               double consultFee = 300.0, double labFee = 0.0, double prescriptionFee = 0.0);
    virtual ~OutPatient();

    inline double getConsultationFee() const { return consultationFee; }
    inline double getDiagnosticLabFee() const { return diagnosticLabFee; }
    inline double getPrescriptionCharges() const { return prescriptionCharges; }

    inline void setConsultationFee(double c) { consultationFee = c; }
    inline void setDiagnosticLabFee(double l) { diagnosticLabFee = l; }
    inline void setPrescriptionCharges(double p) { prescriptionCharges = p; }

    double calculateTotalBill() const override;
    void generateSummary() const override;
    void display() const override;

    OutPatient operator+(double extraLabFee) const;
};

#endif
