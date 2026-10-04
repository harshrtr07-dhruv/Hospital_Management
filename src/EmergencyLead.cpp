#include "../include/EmergencyLead.h"
#include <iostream>
using namespace std;

EmergencyLead::EmergencyLead() {
    pagerCode = "PAGER-00";
    traumaLevel = "Level-1";
}

EmergencyLead::EmergencyLead(const string& pager, const string& level) {
    this->pagerCode = pager;
    this->traumaLevel = level;
}

EmergencyLead::~EmergencyLead() {
}

void EmergencyLead::triggerCodeRed() const {
    cout << "[EMERGENCY CALL] Pager: " << pagerCode 
         << " | Responding to " << traumaLevel << " Trauma Call!\n";
}
