
#ifndef TIMEOFFOPTIMIZER_EMPLOYEE_H
#define TIMEOFFOPTIMIZER_EMPLOYEE_H
#include <iostream>
#include <string>
#include "vacation.h"
#include "date.h"
#include "planner.h"

class Employee{
private:
    int employeeId;
    std::string department;
    int number_of_days; // pentru fiecare angajat, am un numar standard de zile de concediu
    //trebuie sa mai fac o functie care sa actualizeze zilele de concediu dupa ce un angajat si-a luat concediu

public:
    //constr de intializare
    Employee();
    Employee(int EmployeeId,const std::string &Department, int Number_of_days=30);

    //constr copiere
    Employee(const Employee &other);

    //operator = de copiere
    Employee& operator=(const Employee &other);

    //destructor
    ~Employee() = default;

    friend std::ostream &operator<<(std::ostream &out, const Employee &employee);
    friend std::istream &operator>>(std::istream &in,  Employee &employee);

    Vacation requestVacation(const Date &startDate, const Date &endDate);


    int getEmployeeId() const;

    void setEmployeeId(int employeeId);

    const std::string &getDepartment() const;

    void setDepartment(const std::string &department);

    int getNumberOfDays() const;

    void setNumberOfDays(int numberOfDays);


};


#endif
