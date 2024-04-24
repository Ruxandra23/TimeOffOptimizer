#include "casual_leave.h"
#include "planner.h"
casualLeave::casualLeave(int Employee_Id, std::string Name, std::string Department, const Date &Start_Date,
                         const Date &End_Date, bool Status, Planner *planner, int Number_Of_Leave_Days, bool IsPossible)
        : Leave(Employee_Id, Name, Department, Start_Date, End_Date, Status, Number_Of_Leave_Days),
          isPossible{IsPossible}, planner{planner} {}
 void casualLeave::update_Leave_Days(int days) {
     days = Date::count_number_of_days(this->start_Date, this->end_Date);
     this->number_Of_Leave_Days -= days;
 }

 bool casualLeave::is_Approved() {
     if(isPossible == true)
         this->status = true;
     else
         this->status = false;
     return this->status;
 }
 bool casualLeave::request_Leave(const Date &startDate, const Date &endDate) {
     int days_requested = Date::count_number_of_days(startDate, endDate);
     if (days_requested <= number_Of_Leave_Days) return true;
     return false;
 }
bool casualLeave::checkAvailability(const Date &startDate, const Date &endDate) {
    isPossible = true;
    for (const auto& leave : planner->getListofLeaves()) {
        if ((startDate >= leave->getStartDate() && startDate <= leave->getEndDate()) ||
            (endDate >= leave->getStartDate() && endDate <= leave->getEndDate())) {
            isPossible = false;
            break;
        }
    }
    return isPossible;
}

casualLeave::casualLeave() : Leave(), isPossible(false), planner(nullptr) {}
