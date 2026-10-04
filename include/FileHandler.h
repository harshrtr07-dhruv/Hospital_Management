#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Patient.h"
using namespace std;

class FileHandler {
private:
    string filename;
public:
    FileHandler(const string& fname = "hospital_data.txt");
    
    void savePatientData(const Patient* patient);
    void readAllPatients();
    void clearFile();
    void demoFilePointers();
};

#endif
