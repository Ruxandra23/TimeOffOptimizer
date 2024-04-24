
#ifndef PROIECTPOO_EMPLOYEE_H
#define PROIECTPOO_EMPLOYEE_H
#include <iostream>
#include <string>
#include "leave.h"
#include "sick_leave.h"
#include "casual_leave.h"
#include "maternity_leave.h"
#include <vector>
#include <fstream>
#include <cstring>
class Employee{
private:
    int employee_Id;
    std::string name;
    std::string department;
    int sick_Leave_Days;
    int casual_Leave_Days;
    int maternity_Leave_Days;
public:
    Employee(int Employee_Id, std::string Name, std::string Department, int Sick_Leave_Days, int Casual_Leave_Days, int Maternity_Leave_Days);
    Employee();
    void askForLeave(const std::string &leaveType, const Date &startDate, const Date &endDate,Planner* planner);
//    static std::vector<Employee> readCSV(const std::string &filename);
    [[nodiscard]] const std::string &getName() const;

    [[nodiscard]] int getEmployeeId() const;

    [[nodiscard]] const std::string &getDepartment() const;

    [[nodiscard]] int getSickLeaveDays() const;

    [[nodiscard]] int getCasualLeaveDays() const;

    [[nodiscard]] int getMaternityLeaveDays() const;


};
#endif
