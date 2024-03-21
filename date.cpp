#include "date.h"
Date::Date(int Day, int Month, int Year):
        day{Day}, month{Month}, year{Year} {}


Date:: ~Date() = default;

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << date.day << "." << date.month << "." << date.year;
    return os;
}
std::istream &operator>>(std::istream &in, const Date &date){
    std::cout << "Day:";
    in >> date.day;
    std::cout << "Month:";
    in >> date.month;
    std::cout << "Year:";
    in >> date.year;
    return in;

}
int Date::count_number_of_days(const Date &date1,const Date &date2) {
    int months[12] = {31, 59, 90, 120, 151, 181, 212,243, 273, 304, 334, 365};
    long int no_of_days1=0, no_of_days2=0;
    no_of_days1 = 365 * date1.year;
    no_of_days1+= months[date1.month -1];
    no_of_days1+= date1.day;
    no_of_days2 = 365 * date2.year;
    no_of_days2+= months[date2.month -1];
    no_of_days2+= date2.day;
    return abs(no_of_days1-no_of_days2);


}

bool Date::operator==(const Date &rhs) const {
    return day == rhs.day &&
           month == rhs.month &&
           year == rhs.year;
}

bool Date::operator!=(const Date &rhs) const {
    return !(rhs == *this);
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}
