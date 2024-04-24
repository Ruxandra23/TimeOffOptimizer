
#include "employee.h"
#include "planner.h"
#include <memory>
Employee::Employee(int Employee_Id, std::string Name, std::string Department, int Sick_Leave_Days,
                   int Casual_Leave_Days, int Maternity_Leave_Days)
        : employee_Id{Employee_Id}, name{std::move(Name)}, department{std::move(Department)},
          sick_Leave_Days{Sick_Leave_Days}, casual_Leave_Days{Casual_Leave_Days},
          maternity_Leave_Days{Maternity_Leave_Days} {}

void Employee::askForLeave(const std::string &leaveType, const Date &startDate, const Date &endDate, Planner *planner) {
    if (leaveType == "sick") {
        auto *leave1 = new sickLeave(employee_Id, name, department, startDate, endDate, false,12, false);
        if (leave1->request_Leave(startDate, endDate)) {
            if (leave1->is_Approved()) {
                leave1->update_Leave_Days(Date::count_number_of_days(startDate, endDate));
                sick_Leave_Days = leave1->getNumberOfLeaveDays();
                planner->addLeave(leave1);
            } else {
                std::cout << "Leave not approved" << std::endl;
            }
        }
    }

    if (leaveType == "casual") {
        auto *leave2 = new casualLeave(employee_Id, name, department, startDate, endDate, false, planner, 21, false);
        if (leave2->request_Leave(startDate, endDate)) {
            if (leave2->checkAvailability(startDate, endDate)) {
                if (leave2->is_Approved()) {
                    leave2->update_Leave_Days(Date::count_number_of_days(startDate, endDate));
                    casual_Leave_Days = leave2->getNumberOfLeaveDays();
                    planner->addLeave(leave2);
                } else {
                    std::cout << "Leave2 not approved" << std::endl;
                }
            }
        }
    }

    if (leaveType == "maternity") {
        auto *leave3 = new maternityLeave(employee_Id, name, department, startDate, endDate, false);
        if (leave3->request_Leave(startDate, endDate)) {
            if (leave3->is_Approved()) {
                leave3->update_Leave_Days(Date::count_number_of_days(startDate, endDate));
                maternity_Leave_Days = leave3->getNumberOfLeaveDays();
                planner->addLeave(leave3);
            } else {
                std::cout << "Leave3 not approved" << std::endl;
            }
        }
    }
}

//std::vector<Employee> Employee::readCSV(const std::string &filename) {
//    std::vector<Employee> employees;
//    std::string auxFileName = "../" + filename;
//    std::ifstream file(auxFileName);
//    std::string line;
//    std::getline(file,line);
//
//    while(std::getline(file,line)){
//        char *p = std::strtok(const_cast<char*>(line.c_str()), ",");
//        if(p)
//        {
//            Employee emp;
//            std::cout << p << "\n";
//            emp.employeeId = std::stoi(p);
//            p = std::strtok(nullptr,",");
//            if(p)
//            {
//                emp.department = p;
//                p = std::strtok(nullptr,",");
//                if(p)
//                {
//                    emp.number_of_days = std::stoi(p);
//                    employees.push_back(emp);
//                }
//
//            }
//        }
//    }
//    return employees;
//
//}
const std::string &Employee::getName() const {
    return name;
}

int Employee::getEmployeeId() const {
    return employee_Id;
}

const std::string &Employee::getDepartment() const {
    return department;
}

int Employee::getSickLeaveDays() const {
    return sick_Leave_Days;
}

int Employee::getCasualLeaveDays() const {
    return casual_Leave_Days;
}

int Employee::getMaternityLeaveDays() const {
    return maternity_Leave_Days;
}

Employee::Employee() {
    employee_Id = 0;
    name = "";
    department = "";
    sick_Leave_Days = 12;
    casual_Leave_Days = 21;
    maternity_Leave_Days = 360;

}




