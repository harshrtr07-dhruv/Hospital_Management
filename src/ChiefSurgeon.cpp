#include "../include/ChiefSurgeon.h"
#include <iostream>
using namespace std;

ChiefSurgeon::ChiefSurgeon()
    : Doctor(), EmergencyLead(), successfulSurgeries(0), emergencyAllowance(2000.0) {
}

ChiefSurgeon::ChiefSurgeon(int id, const string& name, int age, const string& gender,
                           const string& contact, const string& empId, const string& dept,
                           double salary, const string& specialization,
                           const string& license, double fee,
                           const string& pager, const string& traumaLvl,
                           int surgeries, double allowance)
    : Doctor(id, name, age, gender, contact, empId, dept, salary, specialization, license, fee),
      EmergencyLead(pager, traumaLvl),
      successfulSurgeries(surgeries),
      emergencyAllowance(allowance) {
}

ChiefSurgeon::~ChiefSurgeon() {
}

void ChiefSurgeon::performEmergencyOperation(Patient& patient, const string& surgeryDetails) {
    successfulSurgeries++;
    triggerCodeRed();
    string report = "Chief Surgeon " + this->name + " performed emergency surgery: " + surgeryDetails;
    patient.addDiagnosticNote(report);
    cout << "[SURGERY COMPLETED] " << report << "\n";
}

void ChiefSurgeon::display() const {
    Doctor::display();
    cout << "  -> [ChiefSurgeon (Multiple Inheritance)] Pager: " << pagerCode 
         << " | Trauma: " << traumaLevel 
         << " | Surgeries Done: " << successfulSurgeries 
         << " | Allowance: $" << emergencyAllowance << "\n";
}
