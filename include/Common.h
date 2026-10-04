#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>
using namespace std;

struct VitalSigns {
    double temperature;
    int systolicBP;
    int diastolicBP;
    int pulseRate;
    int oxygenLevel;

    void display() const {
        cout << "[Vitals] Temp: " << temperature << " C | BP: " 
             << systolicBP << "/" << diastolicBP << " mmHg | Pulse: " 
             << pulseRate << " bpm | SpO2: " << oxygenLevel << "%\n";
    }
};

inline bool checkCriticalVitals(const VitalSigns& vitals, int minOxygen = 92, int maxPulse = 120) {
    if (vitals.oxygenLevel < minOxygen || vitals.pulseRate > maxPulse || vitals.temperature > 39.0) {
        return true;
    }
    return false;
}

#endif
