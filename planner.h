
#ifndef TIMEOFFOPTIMIZER_PLANNER_H
#define TIMEOFFOPTIMIZER_PLANNER_H
#include "vacation.h"
#include "employee.h"
#include "date.h"
#include <vector>
#include <ostream>

class Planner{
private:
    std::vector <Vacation> ListofVacations;
public:
    friend class Employee;
    void addVacation(Vacation newVacation);
    friend std::ostream &operator<<(std::ostream &os, const Planner &planner);

    const std::vector<Vacation> &getListofVacations() const;

};

#endif
