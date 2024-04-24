#ifndef PROIECTPOO_SICK_LEAVE_H
#define PROIECTPOO_SICK_LEAVE_H

#include "leave.h"

class sickLeave : public Leave {
private:
    int medical_Certificate_Id;

public:
    sickLeave();
    sickLeave(int Employee_Id, std::string Name, std::string Department, const Date &Start_Date, const Date &End_Date,
              bool Status = false,
              int Number_Of_Leave_Days = 12, int Medical_Certificate_Id = 0);


    void update_Leave_Days(int days) override;
    bool is_Approved() override;
    bool request_Leave(const Date &startDate, const Date &endDate) override;

    int getMedicalCertificateId() const;


};

#endif