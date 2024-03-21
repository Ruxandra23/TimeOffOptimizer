
#ifndef TIMEOFFOPTIMIZER_DATE_H
#define TIMEOFFOPTIMIZER_DATE_H
#include <iostream>
#include <cmath>
class Date{
private:
    int day;
    int month;
    int year;
public:

    Date() = delete;
    Date(int Day=0, int Month=1, int Year=0);

    ~Date();

    friend std::ostream &operator<<(std::ostream &os, const Date &date);
    friend std::istream &operator>>(std::istream &in, const Date &date);
    static int count_number_of_days(const Date &date1, const Date &date2);

    bool operator==(const Date &rhs) const;

    bool operator!=(const Date &rhs) const;

    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);


};

#endif
