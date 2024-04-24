

#ifndef PROIECTPOO_PLANNER_H
#define PROIECTPOO_PLANNER_H
#include "leave.h"
#include "casual_leave.h"
#include "sick_leave.h"
#include "maternity_leave.h"
#include <vector>
#include <ostream>
#include <iostream>
class Planner{
    private:
    std::vector <Leave*> ListofLeaves;
    public:
    void addLeave(Leave* newLeave);
    void count_Leave_Types();
    friend std::ostream &operator<<(std::ostream &os, const Planner *planner);

    const std::vector<Leave *> &getListofLeaves() const;

};


#endif
