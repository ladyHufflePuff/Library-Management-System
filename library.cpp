#include "library.h"
#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

/*
library.cpp
Author Student Number: M00857430
Created: 27/12/2023
Updated: 13/01/2024
*/
/*vector to store added members*/
std::vector<Member> members;

/*
 Getter function for retrieving the name of the person.
 @return The name of the person.
*/
std::string Person::getName()
{
  return name;
}
/*
 Setter function for updating the name of the person.
 @param name The new name to be set for the person.
*/
void Person::setName(std::string name)
{
  this->name = name;
}
/*
 Getter function for retrieving the address of the person.
 @return The address of the person.
*/
std::string Person::getAddress()
{
  return address;
}
/*
 Setter function for updating the address of the person.
 @param address The new address to be set for the person.
*/
void Person::setAddress(std::string address)
{
  this->address = address;
}
/*
 Getter function for retrieving the email of the person.
 @return The email of the person.
*/
std::string Person::getEmail()
{
  return email;
}
/*
 Setter function for updating the email of the person.
 @param email The new email to be set for the person.
*/
void Person::setEmail(std::string email)
{
  this->email = email;
}

/*
 Initializes librarian object with provided staff Id, nam, address, email and salary
 @param staffId The unique identifier for the librarian.
 @param name The name of the librarian.
 @param address The address of the librarian.
 @param email The email of the librarian.
 @param salary The salary of the librarian.
*/
Librarian::Librarian(int staffId, std::string name, std::string address, std::string email, int salary) 
{
  this->staffId = staffId;
  setName(name);
  setAddress(address);
  setEmail(email);
  this->salary = salary;

}
/*
 Adds new member to library and displays thier details
*/
void Librarian::addMember()
{
  int memberID;
  std::string name, address, email;

  while (true)
  {
    std::cout << "Enter the member ID: ";
    std::string entry;
    std::getline(std::cin, entry);

    // member ID entry validation
    bool isValidID = true;
    for (char ch : entry)
    {
      if (!std::isdigit(ch))
      {
        isValidID = false;
        break;
      }
    }
    if (!isValidID)
    {
      std::cout << "\033[1;31m" << "Invalid input. Please enter a valid integer." << "\033[0m" << std::endl;
    }
    else
    {
      memberID = std::stoi(entry); // converting valid string input to integer
      break;
    }
  }

  while (true)
  {
    std::cout << "Enter the name: ";
    std::getline(std::cin, name);

    // member name entry validation
    bool isValidName = true;
    for (char ch : name)
    {
      if (!std::isalpha(ch))
      {
        isValidName = false;
        break;
      }
    }
    if (!isValidName)
    {
      std::cout << "\033[1;31m" << "Invalid input. Please enter a valid name" << "\033[0m" << std::endl;   
    }
    else
    {  
      break;
    }
  }

  while (true)
  {
    std::cout << "Enter the address: ";
    std::getline(std::cin, address);

    // member address entry validation
    bool isValidAddress = true;
    for (char ch : address)
    {
      if (!std::isalpha(ch))
      {
        isValidAddress = false;
        break;
      }
    }
    if (!isValidAddress)
    {
      std::cout << "\033[1;31m" << "Invalid input. Please enter a valid address" << "\033[0m" << std::endl;  
    }
    else
    {
      break;
    }
  }
  
  while (true)
  {
    std::cout << "Enter the email: ";
    std::getline(std::cin, email);

    // member email entry validation
    std::regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})"); 
    if (!std::regex_match(email, emailPattern))
    {
      std::cout << "\033[1;31m" << "Invalid input. Please enter a valid email address!" << "\033[0m" << std::endl;
    }
    else
    {
      break;
    }
  }
  
  Member newMember (memberID, name, address, email);
  members.push_back(newMember);

  // Displaying details of newly added member
  std::cout << "\033[1;32m" <<"A new member has been added successfully!" << "\033[0m" << std::endl;
  std::cout << "Member ID: " << newMember.getMemberID() << std::endl;
  std::cout << "Name: " << newMember.getName() << std::endl;
  std::cout << "Address: " << newMember.getAddress() << std::endl;
  std::cout << "Email: " << newMember.getEmail() << std::endl;
}

