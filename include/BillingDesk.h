#ifndef BILLING_DESK_H
#define BILLING_DESK_H

#include "Patient.h"
#include <iostream>
#include <string>
using namespace std;

class BillingDesk {
public:
    double calculateDiscountedBill(const Patient& p);
    double calculateDiscountedBill(const Patient& p, double insuranceCoveragePercent);
    double calculateDiscountedBill(const Patient& p, double insuranceCoveragePercent, double emergencyTaxAmount);

    void printInvoice(const Patient& p);
    void printInvoice(const Patient& p, double insurancePercent);
};

#endif
