
#ifndef PROIECTPOO_DATE_H
#define PROIECTPOO_DATE_H

#include <iostream>
#include <cmath>

class Date {
private:
    int day;
    int month;
    int year;
public:


    Date();
    Date(int Day, int Month, int Year);

    friend std::ostream &operator<<(std::ostream &os, const Date &date);

    friend std::istream &operator>>(std::istream &in, Date date);

    static int count_number_of_days(const Date &date1, const Date &date2);

    bool operator==(const Date &rhs) const;

    bool operator!=(const Date &rhs) const;

    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);
    bool operator>=(const Date& other) const;
    bool operator<=(const Date& other) const;


};

#endif