/*
 Issues a book to a library member.
 @param memberID The ID of the library member.
 @param bookID The ID of the book to be issued.
*/
void Librarian::issueBook(int memberID, int bookID)
{
  // find borrower in collection of members
  std::string memberId = std::to_string(memberID);
  Member* borrower = nullptr;
  for (Member& member :members) {
    if (member.getMemberID() == memberId) {
      borrower = &member;
    break;
    } 
  }
  if (borrower == nullptr)
  {
    std::cout << "\033[1;31m" << "Member with ID " << memberID << " not found!" << "\033[0m" << std::endl;
    return;
  }
  
    // get filename to retreive book to be issued
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    std::fstream file(filename, std::ios::in);

    // file status validation
    if (!file.is_open())
    {
        std::cout <<  "Could not open the file" << std::endl;
        return;
    } 
    std::string line;
    bool isFirstLine = true; 
    
    // read file
    while (getline(file, line))
    {
        if (isFirstLine)
        {
        isFirstLine = false;
        continue; // Skip the header line
        }
        std::stringstream str(line);
        std::string content;
        int currentbookID;
        std::string bookName, authorFirstName, authorLastName;
        
        if (getline(str, content, ','))
        {
            currentbookID = std::stoi(content);
        }
        if (currentbookID == bookID)
        { 
            //extract book details    
            if (getline(str, content, ','))
            {
                if (content.front() == '\"')
                {
                    bookName = content.substr(1); 
                    while (getline(str, content, ','))
                    {
                        bookName += ',' + content;  
                        if (content.back() == '\"')
                        {
                            bookName.pop_back();
                            break;  
                        }
                    }
                }
                else
                {
                    bookName = content;
                }
            } 
            getline(str, content, ',');
            if (getline(str, content, ','))
            {
                authorFirstName = content;
            }
            if (getline(str, content, ','))
            {
                authorLastName = content;
            }
            Book book(currentbookID,bookName,authorFirstName,authorLastName);
            
            Date date;
            int day, month, year;
            std::cout << "Enter book issue date (dd mm yyyy):";
            std::cin >> day >> month >> year;
            date.setDay(day);
            date.setMonth(month);
            date.setYear(year);
           
            // calculate due date for the book
            int dueDay = date.getDay() + 3;
            int dueMonth = date.getMonth();
            int dueYear = date.getYear();
            while (dueDay > 30) 
            {
                dueDay -= 30;
                dueMonth += 1;
                if (dueMonth > 12)
                {
                    dueMonth = 1;
                    dueYear += 1;
                }
            }
            Date dueDate(dueDay, dueMonth, dueYear);
            book.setDueDate(dueDate);
            book.borrowBook(borrower,dueDate);
            borrower->setBooksBorrowed(book);
            std::cout << "\033[1;32m"<< "Book successfully Issued !" << "\033[0m" << std::endl;
            break;
        }
    }
    file.close();
}


/*
 Returns a book previously issued to a library member.
 @param memberID The ID of the library member.
 @param bookID The ID of the book to be returned.
*/
void Librarian::returnBook(int memberID, int bookID)
{
  std::string memberId = std::to_string(memberID);
  std::string bookId = std::to_string(bookID);
  //find borrower from collection of members  
  Member* borrower = nullptr;
  for (Member& member : members) {
    if (member.getMemberID() == memberId) {
      borrower = &member;
    break;
    } 
  } 
  // borrower validation
  if(borrower == nullptr)
  {
    std::cout << "\033[1;31m" << "Member with ID " << memberID << " not found!" << "\033[0m" << std::endl;
    return;
  }
  else
  {
    std::vector<Book>& borrowedBooks = borrower->getBooksBorrowed();
    Date date;
    date.currentDate();
    // book validation
    auto iterator =std::remove_if(borrowedBooks.begin(),borrowedBooks.end(),[bookId, &date, memberID, this](Book& book)
    {
      Date dueDate = book.getDueDate();
      if (date.compare( dueDate) != 0)
      {
        calcFine(memberID);
        book.returnBook();
      }
      return book.getBookID() == bookId;
    });
    if (iterator != borrowedBooks.end()) 
    {
      borrowedBooks.erase(iterator);
      std::cout << "\033[1;32m" << "Book with ID " << bookID << " successfully returned!" << "\033[0m" << std::endl;
    }  
    else 
    {
      std::cout << "\033[1;31m" << "Book with ID " << bookID << " not borrowed " << "\033[0m"  << std::endl;
    }
  }
  
}


/*
 Displays books borrowed a library member.
 @param memberID The ID of the library member.
*/
void Librarian::displayBorrowedBooks(int memberID)
{  
  std::string memberId = std::to_string(memberID);
  // find borrower from collection of members
  Member* borrower = nullptr;
  for (Member& member : members) {
    if (member.getMemberID() == memberId) {
      borrower = &member;
      break;
    }
  }
  //borrower validation  
  if (borrower == nullptr) {
    std::cout << "\033[1;31m" << "Member with ID " << memberID << " not found!" << "\033[0m" << std::endl;
    return;
  } 
  
  std::vector<Book> borrowedBooks = borrower->getBooksBorrowed();
  if (borrowedBooks.empty()) 
  {
    std::cout << "No books borrowed by member with ID " << memberID << std::endl;
  }
  else 
  {
    //display borrowed books details
    std::cout << "Borrowed books by member with ID " << memberID << ":" << std::endl;
    for ( auto& book : borrowedBooks) 
    {
      std::cout << "Book ID: " << book.getBookID() << std::endl;
      std::cout << "Book Name: " << book.getBookName() << std::endl;        
      std::cout << "Author: " << book.getAuthorFirstName() << " " << book.getAuthorLastName() << std::endl;
      std::cout << "Due date: ";
      book.getDueDate().show();
      std::cout << "===================" << std::endl;
    }
  }
}


