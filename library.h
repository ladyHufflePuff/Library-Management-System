#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include <string>
#include <vector>
#include "date.h"

/*
library.h
Author Student Number: M00857430
Created: 27/12/2023
Updated: 08/01/2024
*/

class Member;
class Book;

class Person /*class name*/
{
private:
    /*private member attributes*/
   std::string name;
   std::string address;
   std::string email;

public:
    /*public member functions*/
    std::string getName();
    void setName(std::string name);
    std::string getAddress();
    void setAddress(std::string address);
    std::string getEmail();
    void setEmail(std::string email);
};

class Librarian : public Person /*class name*/
{
private:
    /*private member attributes*/
   int staffId;
   int salary;
    
public:
    Librarian(int staffId, std::string name, std::string address, std::string email, int salary); /*constructor*/

    /*public member functions*/
    void addMember();
    void issueBook(int memberID, int bookID);
    void returnBook (int memberID, int bookID);
    void displayBorrowedBooks(int memberID);
    void calcFine(int memberID);
    int getStaffID();
    void setStaffID(int staffId);
    int getSalary();
    void setSalary(int salary);
};

class Member : public Person /*class name*/
{
private:
    /*private member attributes*/
    int memberID;
    std::vector<Book> booksLoaned;
public:
    Member(int memberID, std::string name, std::string address, std::string email); /*constructor*/

    /*public member functions*/
    std::string getMemberID();
    std::vector<Book>& getBooksBorrowed();
    void setBooksBorrowed(Book book); 
};

class Book /*class name*/
{
private:
    /*private member attributes*/
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    int pageCount;
    Date dueDate; 
    Member* borrower;
public:
    Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName); /*constructor*/

    /*public member functions*/
    std::string getBookID();
    std::string getBookName();
    std::string getAuthorFirstName();
    std::string getAuthorLastName();
    Date getDueDate();
    void setDueDate(Date dueDate);
    void returnBook();
    void borrowBook(Member* borrower, Date dueDate);
};
#endif