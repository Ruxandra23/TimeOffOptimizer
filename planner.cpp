#include "planner.h"
void Planner::addVacation(Vacation newVacation) {
    bool ok = true;
    int n = this->ListofVacations.size();
    for (int i = 0 ; i < n; i++)
    {
        if((this->ListofVacations[i].startDate == newVacation.startDate) && (this->ListofVacations[i].endDate == newVacation.endDate ))
        {
            if( this->ListofVacations[i].department == newVacation.department)
            {
                ok = false;
                break;
            }
        }
    }
    if(ok) {
        newVacation.setStatus(true);
        ListofVacations.emplace_back(newVacation);
    }

}


std::ostream &operator<<(std::ostream &os, const Planner &planner) {
    int n = planner.ListofVacations.size();
    for (int i = 0 ; i < n; i++)
        os <<"Employee ID: " << planner.ListofVacations[i].getEmployeeId() <<" "<< "Departament: "<< planner.ListofVacations[i].getDepartment()<<" " <<
           "StartDate: "<<planner.ListofVacations[i].getStartDate() << " " <<"EndDate: "<<planner.ListofVacations[i].getEndDate() <<std::endl;
    return os;
}

const std::vector<Vacation> &Planner::getListofVacations() const {
    return ListofVacations;
}
