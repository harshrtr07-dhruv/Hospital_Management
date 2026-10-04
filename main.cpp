#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "include/Common.h"
#include "include/Person.h"
#include "include/Patient.h"
#include "include/InPatient.h"
#include "include/OutPatient.h"
#include "include/Doctor.h"
#include "include/ChiefSurgeon.h"
#include "include/HospitalWard.h"
#include "include/Exceptions.h"
#include "include/QueueTemplate.h"
#include "include/FileHandler.h"

void printHeader() {
    cout << "\n===========================================================================\n";
    cout << "             FINAL HOSPITAL MANAGEMENT SYSTEM - PHASE 5                    \n";
    cout << "    (Integration of OOP, Polymorphism, Exceptions, Templates, File I/O)    \n";
    cout << "===========================================================================\n\n";
}

int main() {
    printHeader();
    vector<Patient*> hospitalRegistry;
    HospitalWard generalWard(101, "General Ward", 50); // Set a higher capacity
    int choice = 0;

    while (choice != 5) {
        cout << "\n========== HOSPITAL MENU ==========\n";
        cout << "1. Add a New In-Patient\n";
        cout << "2. Admit Patient to Ward\n";
        cout << "3. Discharge (Delete) Patient\n";
        cout << "4. Display All Patients & Save to File\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, age, days;
                string name, disease;
                cout << "Enter Patient ID: "; cin >> id;
                cout << "Enter Name: "; cin >> ws; getline(cin, name);
                cout << "Enter Age: "; cin >> age;
                cout << "Enter Disease: "; cin >> ws; getline(cin, disease);
                cout << "Enter Days Staying: "; cin >> days;
                
                // Real-time dynamic allocation
                InPatient* newPatient = new InPatient(id, name, age, "N/A", "N/A", "N/A", disease, {37.0, 120, 80, 95, 90}, 101, days, 500);
                hospitalRegistry.push_back(newPatient);
                cout << "\n✅ Patient created successfully!\n";
                break;
            }
            case 2: {
                if(hospitalRegistry.empty()) {
                    cout << "No patients to admit!\n"; break;
                }
                try {
                    // Try to admit the last created patient
                    generalWard.admitPatient(hospitalRegistry.back());
                    cout << "\n✅ Patient Admitted to Ward!\n";
                } catch (const WardFullException& e) {
                    cout << "\n❌ [ERROR] " << e.what() << "\n";
                }
                break;
            }
            case 3: {
                int searchId;
                cout << "Enter Patient ID to Discharge: ";
                cin >> searchId;
                
                bool found = false;
                for (auto it = hospitalRegistry.begin(); it != hospitalRegistry.end(); ++it) {
                    // Uses your overloaded == operator!
                    if (**it == searchId) { 
                        generalWard.dischargePatient(searchId); // If you have this method
                        delete *it; // Free memory!
                        hospitalRegistry.erase(it);
                        cout << "\n✅ Patient Discharged and Deleted!\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "\n❌ Patient not found!\n";
                break;
            }
            case 4: {
                FileHandler fileHandler("final_hospital_records.txt");
                fileHandler.clearFile(); // Reset file
                cout << "\n--- CURRENT PATIENTS ---\n";
                for (Patient* p : hospitalRegistry) {
                    p->display();
                    fileHandler.savePatientData(p); // Real-time file saving
                }
                cout << "\n✅ Records saved to final_hospital_records.txt\n";
                break;
            }
            case 5:
                cout << "Exiting system. Cleaning up memory...\n";
                for(Patient* p : hospitalRegistry) delete p;
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
