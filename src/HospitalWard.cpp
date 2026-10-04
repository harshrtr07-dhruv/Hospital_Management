#include "../include/HospitalWard.h"
#include <iostream>
using namespace std;

HospitalWard::HospitalWard(int id, const string& name, int capacity) {
    this->wardId = id;
    this->wardName = name;
    this->maxCapacity = capacity;
    this->patientCount = 0;

    this->admittedPatients = new Patient*[this->maxCapacity];
    for (int i = 0; i < this->maxCapacity; ++i) {
        this->admittedPatients[i] = nullptr;
    }
}

HospitalWard::~HospitalWard() {
    for (int i = 0; i < patientCount; ++i) {
        if (admittedPatients[i] != nullptr) {
            delete admittedPatients[i];
            admittedPatients[i] = nullptr;
        }
    }
    delete[] admittedPatients;
    admittedPatients = nullptr;
}

void HospitalWard::admitPatient(Patient* newPatient) {
    if (newPatient == nullptr) {
        return;
    }

    if (patientCount >= maxCapacity) {
        throw WardFullException(wardName + " has reached max capacity.");
    }

    admittedPatients[patientCount] = newPatient;
    patientCount++;

    cout << "[ADMISSION SUCCESS] Patient " << newPatient->getName() 
         << " (ID: " << newPatient->getId() << ") admitted to " << wardName << ".\n";
}

void HospitalWard::dischargePatient(int patientId) {
    int targetIndex = -1;

    for (int i = 0; i < patientCount; ++i) {
        if (admittedPatients[i] != nullptr && admittedPatients[i]->getId() == patientId) {
            targetIndex = i;
            break;
        }
    }

    if (targetIndex == -1) {
        throw PatientNotFoundException(to_string(patientId));
    }

    cout << "[DISCHARGE SUCCESS] Discharging Patient: " 
         << admittedPatients[targetIndex]->getName() << " (ID: " << patientId << ")\n";

    delete admittedPatients[targetIndex];

    for (int i = targetIndex; i < patientCount - 1; ++i) {
        admittedPatients[i] = admittedPatients[i + 1];
    }
    admittedPatients[patientCount - 1] = nullptr;
    patientCount--;
}

Patient* HospitalWard::findPatient(int patientId) const {
    for (int i = 0; i < patientCount; ++i) {
        if (admittedPatients[i] != nullptr && admittedPatients[i]->getId() == patientId) {
            return admittedPatients[i];
        }
    }
    throw PatientNotFoundException(to_string(patientId));
}

void HospitalWard::displayWard() const {
    cout << "\n==================== " << wardName << " (Ward ID: " << wardId << ") ====================\n";
    cout << "Beds Occupied: " << patientCount << " / " << maxCapacity << "\n";
    
    if (patientCount == 0) {
        cout << "  (Ward is currently empty)\n";
    } else {
        for (int i = 0; i < patientCount; ++i) {
            cout << "\n[Bed #" << (i + 1) << "] ";
            admittedPatients[i]->display();
        }
    }
    cout << "========================================================================\n";
}
