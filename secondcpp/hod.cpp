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
    double perfBonus;
    string currentTask;

public:
    // Constructor for HOD including perfBonus
    HOD(int id, string name, int deptId, double basic, double perfBonus)
        : Employee(id, name, deptId, basic), perfBonus(perfBonus) {}

    // Overriding computeNetSalary
    double computeNetSalary() override {
        return basic + perfBonus;
    }

    // Accepting a task
    void Accept_Task(const string& task) {
        currentTask = task;
        cout << "Task Assigned to " << name << ": " << currentTask << endl;
    }

    // Displaying details including net salary
    void displayDetails() override {
        Employee::displayDetails();
        cout << "Position: HOD, Net Salary: " << computeNetSalary() << endl;
        if (!currentTask.empty()) {
            cout << "Current Task: " << currentTask << endl;
        }
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
        double perfBonus;
        cout << "Enter Basic Salary: ";
        cin >> basic;
        cout << "Enter Performance Bonus: ";
        cin >> perfBonus;
        return make_unique<HOD>(id, name, deptId, basic, perfBonus);
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

    // Assign task to HOD using dynamic_cast
    for (const auto& emp : employees) {
        HOD* hod = dynamic_cast<HOD*>(emp.get());
        if (hod) {
            string task;
            cin.ignore();
            cout << "Assign a task to HOD " << hod->computeNetSalary() << ": ";
            getline(cin, task);
            hod->Accept_Task(task);
        }
    }

    cout << "\nFinal Employee Details After Task Assignment:\n";
    for (const auto& emp : employees) {
        emp->displayDetails();
        cout << "------------------------\n";
    }

    return 0;
}
