/*
Create an Employee hierarchy. Each employee has a name, an ID, and possibly different forms of compensation (salary, hourly wage, commission). There’s a base class Employee and derived classes:
    SalariedEmployee: has an annual salary.
    HourlyEmployee: has an hourly wage + hours worked.
    CommissionEmployee: has a base salary + commission rate + sales.
We want a payroll system to compute each employee’s paycheck. Also, we might have special rules for printInfo() or for calculatePay().
*/
/*********************************************************
 * EmployeeManagement.cpp
 * Demonstrates an Employee system with polymorphic pay
 * calculation (Salaried, Hourly, Commission).
 *********************************************************/

 #include <iostream>
 #include <string>
 #include <vector>
 #include <memory>
 #include <iomanip>
 
 //------------------------------------------------
 // 1) Abstract Base: Employee
 //------------------------------------------------
 class Employee {
 protected:
     int id;
     std::string name;
 
 public:
     Employee(int i, const std::string& n)
         : id(i), name(n) {}
 
     virtual ~Employee() {}
 
     virtual double calculatePay() const = 0;  // pure virtual
 
     virtual void printInfo() const {
         std::cout << "[Employee] ID=" << id
                   << ", Name=" << name;
     }
 };
 
 //------------------------------------------------
 // 2) Derived: SalariedEmployee
 //------------------------------------------------
 class SalariedEmployee : public Employee {
 private:
     double annualSalary;
 
 public:
     SalariedEmployee(int i, const std::string& n, double salary)
         : Employee(i, n), annualSalary(salary)
     {}
 
     double calculatePay() const override {
         // let's assume monthly pay
         return annualSalary / 12.0;
     }
 
     void printInfo() const override {
         std::cout << "[Salaried] ";
         Employee::printInfo();
         std::cout << ", AnnualSalary=" << annualSalary;
         std::cout << " => MonthlyPay=" << calculatePay() << "\n";
     }
 };
 
 //------------------------------------------------
 // 3) Derived: HourlyEmployee
 //------------------------------------------------
 class HourlyEmployee : public Employee {
 private:
     double hourlyRate;
     int hoursWorked;
 
 public:
     HourlyEmployee(int i, const std::string& n,
                    double rate, int hours)
         : Employee(i, n), hourlyRate(rate), hoursWorked(hours)
     {}
 
     double calculatePay() const override {
         // simple: rate * hours
         // (no overtime logic for brevity)
         return hourlyRate * hoursWorked;
     }
 
     void printInfo() const override {
         std::cout << "[Hourly] ";
         Employee::printInfo();
         std::cout << ", Rate=" << hourlyRate
                   << ", Hours=" << hoursWorked
                   << " => Pay=" << calculatePay() << "\n";
     }
 };
 
 //------------------------------------------------
 // 4) Derived: CommissionEmployee
 //------------------------------------------------
 class CommissionEmployee : public Employee {
 private:
     double baseSalary;
     double commissionRate;
     double totalSales;
 
 public:
     CommissionEmployee(int i, const std::string& n,
                        double baseSal, double rate, double sales)
         : Employee(i,n), baseSalary(baseSal),
           commissionRate(rate), totalSales(sales)
     {}
 
     double calculatePay() const override {
         return baseSalary + commissionRate * totalSales;
     }
 
     void printInfo() const override {
         std::cout << "[Commission] ";
         Employee::printInfo();
         std::cout << ", Base=" << baseSalary
                   << ", Rate=" << commissionRate
                   << ", Sales=" << totalSales
                   << " => Pay=" << calculatePay() << "\n";
     }
 };
 
 //------------------------------------------------
 // 5) Manager: PayrollManager
 //------------------------------------------------
 class PayrollManager {
 private:
     std::vector<std::unique_ptr<Employee>> emps;
 
 public:
     void addEmployee(std::unique_ptr<Employee> e) {
         emps.push_back(std::move(e));
     }
 
     double totalPayout() const {
         double sum=0.0;
         for(const auto &e : emps) {
             sum += e->calculatePay();
         }
         return sum;
     }
 
     void printAll() const {
         std::cout << "\n=== Employee List ===\n";
         for(const auto &e : emps) {
             e->printInfo();
         }
     }
 };
 
 //------------------------------------------------
 // main() - Test
 //------------------------------------------------
 int main() {
     PayrollManager manager;
 
     // Create employees
     auto emp1 = std::make_unique<SalariedEmployee>(1, "Alice", 60000.0);
     auto emp2 = std::make_unique<HourlyEmployee>(2, "Bob", 20.0, 160);
     auto emp3 = std::make_unique<CommissionEmployee>(3, "Charlie", 2000.0, 0.1, 15000.0);
 
     manager.addEmployee(std::move(emp1));
     manager.addEmployee(std::move(emp2));
     manager.addEmployee(std::move(emp3));
 
     manager.printAll();
 
     std::cout << std::fixed << std::setprecision(2);
     std::cout << "Total payout this period: $" << manager.totalPayout() << "\n";
 
     return 0;
 }
 