#include "../includes/planner.h"

void Planner::addLeave(Leave *newLeave) {
    if(newLeave->is_Approved())
        ListofLeaves.push_back(newLeave);
    else
        std::cout<<"Leave not approved"<<std::endl;

}
void Planner::count_Leave_Types() {
    int n = ListofLeaves.size();
    int sick = 0, casual = 0, maternity = 0;
    for (int i = 0; i < n; i++) {
        if (dynamic_cast<sickLeave *>(ListofLeaves[i])) {
            sick++;
        } else if (dynamic_cast<casualLeave *>(ListofLeaves[i])) {
            casual++;
        } else if (dynamic_cast<maternityLeave *>(ListofLeaves[i])) {
            maternity++;
        }
    }
    std::cout << "Sick leaves: " << sick << std::endl;
    std::cout << "Casual leaves: " << casual << std::endl;
    std::cout << "Maternity leaves: " << maternity << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Planner *planner) {
    int n = planner->ListofLeaves.size();
    for (int i = 0 ; i < n; i++)
        os <<"Employee ID: " << planner->ListofLeaves[i]->getEmployeeId() <<" "<< "Departament: "<< planner->ListofLeaves[i]->getDepartment()<<" " <<
           "StartDate: "<<planner->ListofLeaves[i]->getStartDate()<< " " <<"EndDate: "<<planner->ListofLeaves[i]->getEndDate()<<std::endl;
    return os;
}

const std::vector<Leave *> &Planner::getListofLeaves() const {
    return ListofLeaves;
}

Planner::Planner(const std::vector<Leave *> &listofLeaves) : ListofLeaves(listofLeaves) {}

Planner::Planner() {

}
