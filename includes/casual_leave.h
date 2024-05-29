
#ifndef PROIECTPOO_CASUAL_LEAVE_H
#define PROIECTPOO_CASUAL_LEAVE_H
#include "include.h"
#include "planner.h"
#include "date.h"

class casualLeave : public Leave {
private:
    Planner *planner;
    bool isPossible;
public:
    casualLeave();

    casualLeave(int Employee_Id, std::string Name, std::string Department, const Date &Start_Date, const Date &End_Date,
                bool Status = false, Planner* planner = nullptr,
                int Number_Of_Leave_Days = 21, bool IsPossible = false);

    void update_Leave_Days(int days) override;
    bool is_Approved() override;
    bool request_Leave(const Date &startDate, const Date &endDate) override;
    bool checkAvailability(const Date &startDate, const Date &endDate);


};

#endif
