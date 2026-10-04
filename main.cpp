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

    cout << ">>> STEP 1: Initialization (Encapsulation & Inheritance) <<<\n";
    Doctor drSmith(501, "Dr. Alice Smith", 45, "Female", "+1-555-0001", "EMP-D-01", "Cardiology", 15000.0, "Cardiologist", "LIC-123", 1000.0);
    ChiefSurgeon chiefSurg(601, "Dr. Gregory House", 52, "Male", "+1-555-0002", "EMP-S-01", "Diagnostics", 25000.0, "Infectious Disease", "LIC-456", 2000.0, "PAGER-01", "Level 1", 50, 5000.0);

    HospitalWard generalWard(101, "General Ward", 2); // Small capacity to test exceptions

    InPatient* p1 = new InPatient(1001, "John Doe", 30, "Male", "+1-555-1001", "O+", "Fever", {38.5, 120, 80, 95, 90}, 101, 3, 500, 1000, 200);
    InPatient* p2 = new InPatient(1002, "Jane Roe", 25, "Female", "+1-555-1002", "A-", "Flu", {37.5, 110, 75, 98, 95}, 102, 2, 500, 1000, 200);
    InPatient* p3 = new InPatient(1003, "Bob Builder", 40, "Male", "+1-555-1003", "B+", "Fracture", {37.0, 115, 80, 99, 98}, 103, 5, 500, 1500, 400);
    OutPatient* p4 = new OutPatient(1004, "Alice Wonderland", 22, "Female", "+1-555-1004", "AB+", "Checkup", {36.8, 110, 70, 99, 99}, 300, 100, 50);

    cout << "\n>>> STEP 2: Polymorphic Behaviors (Run-Time Polymorphism) <<<\n";
    vector<Patient*> hospitalRegistry; // STL Vector Integration
    hospitalRegistry.push_back(p1);
    hospitalRegistry.push_back(p2);
    hospitalRegistry.push_back(p3);
    hospitalRegistry.push_back(p4);

    for (int i = 0; i < hospitalRegistry.size(); ++i) {
        cout << "\n--- Registry Entry #" << (i+1) << " ---\n";
        hospitalRegistry[i]->display(); // Polymorphic display
        hospitalRegistry[i]->generateSummary();
    }

    cout << "\n>>> STEP 3: Exception Handling (Try-Catch-Throw) <<<\n";
    try {
        cout << "Admitting John Doe...\n";
        generalWard.admitPatient(p1);
        cout << "Admitting Jane Roe...\n";
        generalWard.admitPatient(p2);
        
        cout << "Admitting Bob Builder (Expect Ward Full Exception)...\n";
        generalWard.admitPatient(p3); // Throws exception
    } catch (const WardFullException& e) {
        cout << "[EXCEPTION CAUGHT] " << e.what() << "\n";
    }

    cout << "\n>>> STEP 4: Templates (Generic Queue) <<<\n";
    QueueTemplate<string> pharmacyQueue(5);
    pharmacyQueue.enqueue(p1->getName());
    pharmacyQueue.enqueue(p4->getName());
    cout << "Pharmacy Queue Size: " << pharmacyQueue.getSize() << "\n";
    cout << "Serving: " << pharmacyQueue.dequeue() << "\n";
    cout << "Serving: " << pharmacyQueue.dequeue() << "\n";

    cout << "\n>>> STEP 5: File Handling & Streams <<<\n";
    FileHandler fileHandler("final_hospital_records.txt");
    fileHandler.clearFile();
    
    for (int i = 0; i < hospitalRegistry.size(); ++i) {
        fileHandler.savePatientData(hospitalRegistry[i]);
    }
    fileHandler.readAllPatients();

    cout << "\n>>> CLEANUP <<<\n";
    delete p3; 
    delete p4;
    // p1 and p2 will be deleted by generalWard destructor

    cout << "\n===========================================================================\n";
    cout << "        PROJECT COMPLETION: ALL 5 PHASES SUCCESSFULLY INTEGRATED!          \n";
    cout << "===========================================================================\n";

    return 0;
}
