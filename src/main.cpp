#include "../includes/include.h"
#include "../includes/planner.h"
#include "../includes/employee.h"
int main() {

    auto *planner = new Planner();

//    // Crearea angajaților'
////    Employee emp1(1, "John Doe", "IT", 0, 0, 0);
////    emp1.askForLeave("sick", Date(16, 04, 2023), Date(19, 04, 2023), planner);
////    std::cout << planner->getListofLeaves().size();
// // casualLeave leave1(1, "John Doe", "IT", Date(16, 04, 2023), Date(19, 04, 2023), false, 0, 0);
//// maternityLeave leave2(2, "Jane Doe", "HR", Date(16, 04, 2023), Date(19, 04, 2023), false);
//// if(leave2.is_Approved())
////     std::cout<<"Leave approved"<<std::endl;
//// else
////     std::cout<<"Leave not approved"<<std::endl;
//// leave2.update_Leave_Days(Date::count_number_of_days(Date(16, 04, 2023), Date(19, 04, 2023)));
//// std::cout<<leave2.getNumberOfLeaveDays()<<std::endl;
//sickLeave leave3(3, "John Doe", "IT", Date(15, 04, 2023), Date(19, 04, 2023));
////if(leave3.is_Approved())
////    std::cout<<"Leave approved"<<std::endl;
////else
////    std::cout<<"Leave not approved"<<std::endl;
//// leave3.update_Leave_Days(Date::count_number_of_days(Date(15, 04, 2023), Date(19, 04, 2023)));
//// std::cout<<leave3.getNumberOfLeaveDays()<<std::endl;
////std::cout<< leave3.request_Leave(Date(15, 06, 2023), Date(29, 06, 2023));
//planner->addLeave(&leave3);
//std::cout <<planner;
//casualLeave leave4(4, "Jane Doe", "HR", Date(23, 04, 2023), Date(31, 04, 2023), false, planner);
//std::cout << leave4.checkAvailability(Date(17, 04, 2023), Date(2112, 04, 2023));
//    return 0;
//Date date1(16, 04, 2023);
//std::cout << date1;
//Employee emp1(1, "John Doe", "IT",12,21,360);
//emp1.askForLeave("maternity", Date(16, 04, 2023), Date(19, 04, 2023), planner);


Employee <int> emp1(1, "John Doe", "IT", 39, 12, 21, 360);
emp1.askForLeave("maternity", Date(16, 04, 2023), Date(19, 04, 2023), planner);
std::cout << emp1.getMaternityLeaveDays() << std::endl;
std::cout << planner->getListofLeaves().size() << std::endl;
planner->count_Leave_Types();

//Employee <std::string> emp2(2, "Jane Doe", "HR", "thirty-nine", 12, 21, 360);

//    int type;
//    while(1){
//        std::cout << std::endl << "Enter the type of leave you want to request or zero for exit: " << std::endl;
//        std::cin >> type;
//        if(type == 0)
//            break;
//        Leave *leave = LeaveFactory::createLeave(type);
//        if(leave){
//           // leave->request_Leave(Date(16, 04, 2023), Date(19, 04, 2023));
//            planner->addLeave(leave);
//        }
//    }â
//    std::cout << "Exit..." << std::endl;

    return 0;
}