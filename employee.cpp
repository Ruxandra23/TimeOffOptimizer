#include "employee.h"
#include <expected>

Employee::Employee() :
        Employee(0,"None",30) {}


Employee::Employee( int EmployeeId,const std::string &Department, int Number_of_days):
        employeeId{EmployeeId}, department{Department}, number_of_days{Number_of_days} {}


Employee::Employee(const Employee &other) :
        employeeId{other.employeeId}, department{other.department}, number_of_days{other.number_of_days} {}

Employee& Employee::operator=(const Employee &other) {
    if(this == &other)
        return *this;
    else
    {
        this->number_of_days = other.number_of_days;
        this->department = other.department;
        this->employeeId = other.employeeId;
    }
    return *this;

}

std::ostream &operator<<(std::ostream &out, const Employee &employee) {
    out  << " employeeId: " << employee.employeeId << " department: " << employee.department
         << " number_of_days: " << employee.number_of_days;
    return out;
}
std::istream &operator>>(std::istream &in, Employee &employee) {
    std::cout << "EmployeeId:";
    in >> employee.employeeId;
    std::cout << "Department:";
    in >> employee.department;
    return in;

}
bool Employee::requestVacation(const Date &startDate, const Date &endDate) {
    int days_requested = Date::count_number_of_days(startDate, endDate);
    if (days_requested <= number_of_days) return 1;
    return 0;


}

int Employee::getEmployeeId() const {
    return employeeId;
}

void Employee::setEmployeeId(int employeeId) {
    Employee::employeeId = employeeId;
}

const std::string &Employee::getDepartment() const {
    return department;
}

void Employee::setDepartment(const std::string &department) {
    Employee::department = department;
}

int Employee::getNumberOfDays() const {
    return number_of_days;
}

void Employee::setNumberOfDays(int numberOfDays) {
    number_of_days = numberOfDays;
}
