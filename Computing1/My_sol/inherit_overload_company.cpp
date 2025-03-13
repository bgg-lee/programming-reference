/*
📝 Problem 1: Company Management System
Objective: Implement a company management system with different types of employees.

📌 Problem Statement
Design a system where different types of employees (RegularEmployee, Manager, Intern) inherit from a base class Employee.
Each employee has a name, ID, and salary but different behaviors based on their position.

Requirements
Use inheritance to create RegularEmployee, Manager, and Intern classes.
Implement a static member to track the number of employees.
Use override to redefine calculateBonus() differently in each derived class.
Overload << to print employee details.
🔹 Employee Class (Base Class)
Attributes: name, id, salary
Methods:
calculateBonus() -> virtual
displayInfo() -> virtual
operator<< (friend function)
🔹 RegularEmployee Class
Inherits from Employee
Overrides calculateBonus() to return 10% of salary.
🔹 Manager Class
Inherits from Employee
Overrides calculateBonus() to return 20% of salary.
🔹 Intern Class
Inherits from Employee
Overrides calculateBonus() to return fixed $500.
*/
#include <iostream>
#include <vector>

using namespace std;

class Employee { // 추상클래스 = abstract class ( virtual func() = 0->pure virtual function을 포함한 class는 instance를 만들 수 없다! ex) Employee emp(); 이런 식 불가 Polymorphism으로 Employee* ptr = new Initern(~); 이런식의 표현은 가능)
protected:
    string name;
    int id;
    double salary;
    static int employeeCount;  // ✅ Static member

public:
    Employee(string n, int i, double s) : name(n), id(i), salary(s) {
        employeeCount++;
    }

    virtual ~Employee() { employeeCount--; }

    virtual double calculateBonus() const = 0; // ✅ Pure virtual function

    virtual void displayInfo() const {
        cout << "ID: " << id << ", Name: " << name << ", Salary: $" << salary << endl;
    }

    static int getEmployeeCount() { return employeeCount; }

    friend ostream& operator<<(ostream& os, const Employee& emp) {
        os << "ID: " << emp.id << ", Name: " << emp.name << ", Salary: $" << emp.salary;
        return os;
    }
};

int Employee::employeeCount = 0;

class RegularEmployee : public Employee {
public:
    RegularEmployee(string n, int i, double s) : Employee(n, i, s) {}

    double calculateBonus() const override {
        return salary * 0.1;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Bonus: $" << calculateBonus() << " (Regular Employee)" << endl;
    }
};

class Manager : public Employee {
public:
    Manager(string n, int i, double s) : Employee(n, i, s) {}

    double calculateBonus() const override {
        return salary * 0.2;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Bonus: $" << calculateBonus() << " (Manager)" << endl;
    }
};

class Intern : public Employee {
public:
    Intern(string n, int i, double s) : Employee(n, i, s) {}

    double calculateBonus() const override {
        return 500;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Bonus: $" << calculateBonus() << " (Intern)" << endl;
    }
};

int main() {
    vector<Employee*> employees;

    employees.push_back(new RegularEmployee("Alice", 101, 5000));
    employees.push_back(new Manager("Bob", 102, 8000));
    employees.push_back(new Intern("Charlie", 103, 2000));

    for (const auto& emp : employees) {
        cout << *emp << endl;
        emp->displayInfo();
        cout << "-----------------" << endl;
    }

    cout << "Total Employees: " << Employee::getEmployeeCount() << endl;

    for (auto emp : employees) {
        delete emp;
    }

    cout << "Total Employees: " << Employee::getEmployeeCount() << endl;
    return 0;
}
