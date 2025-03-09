#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    int id;
    string department;
};

int main() {
    Employee employees[5];

    // Input employee details
    for (int i = 0; i < 5; i++) {
        cout << "Enter details for Employee " << i + 1 << ":\n";
        cout << "Employee Name: ";
        cin>> employees[i].name;
        cout << "Employee ID: ";
        cin >> employees[i].id;
    
        cout << "Department: ";
        cin>> employees[i].department;
        cout << endl;
    }

    // Display employee details
    cout << "\nEmployee Details:\n";
    cout << "-----------------------------------------\n";
    cout << "ID\tName\t\tDepartment\n";
    cout << "-----------------------------------------\n";

    for (int i = 0; i < 5; i++) {
        cout << employees[i].id << "\t" << employees[i].name << "\t\t" << employees[i].department << endl;
    }

    return 0;
}
