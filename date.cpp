#include <iostream>
#include <ctime>
#include "date.h"

/*
date.cpp 
Author Student Number: M00857430
Created: 08/01/2024
Updated: 13/01/2024
*/

/*
  Getter function for retrieving the day of the date.
  @return The day of the date.
*/
int Date::getDay() 
{
  return day; 
}

/*
  Getter function for retrieving the month of the date.
  @return The month of the date.
*/
int Date::getMonth() 
{ 
  return month; 
}

/*
  Getter function for retrieving the year of the date.
  @return The year of the date.
*/
int Date::getYear() 
{ 
  return year; 
}

/*
  Setter function for updating the day of the date.
  @param day The new day to be set for the date.
*/
void Date::setDay(int day) 
{ 
  this->day = day; 
}

/*
  Setter function for updating the month of the date.
  @param month The new month to be set for the date.
*/
void Date::setMonth(int month) 
{ 
  this->month = month; 
}

/*
  Setter function for updating the year of the date.
  @param year The new year to be set for the date.
*/
void Date::setYear(int year) 
{ 
  this->year = year; 
}

/*
  Updates the Date object with the current date.
*/
void Date::currentDate()
{
  std::time_t t = std::time(0);   // get time now
  std::tm* currentTime = std::localtime(&t);
  day = currentTime->tm_mday;
  month = currentTime->tm_mon + 1;
  year = currentTime->tm_year + 1900;      
  setDay(day);
  setMonth(month);
  setYear(year);
}

/*
 Compares the difference in days between a date instance and another date
 @param date the other date to be compared
 @return days the difference in the number of days between the two dates
*/
int Date::compare( Date& date)
 {
  int days1 = getDay() + getMonth() * 30 + getYear() * 365;
  int days2 = date.getDay() + date.getMonth() * 30 + date.getYear() * 365;
  int days = days1 - days2;
  if (days1 < days2){
    return days = 0;
  }
  else{
    return days;
  }
}

/*
  Displays the date in the format "day/month/year".
*/
void Date::show() { 
  std::cout << day << "/" << month << "/" << year << std::endl;
}

