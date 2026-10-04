#include "../include/OutPatient.h"
#include <iostream>
using namespace std;

OutPatient::OutPatient() : Patient() {
    consultationFee = 300.0;
    diagnosticLabFee = 0.0;
    prescriptionCharges = 0.0;
}

OutPatient::OutPatient(int id, const string& name, int age, const string& gender,
                       const string& contact, const string& bloodGroup,
                       const string& disease, const VitalSigns& v,
                       double consultFee, double labFee, double prescriptionFee)
    : Patient(id, name, age, gender, contact, bloodGroup, disease, v) {
    this->consultationFee = consultFee;
    this->diagnosticLabFee = labFee;
    this->prescriptionCharges = prescriptionFee;
}

OutPatient::~OutPatient() {
}

double OutPatient::calculateTotalBill() const {
    return consultationFee + diagnosticLabFee + prescriptionCharges;
}

void OutPatient::generateSummary() const {
    cout << "\n================ [OUT-PATIENT CLINICAL SUMMARY] ================\n";
    cout << "Patient ID: " << id << " | Name: " << name << " | Age: " << age << "\n";
    cout << "Diagnosis: " << diseaseName << " | Blood Group: " << bloodGroup << "\n";
    cout << "Consultation Fee: $" << consultationFee << "\n";
    cout << "Lab Test Charges: $" << diagnosticLabFee << "\n";
    cout << "Prescription Charges: $" << prescriptionCharges << "\n";
    cout << "----------------------------------------------------------------\n";
    cout << "TOTAL OUTPATIENT CHARGE: $" << calculateTotalBill() << "\n";
    cout << "================================================================\n";
}

void OutPatient::display() const {
    Patient::display();
    cout << "  -> [OutPatient] Consultation: $" << consultationFee 
         << " | Lab Fees: $" << diagnosticLabFee 
         << " | Total Bill: $" << calculateTotalBill() << "\n";
}

OutPatient OutPatient::operator+(double extraLabFee) const {
    OutPatient updated = *this;
    updated.diagnosticLabFee += extraLabFee;
    return updated;
}
