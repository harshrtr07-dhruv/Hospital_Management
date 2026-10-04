#include "../include/FileHandler.h"

FileHandler::FileHandler(const string& fname) {
    this->filename = fname;
}

void FileHandler::clearFile() {
    // Open file in ios::out and ios::trunc mode to clear contents
    ofstream outFile(filename, ios::out | ios::trunc);
    if (!outFile) {
        cout << "[FILE ERROR] Could not open file to clear.\n";
        return;
    }
    cout << "[FILE SUCCESS] File " << filename << " has been cleared.\n";
    outFile.close();
}

void FileHandler::savePatientData(const Patient* patient) {
    if (patient == nullptr) return;

    // Open file in ios::out and ios::app (append) mode
    ofstream outFile(filename, ios::out | ios::app);
    if (!outFile) {
        cout << "[FILE ERROR] Could not open file for writing.\n";
        return;
    }

    // Write patient data directly using stream operators
    outFile << patient->getId() << ","
            << patient->getName() << ","
            << patient->getBloodGroup() << ","
            << patient->getDiseaseName() << "\n";
            
    cout << "[FILE SUCCESS] Saved patient data to " << filename << ".\n";
    outFile.close();
}

void FileHandler::readAllPatients() {
    // Open file in ios::in mode
    ifstream inFile(filename, ios::in);
    if (!inFile) {
        cout << "[FILE ERROR] Could not open file for reading.\n";
        return;
    }

    cout << "\n--- Reading all patient records from " << filename << " ---\n";
    string line;
    int count = 0;
    while (getline(inFile, line)) {
        cout << "Record " << ++count << ": " << line << "\n";
    }
    
    if (count == 0) {
        cout << " (File is empty)\n";
    }
    
    cout << "--------------------------------------------------------\n";
    inFile.close();
}

void FileHandler::demoFilePointers() {
    // Open file in both read and write mode (fstream) to demonstrate file pointers
    fstream file(filename, ios::in | ios::out);
    if (!file) {
        cout << "[FILE ERROR] Could not open file for pointer demo.\n";
        return;
    }

    cout << "\n--- Demonstrating File Pointers (seekg, tellg, seekp, tellp) ---\n";
    
    // tellg() gets current get pointer position
    cout << "Initial get pointer position: " << file.tellg() << " bytes.\n";
    
    // seekg() moves the get pointer (read position)
    file.seekg(0, ios::end);
    cout << "File size (by seeking to end): " << file.tellg() << " bytes.\n";
    
    // Move get pointer back to beginning
    file.seekg(0, ios::beg);
    
    // Read first few characters
    char buffer[10];
    if (file.read(buffer, 5)) {
        buffer[5] = '\0';
        cout << "First 5 characters read: " << buffer << "\n";
    }
    
    // Check put pointer (write position)
    cout << "Current put pointer position: " << file.tellp() << " bytes.\n";

    cout << "--------------------------------------------------------\n";
    file.close();
}
