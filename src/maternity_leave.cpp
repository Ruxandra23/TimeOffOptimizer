#include "maternity_leave.h"

maternityLeave::maternityLeave(int Employee_Id, std::string Name, std::string Department, const Date &Start_Date,
                               const Date &End_Date, bool Status, int Number_Of_Leave_Days, bool Near_Childbirth)
        : Leave(Employee_Id, Name, Department, Start_Date, End_Date, Status, Number_Of_Leave_Days),
          near_Childbirth{Near_Childbirth} {}

void maternityLeave::update_Leave_Days(int days) {
    days = Date::count_number_of_days(this->start_Date, this->end_Date);
    this->number_Of_Leave_Days -= days;

}

bool maternityLeave::is_Approved() {
    std::cout << "Is the employee near childbirth? (1 for yes, 0 for no): ";
    std::cin >> near_Childbirth;
    if (near_Childbirth)
        this->status = true;
    else
        this->status = false;
    return this->status;
}

bool maternityLeave::request_Leave(const Date &startDate, const Date &endDate) {
    int days_requested = Date::count_number_of_days(startDate, endDate);
    if (days_requested <= number_Of_Leave_Days) return true;
    return false;
}

bool maternityLeave::isNearChildbirth() const {
    return near_Childbirth;
}

maternityLeave::maternityLeave() : Leave(), near_Childbirth(false) {}
