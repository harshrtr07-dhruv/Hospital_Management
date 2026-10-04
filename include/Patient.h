#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"
#include "Common.h"
#include <string>
#include <iostream>
using namespace std;

class MedicalBoardInspector;

class Patient : public Person {
protected:
    string bloodGroup;
    string diseaseName;
    VitalSigns vitals;

    string* diagnosticNotes;
    int notesCount;
    int notesCapacity;

    void expandNotesCapacity();

public:
    Patient();
    Patient(int id, const string& name, int age, const string& gender,
            const string& contact, const string& bloodGroup = "O+",
            const string& disease = "General Checkup",
            const VitalSigns& v = {37.0, 120, 80, 75, 98});
    Patient(const Patient& other);
    virtual ~Patient();

    inline string getBloodGroup() const { return bloodGroup; }
    inline string getDiseaseName() const { return diseaseName; }
    inline const VitalSigns& getVitals() const { return vitals; }
    inline int getNotesCount() const { return notesCount; }
    inline bool isCritical() const { return checkCriticalVitals(vitals); }

    void addDiagnosticNote(const string& note);
    void updateVitals(const VitalSigns& newVitals);
    void printDiagnosticNotes() const;

    virtual double calculateTotalBill() const = 0;
    virtual void generateSummary() const = 0;

    void display() const override;

    bool operator==(const Patient& other) const;
    bool operator==(int searchId) const;

    friend ostream& operator<<(ostream& out, const Patient& p);
    friend istream& operator>>(istream& in, Patient& p);

    friend void generateEmergencyAudit(const Patient& p);
    friend class MedicalBoardInspector;
};

#endif
