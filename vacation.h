
#ifndef PROIECT_VACATION_H
#define PROIECT_VACATION_H
#include <string>
#include <ostream>
#include "date.h"


class Vacation{
private:
    std::string department;
    int employeeID;
    Date startDate;
    Date endDate;
    bool status;
public:
    Vacation( int EmployeeID, const std::string &Department, const Date &StartDate, const Date &EndDate, bool Status = false)
            :  employeeID(EmployeeID), department(Department), startDate(StartDate), endDate(EndDate), status(Status) {

    }

//    ~Vacation() ;
    Vacation() = default;
    Vacation(const Vacation &other) : Vacation( other.employeeID,other.department, other.startDate, other.endDate, other.status) {

    }

    friend std::ostream &operator<<(std::ostream &os, const Vacation &vacation) {
        os << "department: " << vacation.department << " employeeID: " << vacation.employeeID << " startDate: "
           << vacation.startDate << " endDate: " << vacation.endDate << " status: " << vacation.status;
        return os;
    }

    const std::string &getDepartment() const {
        return department;
    }

    void setDepartment(const std::string &department) {
        Vacation::department = department;
    }

    int getEmployeeId() const {
        return employeeID;
    }

    void setEmployeeId(int employeeId) {
        employeeID = employeeId;
    }

    const Date &getStartDate() const {
        return startDate;
    }

    void setStartDate(const Date &startDate) {
        Vacation::startDate = startDate;
    }

    const Date &getEndDate() const {
        return endDate;
    }

    void setEndDate(const Date &endDate) {
        Vacation::endDate = endDate;
    }

    bool isStatus() const {
        return status;
    }

    void setStatus(bool status) {
        Vacation::status = status;
    }

    friend class Planner;


};


#endif
