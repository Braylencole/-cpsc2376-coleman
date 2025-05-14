#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>

class Employee {
protected:
    std::string name;
    int id;

public:
    Employee(std::string name, int id) : name(std::move(name)), id(id) {}

    virtual ~Employee() = default; 

    virtual double calculateSalary() const = 0; 

    virtual void displayInfo() const {
        std::cout << "ID: " << id << ", Name: " << name;
    }
};

class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(std::string name, int id, double salary)
        : Employee(std::move(name), id), monthlySalary(salary) {
    }

    double calculateSalary() const override {
        return monthlySalary;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Salaried, Monthly Salary: $"
            << std::fixed << std::setprecision(2) << monthlySalary << std::endl;
    }
};

class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    HourlyEmployee(std::string name, int id, double rate, int hours)
        : Employee(std::move(name), id), hourlyRate(rate), hoursWorked(hours) {
    }

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Hourly, Hours Worked: " << hoursWorked
            << ", Hourly Rate: $" << std::fixed << std::setprecision(2)
            << hourlyRate << ", Salary: $" << calculateSalary() << std::endl;
    }
};

class CommissionEmployee : public Employee {
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(std::string name, int id, double base, double sales, double rate)
        : Employee(std::move(name), id), baseSalary(base), salesAmount(sales), commissionRate(rate) {
    }

    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Commission, Base Salary: $" << baseSalary
            << ", Sales: $" << salesAmount
            << ", Commission Rate: " << (commissionRate * 100) << "%"
            << ", Salary: $" << calculateSalary() << std::endl;
    }
};

void loadEmployees(const std::string& filename, std::vector<std::unique_ptr<Employee>>& employees) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type, name;
        int id;
        double salary1, salary2, salary3;

        iss >> type >> id >> name;

        if (type == "Salaried") {
            if (iss >> salary1) {
                employees.push_back(std::make_unique<SalariedEmployee>(name, id, salary1));
            }
        }
        else if (type == "Hourly") {
            int hours;
            if (iss >> salary1 >> hours) {
                employees.push_back(std::make_unique<HourlyEmployee>(name, id, salary1, hours));
            }
        }
        else if (type == "Commission") {
            if (iss >> salary1 >> salary2 >> salary3) {
                employees.push_back(std::make_unique<CommissionEmployee>(name, id, salary1, salary2, salary3));
            }
        }
        else {
            std::cerr << "Invalid employee type in file: " << type << std::endl;
        }
    }
}

int main() {
    std::vector<std::unique_ptr<Employee>> employees;
    loadEmployees("employees.txt", employees);

    std::cout << "Employee Payroll Details:\n";
    for (const auto& employee : employees) {
        employee->displayInfo();
    }

    return 0;
}
