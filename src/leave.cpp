#include "../includes/planner.h"

Leave::Leave(int Employee_Id, std::string Name, std::string Department, const Date &Start_Date, const Date &End_Date,
             bool Status,
             int Number_Of_Leave_Days) :
        employee_Id{Employee_Id}, name{std::move(Name)}, department{std::move(Department)}, start_Date{Start_Date},
        end_Date{End_Date}, status{Status}, number_Of_Leave_Days{Number_Of_Leave_Days} {}

Leave::Leave(const Leave &other) :
        employee_Id{other.employee_Id}, name{other.name}, department{other.department}, start_Date{other.start_Date},
        end_Date{other.end_Date}, status{other.status}, number_Of_Leave_Days{other.number_Of_Leave_Days} {}

std::ostream &operator<<(std::ostream &os, const Leave &leave) {
    os << "employee_Id: " << leave.employee_Id << " name: " << leave.name << " department: " << leave.department
       << " start_Date: " << leave.start_Date << " end_Date: " << leave.end_Date << " status: " << leave.status
       << " number_Of_Leave_Days: " << leave.number_Of_Leave_Days;
    return os;
}

Leave &Leave::operator=(const Leave &other) {
    if (this == &other)
        return *this;
    else {
        this->employee_Id = other.employee_Id;
        this->name = other.name;
        this->department = other.department;
        this->start_Date = other.start_Date;
        this->end_Date = other.end_Date;
        this->status = other.status;
        this->number_Of_Leave_Days = other.number_Of_Leave_Days;
    }
    return *this;
}

void Leave::update_Leave_Days(int days) {
    days = Date::count_number_of_days(this->start_Date, this->end_Date);
    this->number_Of_Leave_Days -= days;
}

bool Leave::is_Approved() {
    return this->status;
}
bool Leave::request_Leave(const Date &startDate, const Date &endDate) {
    int days_requested = Date::count_number_of_days(startDate, endDate);
    if (days_requested <= number_Of_Leave_Days) return true;
    return false;
}
void Leave::templateMethod(const Date &startDate, const Date &endDate, Planner *planner) {
    if (this->request_Leave(startDate, endDate)) {
        if (this->is_Approved()) {
            this->update_Leave_Days(Date::count_number_of_days(startDate, endDate));
            planner->addLeave(this);
        }
    }
}
const Date &Leave::getStartDate() const {
    return start_Date;
}

const Date &Leave::getEndDate() const {
    return end_Date;
}

int Leave::getNumberOfLeaveDays() const {
    return number_Of_Leave_Days;
}

int Leave::getEmployeeId() const {
    return employee_Id;
}

const std::string &Leave::getName() const {
    return name;
}

const std::string &Leave::getDepartment() const {
    return department;
}

bool Leave::isStatus() const {
    return status;
}

Leave::Leave() : employee_Id(0), name(""), department(""), start_Date(), end_Date(), status(false), number_Of_Leave_Days(0) {}