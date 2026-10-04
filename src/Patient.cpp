#include "../include/Patient.h"
#include <iostream>
using namespace std;

void Patient::expandNotesCapacity() {
    int newCapacity = (notesCapacity == 0) ? 2 : notesCapacity * 2;
    string* newArray = new string[newCapacity];

    for (int i = 0; i < notesCount; ++i) {
        newArray[i] = diagnosticNotes[i];
    }

    delete[] diagnosticNotes;
    diagnosticNotes = newArray;
    notesCapacity = newCapacity;
}

Patient::Patient() : Person() {
    bloodGroup = "O+";
    diseaseName = "General Checkup";
    vitals = {37.0, 120, 80, 72, 98};
    
    notesCount = 0;
    notesCapacity = 2;
    diagnosticNotes = new string[notesCapacity];
}

Patient::Patient(int id, const string& name, int age, const string& gender,
                 const string& contact, const string& bloodGroup,
                 const string& disease, const VitalSigns& v)
    : Person(id, name, age, gender, contact) {
    this->bloodGroup = bloodGroup;
    this->diseaseName = disease;
    this->vitals = v;

    this->notesCount = 0;
    this->notesCapacity = 4;
    this->diagnosticNotes = new string[this->notesCapacity];
}

Patient::Patient(const Patient& other) : Person(other) {
    this->bloodGroup = other.bloodGroup;
    this->diseaseName = other.diseaseName;
    this->vitals = other.vitals;

    this->notesCount = other.notesCount;
    this->notesCapacity = other.notesCapacity;

    if (other.diagnosticNotes != nullptr && this->notesCapacity > 0) {
        this->diagnosticNotes = new string[this->notesCapacity];
        for (int i = 0; i < this->notesCount; ++i) {
            this->diagnosticNotes[i] = other.diagnosticNotes[i];
        }
    } else {
        this->diagnosticNotes = nullptr;
    }
}

Patient::~Patient() {
    if (diagnosticNotes != nullptr) {
        delete[] diagnosticNotes;
        diagnosticNotes = nullptr;
    }
}

void Patient::addDiagnosticNote(const string& note) {
    if (notesCount >= notesCapacity) {
        expandNotesCapacity();
    }
    diagnosticNotes[notesCount] = note;
    notesCount++;
}

void Patient::updateVitals(const VitalSigns& newVitals) {
    this->vitals = newVitals;
}

void Patient::printDiagnosticNotes() const {
    cout << "--- Clinical Notes for Patient: " << name << " (ID: " << id << ") ---\n";
    if (notesCount == 0) {
        cout << "  (No notes recorded)\n";
        return;
    }
    for (int i = 0; i < notesCount; ++i) {
        cout << "  [" << (i + 1) << "] " << diagnosticNotes[i] << "\n";
    }
}

void Patient::display() const {
    Person::display();
    cout << "  -> Blood Group: " << bloodGroup 
         << " | Disease: " << diseaseName 
         << " | Total Notes: " << notesCount << "\n";
    cout << "  -> ";
    vitals.display();
}

bool Patient::operator==(const Patient& other) const {
    return this->id == other.id;
}

bool Patient::operator==(int searchId) const {
    return this->id == searchId;
}

ostream& operator<<(ostream& out, const Patient& p) {
    out << "[Patient Record] ID: " << p.id 
        << " | Name: " << p.name 
        << " | Age: " << p.age 
        << " | Blood Group: " << p.bloodGroup 
        << " | Disease: " << p.diseaseName;
    return out;
}

istream& operator>>(istream& in, Patient& p) {
    cout << "Enter Patient ID: ";
    in >> p.id;
    cout << "Enter Name: ";
    in >> p.name;
    cout << "Enter Age: ";
    in >> p.age;
    cout << "Enter Gender: ";
    in >> p.gender;
    cout << "Enter Contact: ";
    in >> p.contactNumber;
    cout << "Enter Blood Group: ";
    in >> p.bloodGroup;
    cout << "Enter Diagnosis/Disease: ";
    in >> p.diseaseName;
    return in;
}

void generateEmergencyAudit(const Patient& p) {
    cout << "\n================ [EMERGENCY AUDIT (FRIEND FUNCTION)] ================\n";
    cout << "Direct Private Access -> Name: " << p.name 
         << " | Blood Group: " << p.bloodGroup 
         << " | SpO2: " << p.vitals.oxygenLevel << "%\n";
    cout << "Status: " << (p.isCritical() ? "CRITICAL ALERT!" : "STABLE") << "\n";
    if (p.notesCount > 0) {
        cout << "Latest Clinical Note: \"" << p.diagnosticNotes[p.notesCount - 1] << "\"\n";
    }
    cout << "=====================================================================\n";
}
