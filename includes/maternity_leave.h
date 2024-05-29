
#ifndef PROIECTPOO_MATERNITY_LEAVE_H
#define PROIECTPOO_MATERNITY_LEAVE_H
#include "include.h"
#include "leave.h"
#include "date.h"
class maternityLeave : public Leave {
private:
    bool near_Childbirth;

public:
    maternityLeave(int Employee_Id, std::string Name, std::string Department, const Date &Start_Date,
                   const Date &End_Date, bool Status = false,
                   int Number_Of_Leave_Days = 360, bool Near_Childbirth = false);

    maternityLeave();

    void update_Leave_Days(int days) override;
    bool is_Approved() override;
    bool request_Leave(const Date &startDate, const Date &endDate) override;

    bool isNearChildbirth() const;
};

#endif
