#include "../include/InPatient.h"
#include <iostream>
using namespace std;

InPatient::InPatient() : Patient() {
    roomNumber = 101;
    daysStayed = 1;
    dailyRoomRate = 1000.0;
    surgeryCharges = 0.0;
    medicationCharges = 0.0;
}

InPatient::InPatient(int id, const string& name, int age, const string& gender,
                     const string& contact, const string& bloodGroup,
                     const string& disease, const VitalSigns& v,
                     int roomNum, int days, double roomRate, double surgeryFee, double medFee)
    : Patient(id, name, age, gender, contact, bloodGroup, disease, v) {
    this->roomNumber = roomNum;
    this->daysStayed = days;
    this->dailyRoomRate = roomRate;
    this->surgeryCharges = surgeryFee;
    this->medicationCharges = medFee;
}

InPatient::~InPatient() {
}

double InPatient::calculateTotalBill() const {
    double roomTotal = daysStayed * dailyRoomRate;
    return roomTotal + surgeryCharges + medicationCharges;
}

void InPatient::generateSummary() const {
    cout << "\n================ [IN-PATIENT DISCHARGE SUMMARY] ================\n";
    cout << "Patient ID: " << id << " | Name: " << name << " | Age: " << age << "\n";
    cout << "Diagnosis: " << diseaseName << " | Blood Group: " << bloodGroup << "\n";
    cout << "Admitted Room: #" << roomNumber << " | Total Stay: " << daysStayed << " days\n";
    cout << "Room Charges ($" << dailyRoomRate << "/day): $" << (daysStayed * dailyRoomRate) << "\n";
    cout << "Surgery Fees: $" << surgeryCharges << "\n";
    cout << "Medication & Nursing Fees: $" << medicationCharges << "\n";
    cout << "----------------------------------------------------------------\n";
    cout << "FINAL PAYABLE BILL: $" << calculateTotalBill() << "\n";
    cout << "================================================================\n";
}

void InPatient::display() const {
    Patient::display();
    cout << "  -> [InPatient] Room: #" << roomNumber 
         << " | Days: " << daysStayed 
         << " | Room Rate: $" << dailyRoomRate 
         << " | Total Bill: $" << calculateTotalBill() << "\n";
}

InPatient InPatient::operator+(double extraMedicationFee) const {
    InPatient updated = *this;
    updated.medicationCharges += extraMedicationFee;
    return updated;
}
