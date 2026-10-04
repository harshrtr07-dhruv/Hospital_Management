#include "../include/Doctor.h"
#include <iostream>
using namespace std;

Doctor::Doctor() : Staff() {
    specialization = "General Physician";
    licenseNumber = "DOC-0000";
    consultationFee = 500.0;
    consultationCount = 0;
}

Doctor::Doctor(int id, const string& name, int age, const string& gender,
               const string& contact, const string& empId, const string& dept,
               double salary, const string& specialization,
               const string& license, double fee)
    : Staff(id, name, age, gender, contact, empId, dept, salary) {
    this->specialization = specialization;
    this->licenseNumber = license;
    this->consultationFee = fee;
    this->consultationCount = 0;
}

Doctor::~Doctor() {
}

void Doctor::performConsultation(Patient& patient, const string& notes) {
    consultationCount++;
    string clinicalNote = "Dr. " + this->name + " (" + specialization + "): " + notes;
    
    patient.addDiagnosticNote(clinicalNote);

    cout << "[CONSULTATION] Dr. " << this->name 
         << " consulted Patient: " << patient.getName() 
         << " (ID: " << patient.getId() << ")\n";
}

void Doctor::display() const {
    Staff::display();
    cout << "  -> Spec: " << specialization 
         << " | License: " << licenseNumber 
         << " | Fee: $" << consultationFee 
         << " | Consultations: " << consultationCount << "\n";
}
