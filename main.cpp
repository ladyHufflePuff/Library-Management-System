#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "library.h"

/*
main.cpp
Author Student Number: M00857430
Created: 08/01/2024
Updated: 13/01/2024
*/

int main()
{
    std::cout << "\033[1m";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "~~                           LIBRARY MANAGEMENT SYSTEM                        ~~" << std::endl;
    std::cout << "~~                              CST2550  COURSEWORK                           ~~" << std::endl;
    std::cout << "~~                                 BY M00857430                               ~~" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "\033[0m";
    
    std::cout << "Welcome to the Library Management System!" << std::endl;
    Librarian librarian(110, "John Wong", "98th avenue, Wall St", "john@barnes.org", 50000);
    while (true)
    {
        int choice;
        /*menu display*/
        std::cout << "___________________________________________________________" << std::endl;
        std::cout << "Please choose an option from the menu to proceed" << std::endl;
        std::cout << "1. Add Member" << std::endl;
        std::cout << "2. Issue Book" << std::endl;
        std::cout << "3. Return Book" << std::endl;
        std::cout << "4. Display Borrowed Books" << std::endl;
        std::cout << "5. Exit System" << std::endl;
        std::cout << "Enter your choice : ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
        if (choice == 1)
        {
            librarian.addMember();
            
        }

        if (choice == 2)
        {
            int memberID, bookID;
            std::cout << "Enter Member ID: ";
            std::cin >> memberID;
            std::cout << "Enter Book ID: ";
            std::cin >> bookID;
            librarian.issueBook(memberID, bookID);
        }

        if (choice == 3)
        {
            int memberID, bookID;
            std::cout << "Enter Member ID: ";
            std::cin >> memberID;
            std::cout << "Enter Book ID: ";
            std::cin >> bookID;
            librarian.returnBook(memberID,bookID);

        }
        
        if (choice == 4)
        {
            int memberID;
            std::cout << "Enter Member ID: ";
            std::cin >> memberID;
            librarian.displayBorrowedBooks(memberID);
        }

        if (choice == 5)
        {
            std::cout << "\033[1;32m" <<"You have sucessfully exit the Library Management System!" << "\033[0m" << std::endl;
            break;
        }
    }
    return 0;
}
