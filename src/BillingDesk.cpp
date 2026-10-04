#include "../include/BillingDesk.h"
#include <iostream>
using namespace std;

double BillingDesk::calculateDiscountedBill(const Patient& p) {
    return p.calculateTotalBill();
}

double BillingDesk::calculateDiscountedBill(const Patient& p, double insuranceCoveragePercent) {
    double base = p.calculateTotalBill();
    double covered = (base * insuranceCoveragePercent) / 100.0;
    return base - covered;
}

double BillingDesk::calculateDiscountedBill(const Patient& p, double insuranceCoveragePercent, double emergencyTaxAmount) {
    double discounted = calculateDiscountedBill(p, insuranceCoveragePercent);
    return discounted + emergencyTaxAmount;
}

void BillingDesk::printInvoice(const Patient& p) {
    cout << "\n================ [STANDARD BILLING INVOICE] ================\n";
    cout << "Patient ID: " << p.getId() << " | Name: " << p.getName() << "\n";
    cout << "Total Gross Amount: $" << p.calculateTotalBill() << "\n";
    cout << "Final Payable Amount: $" << calculateDiscountedBill(p) << "\n";
    cout << "============================================================\n";
}

void BillingDesk::printInvoice(const Patient& p, double insurancePercent) {
    double gross = p.calculateTotalBill();
    double net = calculateDiscountedBill(p, insurancePercent);
    cout << "\n================ [INSURANCE BILLING INVOICE] ================\n";
    cout << "Patient ID: " << p.getId() << " | Name: " << p.getName() << "\n";
    cout << "Total Gross Amount: $" << gross << "\n";
    cout << "Insurance Applied: " << insurancePercent << "% (-$" << (gross - net) << ")\n";
    cout << "Net Patient Payable: $" << net << "\n";
    cout << "=============================================================\n";
}
