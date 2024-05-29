#include "../includes/sick_leave.h"

sickLeave::sickLeave(int Employee_Id, std::string Name, std::string Department, const Date &Start_Date,
                     const Date &End_Date, bool Status,
                     int Number_Of_Leave_Days, int Medical_Certificate_Id) : Leave(Employee_Id, Name, Department,
                                                                                   Start_Date, End_Date, Status,
                                                                                   Number_Of_Leave_Days),
                                                                             medical_Certificate_Id{
                                                                                     Medical_Certificate_Id} {}


void sickLeave::update_Leave_Days(int days) {
    days = Date::count_number_of_days(this->start_Date, this->end_Date);
    this->number_Of_Leave_Days -= days;
}


bool sickLeave::is_Approved() {
    if (medical_Certificate_Id != 0)
        this->status = true;
    else
        this->status = false;
    return this->status;
}
bool sickLeave::request_Leave(const Date &startDate, const Date &endDate) {
    std::cout << "Enter the medical certificate id: ";
    std::cin >> medical_Certificate_Id;
    int days_requested = Date::count_number_of_days(startDate, endDate);
    if (days_requested <= number_Of_Leave_Days) return true;
    return false;
}

int sickLeave::getMedicalCertificateId() const {
    return medical_Certificate_Id;
}
sickLeave::sickLeave() : Leave(), medical_Certificate_Id(0) {}