/*
 calculates the fine for an overdue book borrowed a library member.
 @param memberID The ID of the library member.
*/
void Librarian::calcFine(int memberID)
{
  std::string memberId = std::to_string(memberID);
  // find borrower from collection of members
  Member* borrower = nullptr;
  for (Member& member : members) {
    if (member.getMemberID() == memberId) {
      borrower = &member;
      break;
    } 
  } 

  Date date;
  date.currentDate();
  int fine = 0;
  std::vector<Book>& borrowedBooks = borrower->getBooksBorrowed();
  for ( auto& book : borrowedBooks) 
  {
    //retreives due date of borrowed book
    Date dueDate = book.getDueDate();
    //checks if book is overdue
    if (date.compare(dueDate) !=0){
        for (int i=0; i< date.compare(dueDate); i++ )
        {
          fine +=1;
        }
    }
  }
  std::cout << "Total Fine: £" << fine << std::endl;
}

/*
 Getter function for retrieving the staaff ID of the Librarian.
 @return The staff ID of the Librarian.
*/
int Librarian::getStaffID()
{
  return staffId;
}

/*
 Setter function for updating the staff ID of the Librarian.
 @param staff ID The new staff ID to be set for the Librarian.
*/
void Librarian::setStaffID(int staffId)
{
  this->staffId = staffId;
}

/*
 Getter function for retrieving the salary of the Librarian.
 @return The salary of the Librarian.
*/
int Librarian::getSalary()
{
  return salary;
}

/*
 Setter function for updating the salary of the Librarian.
 @param salary The new salary to be set for the Librarian.
*/
void Librarian::setSalary(int salary)
{
  this->salary = salary;
}


/*
  Initializes a Member object with the provided memberID,name, address, and email.
  @param memberID The unique identifier of the member.
  @param name The name of the member.
  @param address The address of the member.
  @param email The email address of the member.
*/
Member::Member(int memberID, std::string name, std::string address, std::string email)
{
  this->memberID = memberID;
  setName(name);
  setAddress(address);
  setEmail(email);
}


/*
  Getter function for retrieving the member ID.
  @return The member ID.
*/
std::string Member::getMemberID()
{
  std::string memberId = std::to_string(memberID);
  return memberId;
}

/*
  Getter function for retrieving the vector of books borrowed by the member.
  @return Reference to the vector of books borrowed by the member.
*/
std::vector<Book>& Member::getBooksBorrowed()
{
  return booksLoaned;
}

/*
  Setter function for adding a book to the member's list of borrowed books.
  @param book The book to be added to the list.
*/
void Member::setBooksBorrowed(Book book)
{
  booksLoaned.push_back(book);
}


/*
  Initializes a Book object with the provided book ID, book name, and author information.
  @param bookID The unique identifier for the book.
  @param bookName The name of the book.
  @param authorFirstName The first name of the book's author.
  @param authorLastName The last name of the book's author.
*/
Book::Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName )
{
  this->bookID = bookID;
  this->bookName = bookName;
  this->authorFirstName = authorFirstName;
  this->authorLastName = authorLastName;
  
}


/*
  Getter function for retrieving the book ID.
  @return The book ID.
*/
std::string Book::getBookID()
{
  std::string bookId = std::to_string(bookID);
  return bookId;
}

/*
  Getter function for retrieving the book name.
  @return The name of the book.
*/
std::string Book::getBookName()
{
  return bookName;
}

/*
  Getter function for retrieving the author's first name.
  @return The first name of the book's author.
*/
std::string Book::getAuthorFirstName() 
{
  return authorFirstName;
}

/*
  Getter function for retrieving the author's last name.
  @return The last name of the book's author.
*/
std::string Book::getAuthorLastName()
{
  return authorLastName;
}

/*
  Getter function for retrieving the due date of the book.
  @return A pointer to the due date object.
*/
Date Book::getDueDate()
{
  return dueDate;
}

/*
  Setter function for updating the due date of the book.
  @param dueDate A pointer to the new due date for the book.
*/
void Book::setDueDate(Date dueDate)
{
  this->dueDate = dueDate;
}

/*
  Marks the book as returned by setting borrower and dueDate to nullptr.
*/
void Book::returnBook()
{
  borrower = nullptr;
  dueDate = Date();
}

/*
  Marks the book as borrowed by assigning the borrower and due date.
  @param borrower A pointer to the member borrowing the book.
  @param dueDate A pointer to the due date for the borrowed book.
*/
void Book::borrowBook(Member* borrower, Date dueDate)
{
  this->borrower = borrower;
  this->dueDate = dueDate;
}
