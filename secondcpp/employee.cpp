#include <iostream>
#include <string>
#include <vector>
#include <memory> // For smart pointers
#include <typeinfo>

using namespace std;

// Base Class: Employee
class Employee {
protected:
    int id;
    string name;
    int deptId;
    double basic;

public:
    Employee(int id, string name, int deptId, double basic)
        : id(id), name(name), deptId(deptId), basic(basic) {}

    // Virtual function for runtime polymorphism
    virtual double computeNetSalary() {
        return 0;  // To be overridden
    }

    virtual void displayDetails() {
        cout << "ID: " << id << ", Name: " << name << ", Dept ID: " << deptId << endl;
    }

    virtual ~Employee() {}
};

// Derived Class: HOD (Head of Department)
class HOD : public Employee {
private:
    double allowance;

public:
    HOD(int id, string name, int deptId, double basic, double allowance)
        : Employee(id, name, deptId, basic), allowance(allowance) {}

    double computeNetSalary() override {
        return basic + allowance;
    }

    void displayDetails() override {
        Employee::displayDetails();
        cout << "Position: HOD, Net Salary: " << computeNetSalary() << endl;
    }
};

// Derived Class: Visiting Faculty
class VisitingFaculty : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    VisitingFaculty(int id, string name, int deptId, double hourlyRate, int hoursWorked)
        : Employee(id, name, deptId, 0), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double computeNetSalary() override {
        return hourlyRate * hoursWorked;
    }

    void displayDetails() override {
        Employee::displayDetails();
        cout << "Position: Visiting Faculty, Net Salary: " << computeNetSalary() << endl;
    }
};

// Function to check type using RTTI
void checkType(Employee* emp) {
    if (typeid(*emp) == typeid(HOD)) {
        cout << "This employee is an HOD.\n";
    } else if (typeid(*emp) == typeid(VisitingFaculty)) {
        cout << "This employee is a Visiting Faculty.\n";
    } else {
        cout << "Unknown Employee Type.\n";
    }
}

// Function to create Employee dynamically
unique_ptr<Employee> createEmployee() {
    int choice;
    cout << "\nSelect Employee Type:\n1. HOD\n2. Visiting Faculty\nChoice: ";
    cin >> choice;

    int id, deptId;
    string name;
    double basic;

    cout << "Enter Employee ID: ";
    cin >> id;
    cin.ignore(); // Clear input buffer
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Department ID: ";
    cin >> deptId;

    if (choice == 1) { // HOD
        double allowance;
        cout << "Enter Basic Salary: ";
        cin >> basic;
        cout << "Enter Allowance: ";
        cin >> allowance;
        return make_unique<HOD>(id, name, deptId, basic, allowance);
    } else if (choice == 2) { // Visiting Faculty
        double hourlyRate;
        int hoursWorked;
        cout << "Enter Hourly Rate: ";
        cin >> hourlyRate;
        cout << "Enter Hours Worked: ";
        cin >> hoursWorked;
        return make_unique<VisitingFaculty>(id, name, deptId, hourlyRate, hoursWorked);
    } else {
        cout << "Invalid choice! Employee not created.\n";
        return nullptr;
    }
}

// Main function
int main() {
    vector<unique_ptr<Employee>> employees;

    int num;
    cout << "How many employees do you want to add? ";
    cin >> num;

    for (int i = 0; i < num; ++i) {
        cout << "\nAdding Employee " << i + 1 << ":\n";
        auto emp = createEmployee();
        if (emp) {
            employees.push_back(move(emp));
        }
    }

    cout << "\nEmployee Details:\n";
    for (const auto& emp : employees) {
        emp->displayDetails();
        checkType(emp.get());
        cout << "------------------------\n";
    }

    return 0;
}
