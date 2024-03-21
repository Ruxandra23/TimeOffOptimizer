#include "date.h"
#include "employee.h"
#include "vacation.h"
#include "planner.h"
using namespace std;
int main() {

    cout << "Hello world";

//    int condition;
//    do {
//        std::cout << "Menu:" << std::endl;
//        //std::cout << "1.Enter your details:" << std::endl;
//        std::cout << "1.Create a vacation request:" << std::endl;
//        //std::cout << "3.Processing your request..." << std::endl;
//        std::cout << "2.Show all the upcoming vacations" << std::endl;
//        std::cout << "3.Quit menu" << std::endl;
//        std::cout << "Choose an option: ";
//        std::cin >> condition;
//
//        switch (condition) {
//
//            case 1: {
//                int empId;
//                std::string department;
//                std::cout<< "Enter your ID: ";
//                std::cin >> empId;
//                std::cout<< "Enter the department you belong to: ";
//                std::cin >> department;
//                Employee employee(empId,department);
//                break;
//            }
//            case 2: {
//                int Day,Month,Year, _day, _month, _year;
//                std::cout << "Enter details for your vacation request: " << std::endl;
//                std::cout << "First day of vacation:";
//                std::cin >> Day;
//                std::cout << "Month:";
//                std::cin >> Month;
//                std::cout << "Year:";
//                std::cin >> Year;
//                Date startDate(Day,Month,Year);
//                std::cout << "Last day of vacation:";
//                std::cin >> _day;
//                std::cout << "Month:";
//                std::cin >> _month;
//                std::cout << "Year:";
//                std::cin >> _year;
//                Date endDate(_day,_month,_year);
//                break;
//            }
//            case 3:{
//
//            }
//
//
//
//
//
//        }
//
//    }while(condition!=5);


    Vacation obj( 101,"FMI", Date(11, 03, 2024), Date(14, 03, 2024));
    Vacation obj2(102,"FMI",Date(11,03,2024),Date(14,03,2024));
      Planner planner;
      planner.addVacation(obj);
      planner.addVacation(obj2);

      cout << obj << endl << obj2;
//     planner.showVacations();

//      Employee emp1(123,"numedepartament",30);
//      Planner planner;
//      planner.addVacation(emp1.requestVacation(123,"FMI", Date(11,03,2024),Date(14,03,2024)));
//      planner.showVacations();


// trebuie sa mai fac
//fct pt concediu medical
//fct pt sugestie concediu
}
