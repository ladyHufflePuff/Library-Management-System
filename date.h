#ifndef _DATE_H_
#define _DATE_H_
# include <iostream>

/*
date.h Header file for date Abstract Data Type
Author Student Number: M00857430
Created: 07/01/2024
Updated: 13/01/2024
*/

class Date /*class name*/
{
private:
    /*private member attributes*/
    int day;
    int month;
    int year;

public:
    Date(int day=0, int month=0, int year=0)
    {
        this->day= day;
        this->month=month; 
        this->year=year; 
    }; /*constructor*/

    /*public member functions*/
    int getDay();
    int getMonth();
    int getYear();
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void currentDate();
    int compare( Date& date);
    void show();

};
#endif