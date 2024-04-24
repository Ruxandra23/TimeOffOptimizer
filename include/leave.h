
#ifndef PROIECTPOO_LEAVE_H
#define PROIECTPOO_LEAVE_H

#include <string>
#include <ostream>
#include <utility>
#include "date.h"

class Leave {
protected:
    int employee_Id;
    std::string name;
    std::string department;
    Date start_Date;
    Date end_Date;
    bool status;
    int number_Of_Leave_Days;

public:

    Leave(int Employee_Id, std::string Name, std::string Department, const Date &Start_Date, const Date &End_Date,
          bool Status,
          int Number_Of_Leave_Days);

    Leave(const Leave &other);
    Leave();
    friend std::ostream &operator<<(std::ostream &os, const Leave &leave);

    Leave &operator=(const Leave &other);

    virtual void update_Leave_Days(int days) = 0;
    virtual bool is_Approved();
    virtual bool request_Leave(const Date &startDate, const Date &endDate) = 0;

    const Date &getStartDate() const;

    const Date &getEndDate() const;

    friend class Planner;

    int getNumberOfLeaveDays() const;

    int getEmployeeId() const;

    const std::string &getName() const;

    const std::string &getDepartment() const;

    bool isStatus() const;


};

#endif
