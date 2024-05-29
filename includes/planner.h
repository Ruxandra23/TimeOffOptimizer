

#ifndef PROIECTPOO_PLANNER_H
#define PROIECTPOO_PLANNER_H
#include "include.h"
#include "leave.h"
#include "casual_leave.h"
#include "maternity_leave.h"
#include "sick_leave.h"
class Planner{
    private:
    std::vector <Leave*> ListofLeaves;
    public:
    explicit Planner(const std::vector<Leave *> &listofLeaves);

    void addLeave(Leave* newLeave);
    void count_Leave_Types();
    friend std::ostream &operator<<(std::ostream &os, const Planner *planner);
    Planner();
    [[nodiscard]] const std::vector<Leave *> &getListofLeaves() const;

};


#endif
