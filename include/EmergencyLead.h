#ifndef EMERGENCY_LEAD_H
#define EMERGENCY_LEAD_H

#include <string>
#include <iostream>
using namespace std;

class EmergencyLead {
protected:
    string pagerCode;
    string traumaLevel;

public:
    EmergencyLead();
    EmergencyLead(const string& pager, const string& level);
    virtual ~EmergencyLead();

    inline string getPagerCode() const { return pagerCode; }
    inline string getTraumaLevel() const { return traumaLevel; }

    void triggerCodeRed() const;
};

#endif
