#ifndef PROIECTPOO_EMPLOYEE_H
#define PROIECTPOO_EMPLOYEE_H

#include "include.h"
#include "planner.h"
#include "date.h"
#include "leave_factory.h"

class LeaveFactory;

template<typename T>
class Employee {
private:
    int employee_Id;
    std::string name;
    std::string department;
    T age;
    int sick_Leave_Days;
    int casual_Leave_Days;
    int maternity_Leave_Days;

public:
    Employee();

    Employee(int Employee_Id, std::string Name, std::string Department, T age, int Sick_Leave_Days,
             int Casual_Leave_Days, int Maternity_Leave_Days);


    void askForLeave(const std::string &leaveType, const Date &startDate, const Date &endDate, Planner *planner);

    [[nodiscard]] const std::string &getName() const;

    [[nodiscard]] int getEmployeeId() const;

    [[nodiscard]] const std::string &getDepartment() const;

    [[nodiscard]] T getAge() const;

    [[nodiscard]] int getSickLeaveDays() const;

    [[nodiscard]] int getCasualLeaveDays() const;

    [[nodiscard]] int getMaternityLeaveDays() const;

    friend std::ostream &operator<<(std::ostream &os, const Employee &employee) {
        os << "employee_Id: " << employee.employee_Id << " name: " << employee.name << " department: "
           << employee.department << " age: " << employee.age << " sick_Leave_Days: " << employee.sick_Leave_Days
           << " casual_Leave_Days: " << employee.casual_Leave_Days << " maternity_Leave_Days: "
           << employee.maternity_Leave_Days;
        return os;
    }
};

template<typename T>
Employee<T>::Employee() : employee_Id(0), name(""), department(""), age(T()), sick_Leave_Days(12),
                          casual_Leave_Days(21), maternity_Leave_Days(360) {}

template<typename T>
Employee<T>::Employee(int Employee_Id, std::string Name, std::string Department, T Age, int Sick_Leave_Days,
                      int Casual_Leave_Days, int Maternity_Leave_Days)
        : employee_Id(Employee_Id), name(std::move(Name)), department(std::move(Department)), age(Age),
          sick_Leave_Days(Sick_Leave_Days), casual_Leave_Days(Casual_Leave_Days),
          maternity_Leave_Days(Maternity_Leave_Days) {}

template<typename T>
void
Employee<T>::askForLeave(const std::string &leaveType, const Date &startDate, const Date &endDate, Planner *planner) {
    Leave *leave = LeaveFactory::createLeave(leaveType, employee_Id, name, department, startDate, endDate,
                                             sick_Leave_Days, casual_Leave_Days, maternity_Leave_Days, planner);
    if (leave != nullptr) {
        if (leaveType == "sick") {
            sick_Leave_Days = leave->getNumberOfLeaveDays();
        } else if (leaveType == "casual") {
            casual_Leave_Days = leave->getNumberOfLeaveDays();
        } else if (leaveType == "maternity") {
            maternity_Leave_Days = leave->getNumberOfLeaveDays();
        }

    } else {
        std::cout << "Invalid leave type" << std::endl;
    }
}




    template<typename T>
const std::string &Employee<T>::getName() const {
    return name;
}

template<typename T>
int Employee<T>::getEmployeeId() const {
    return employee_Id;
}

template<typename T>
const std::string &Employee<T>::getDepartment() const {
    return department;
}

template<typename T>
T Employee<T>::getAge() const {
    return age;
}

template<typename T>
int Employee<T>::getSickLeaveDays() const {
    return sick_Leave_Days;
}

template<typename T>
int Employee<T>::getCasualLeaveDays() const {
    return casual_Leave_Days;
}

template<typename T>
int Employee<T>::getMaternityLeaveDays() const {
    return maternity_Leave_Days;
}

#endif
