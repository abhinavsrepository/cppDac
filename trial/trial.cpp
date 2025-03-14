#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>


using namespace std;

class Employee{


    protected :
    int id ;
    int deptId;
    double basic;
    string name;

    public :
    Employee (int id, string name,int deptId ,double basic):
    id (id),name (name),deptId(deptId),basic(basic) {}

    virtual double computeNetSalary(){
        return 0;
    }


    virtual void displayDetails (){

        cout <<"ID:"<<id<<"Name:"<<name<<" Dept Id:"<<deptId<<endl;
    }

    virtual ~Employee(){}
};

class HOD : public Employee {
    private:
    double allowance;
    HOD(int id ,string name ,int deptId,double basic,double allowance):
    Employee(id, name,deptId,basic),allowance (allowance){}

    double computeNetSalary() override{
        return basic +allowance;

    }

    void displayDetails() override{
        Employee::displayDetails();

        cout<<"Position :Hod ,Net Salary"<<computeNetSalary()<<endl;
    }
};
class VisitingFaculty :public Employee {
    private :
    double hourlyRate;
    int hoursWorked;

    public:
    VisitingFaculty(int id ,string name ,int deptId,double hourlyRate,int hourseWorked){}

    double computeNetSalary() override {
        return hourlyRate * hoursWorked;



    }
    void displayDetails() override {
        Employee :: displayDetails();
        cout<< "Position :VIsiting Faculty Net Salayry"<<computeNetSalary()<<endl;
    }
};

void checkType (Employee * emp){
    if (typeid(*emp)== typeid(HOD)){
        cout<<"This employee is an HOD.\n";
    }
    else if (typeid(*emp) == typeid(VisitingFaculty)){
        cout<< "This employee is a visiting Faculty.\n";

    }
    else{
        cout<<"Unknown Employee Type.\n";
    }
}

unique_ptr<Employee> createEmployee(){
    int choice ;
    cout<< "Ele"
}