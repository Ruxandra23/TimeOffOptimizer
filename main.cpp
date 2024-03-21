#include "date.h"
#include "employee.h"
#include "vacation.h"
#include "planner.h"
using namespace std;
int main() {
    Planner planner;
    int condition;
    do {
        std::cout << "Menu:" << std::endl;
        //std::cout << "1.Enter your details:" << std::endl;
        std::cout << "1.Create a vacation request:" << std::endl;
        //std::cout << "3.Processing your request..." << std::endl;
        std::cout << "2.Show all the upcoming vacations" << std::endl;
        std::cout << "3.Quit menu" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> condition;

        switch (condition) {

            case 1: {
                int empId;
                std::string department;
                std::cout<< "Enter your ID: ";
                std::cin >> empId;
                std::cout<< "Enter the department you belong to: ";
                std::cin >> department;
                Employee employee(empId,department);
                int Day,Month,Year, _day, _month, _year;
                std::cout << "First day of vacation:";
                std::cin >> Day;
                std::cout << "Month:";
                std::cin >> Month;
                std::cout << "Year:";
                std::cin >> Year;
                Date startDate(Day,Month,Year);
                std::cout << "Last day of vacation:";
                std::cin >> _day;
                std::cout << "Month:";
                std::cin >> _month;
                std::cout << "Year:";
                std::cin >> _year;
                Date endDate(_day,_month,_year);
                Vacation newvacation(empId,department,startDate,endDate);
                if(employee.requestVacation(startDate,endDate)==1)
                   {    planner.addVacation(newvacation);
                        std::cout << "Your request has been registered!" << std::endl;

                   }
                else  std::cout << "Insufficient days for vacation!" << std::endl;
                break;
            }
            case 2:{

                std::cout<<planner;
                break;
            }
            default:
                std::cout << "Not a valid option! Choose something else!";
                break;

        }

    }while(condition!=3);

    

// trebuie sa mai fac
//fct pt concediu medical
//fct pt sugestie concediu
}
