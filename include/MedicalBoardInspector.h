#ifndef MEDICAL_BOARD_INSPECTOR_H
#define MEDICAL_BOARD_INSPECTOR_H

#include "Patient.h"
#include <iostream>
#include <string>
using namespace std;

class MedicalBoardInspector {
private:
    string inspectorId;
    string inspectorName;

public:
    MedicalBoardInspector(const string& id, const string& name) {
        this->inspectorId = id;
        this->inspectorName = name;
    }
    
    ~MedicalBoardInspector() {}

    void inspectPatientRecord(const Patient& p) const {
        cout << "\n+---------------- [MEDICAL BOARD AUDIT LOG] ----------------+\n";
        cout << "| Inspector: " << inspectorName << " (ID: " << inspectorId << ")\n";
        cout << "| Auditing Private Patient: " << p.name << " (ID: " << p.id << ")\n";
        cout << "| Private Blood Group: " << p.bloodGroup << "\n";
        cout << "| Private Disease Record: " << p.diseaseName << "\n";
        cout << "| Private Vitals: Temp=" << p.vitals.temperature 
             << "C, BP=" << p.vitals.systolicBP << "/" << p.vitals.diastolicBP 
             << ", SpO2=" << p.vitals.oxygenLevel << "%\n";
        cout << "| Diagnostic Notes Count: " << p.notesCount << "\n";
        for (int i = 0; i < p.notesCount; ++i) {
            cout << "|   - Note " << (i + 1) << ": " << p.diagnosticNotes[i] << "\n";
        }
        cout << "+----------------------------------------------------------+\n";
    }
};

#endif
