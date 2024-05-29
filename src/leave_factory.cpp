#include "../includes/leave_factory.h"

Leave *LeaveFactory::createLeave(const std::string &type, int employee_Id, const std::string &name,
                                  const std::string &department, const Date &startDate, const Date &endDate,int sick_Leave_Days, int casual_Leave_Days, int maternity_Leave_Days, Planner *planner) {
    Leave *leave = nullptr;
    if (type == "sick") {
        leave = new sickLeave(employee_Id, name, department, startDate, endDate, false, 12, false);
        leave->templateMethod(startDate, endDate, planner);
    }
    else if (type == "casual") {
        leave = new casualLeave(employee_Id, name, department, startDate, endDate, false, planner, 21, false);
        leave->templateMethod(startDate, endDate, planner);

    }
    else if (type == "maternity") {
        leave = new maternityLeave(employee_Id, name, department, startDate, endDate, false);
        leave->templateMethod(startDate, endDate, planner);

    }
    return leave;
}

