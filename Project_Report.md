# Hospital Management System - C++ OOP Project Report

**Submitted by:** Harshvardhan Sinh Shekhawat  
**Registration No:** 24BCE11531  
**Submitted to:** Dr. Garima Jain  
**Subject:** OOPS with C++  
**Slot:** B11+B12+B13  

---

## 1. Project Overview
The **Hospital Management System** is a comprehensive C++ console application built to demonstrate core and advanced concepts of Object-Oriented Programming (OOP). The project simulates a real-world hospital environment involving Patients (In-Patients and Out-Patients), Medical Staff (Doctors, Chief Surgeons), Hospital Wards, and File Persistence. 

The project was developed iteratively, strictly aligning with the 5 Course Outcomes (COs) of the syllabus.

---

## 2. Implementation of Course Outcomes (CO1 - CO5)

### CO1 & CO2: Classes, Objects, and Encapsulation
* **Encapsulation & Access Specifiers**: All sensitive patient data (like vitals and diagnostic notes) is hidden using `private` and `protected` access specifiers, and accessed securely through public getter/setter methods.
* **Constructors & Destructors**: Utilized Default Constructors, Parameterized Constructors, and Destructors across all classes (e.g., `Patient`, `HospitalWard`) to manage object lifecycles safely.
* **Copy Constructor (Deep Copy)**: The `Patient` class includes a custom Copy Constructor that performs a deep copy of the dynamically allocated `diagnosticNotes` string array to prevent memory leaks and pointer corruption.
* **Dynamic Objects**: Managed memory dynamically at runtime using the `new` and `delete` operators for instantiating patient records in `main.cpp`.
* **Friend Class & Friend Function**: Implemented a `MedicalBoardInspector` class and a `generateEmergencyAudit()` function which are granted `friend` access to the `Patient` class, allowing them to audit private variables securely.

### CO3: Polymorphism & Inheritance
* **Inheritance Hierarchies**: 
  * **Hierarchical**: `InPatient` and `OutPatient` inherit from the `Patient` base class.
  * **Multilevel**: `Doctor` inherits from `Staff`, which inherits from `Person`.
  * **Multiple**: `ChiefSurgeon` inherits from both `Doctor` and `EmergencyLead`.
* **Abstract Base Class**: The `Patient` class acts as an Abstract Base Class containing pure virtual functions like `virtual double calculateTotalBill() const = 0;`.
* **Run-Time Polymorphism**: Utilized the Standard Template Library (STL) `std::vector<Patient*>` to store all patient types. A single loop triggers the overridden `display()` methods dynamically based on the specific object type at runtime.
* **Compile-Time Polymorphism (Overloading)**: 
  * **Function Overloading**: The `BillingDesk` class overloads the `calculateDiscountedBill()` function to accept varying parameters (standard, with insurance, with emergency tax).
  * **Operator Overloading**: Overloaded the `==` operator for searching patient IDs, and the `<<` insertion operator to stream patient records easily.

### CO4: Exception Handling & Templates
* **Exception Handling (try-catch-throw)**: Implemented a robust error-handling mechanism. For example, if the `HospitalWard` reaches maximum capacity, it uses `throw` to trigger a custom `WardFullException`, which is safely caught in `main.cpp` using a `catch` block without crashing the system.
* **Class Templates**: Designed a generic `QueueTemplate<T>` class capable of queuing any data type. It is utilized to queue `std::string` objects representing the patient pharmacy waitlist.

### CO5: File Handling and Streams
* **Data Persistence**: Integrated the `<fstream>` library to ensure hospital records are permanently saved to the hard drive.
* **File Operations**: 
  * Utilized `std::ofstream` in append mode (`std::ios::app`) to write new patient records directly to `final_hospital_records.txt`.
  * Utilized `std::ifstream` alongside `std::getline()` to sequentially read the saved data back into the console, proving successful disk interaction.

---

## 3. How to Compile and Run
1. Open a terminal in the project directory.
2. Compile the source code using the following command:
   ```bash
   g++ -std=c++17 src/*.cpp main.cpp -o hospital_system.exe
   ```
3. Execute the compiled application:
   ```bash
   .\hospital_system.exe
   ```

---
*End of Report*
