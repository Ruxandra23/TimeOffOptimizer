#ifndef PROIECTPOO_LEAVE_FACTORY_H
#define PROIECTPOO_LEAVE_FACTORY_H
#include "include.h"
#include "planner.h"

class LeaveFactory {
public:
    static Leave* createLeave(const std::string &type, int employee_Id, const std::string &name,
                              const std::string &department, const Date &startDate, const Date &endDate,int sick_Leave_Days, int casual_Leave_Days, int maternity_Leave_Days, Planner* planner);

};

#endif