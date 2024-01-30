#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "library.h"

/*
Catch2 test
Author Student Number: M00857430
Created: 12/01/2024
Updated: 15/01/2024
*/


TEST_CASE("Test addMember function", "[addMember]")
{
    Librarian librarian(110, "John Wong", "98th avenue, Wall St", "john@barnes.org", 50000);

    /*simulating user input in a string stream to be passed into the method*/
    std::string methodInput = "1\nnoel\nCroatia\nnoel@live.com\n";
    std::istringstream inputStream(methodInput);
    std::streambuf* testInput = std::cin.rdbuf(inputStream.rdbuf());

    /* capturing method output in a string stream*/
    std::stringstream methodOutput;
    std::streambuf* testOutput = std::cout.rdbuf(methodOutput.rdbuf());

    librarian.addMember();
    std::cout.rdbuf(testOutput);
    std::cin.rdbuf(testInput);

    /* Check if the expected output is found in the actual method output */
    REQUIRE(methodOutput.str().find("A new member has been added successfully!") != std::string::npos);
    REQUIRE(methodOutput.str().find("Member ID: 1") != std::string::npos);
    REQUIRE(methodOutput.str().find("Name: noel") != std::string::npos);
    REQUIRE(methodOutput.str().find("Address: Croatia") != std::string::npos);
    REQUIRE(methodOutput.str().find("Email: noel@live.com") != std::string::npos);
}
    

TEST_CASE("Test issueBook function", "[issueBook]") 
{
    Librarian librarian(110, "John Wong", "98th avenue, Wall St", "john@barnes.org", 50000);
    /*simulating user input in a string stream to be passed into the method*/
    std::string methodInput = "library_books.csv\n03 01 2024\n";
    std::istringstream inputStream(methodInput);
    std::streambuf* testInput = std::cin.rdbuf(inputStream.rdbuf());

    /* capturing method output in a string stream*/
    std::stringstream methodOutput;
    std::streambuf* testOutput = std::cout.rdbuf(methodOutput.rdbuf());
    
    librarian.issueBook(1,4);
    std::cout.rdbuf(testOutput);
    std::cin.rdbuf(testInput);

    /* Check if the expected output is found in the actual method output */
    REQUIRE(methodOutput.str().find("Book successfully Issued !") != std::string::npos);
}


TEST_CASE("Test displayBorrowedBooks function", "[displayBorrowedBooks]") 
{
    Librarian librarian(110, "John Wong", "98th avenue, Wall St", "john@barnes.org", 50000);

    /* capturing method output in a string stream*/
    std::stringstream methodOutput;
    std::streambuf* testOutput = std::cout.rdbuf(methodOutput.rdbuf());

    librarian.displayBorrowedBooks(1);
    std::cout.rdbuf(testOutput);

    /* Check if the expected output is found in the actual method output */
    REQUIRE(methodOutput.str().find("Borrowed books by member with ID 1:") != std::string::npos);
    REQUIRE(methodOutput.str().find("Book ID: 4") != std::string::npos);
    REQUIRE(methodOutput.str().find("Book Name: The Freakshow Murders") != std::string::npos);
    REQUIRE(methodOutput.str().find("Author: Frederic Brown") != std::string::npos);
    REQUIRE(methodOutput.str().find("Due date: 6/1/2024") != std::string::npos);
}


TEST_CASE("Test calcFine function", "[calcFine]") 
{
    Librarian librarian(110, "John Wong", "98th avenue, Wall St", "john@barnes.org", 50000);

     /* capturing method output in a string stream*/
    std::stringstream methodOutput;
    std::streambuf* testOutput = std::cout.rdbuf(methodOutput.rdbuf());

    librarian.calcFine(1);
    std::cout.rdbuf(testOutput);
   
    /* Check if the expected output is found in the actual method output */
    REQUIRE(methodOutput.str().find("Total Fine: £9") != std::string::npos);
}


TEST_CASE("Test returnBook function", "[returnBook]") 
{
    Librarian librarian(110, "John Wong", "98th avenue, Wall St", "john@barnes.org", 50000);

    /* capturing method output in a string stream*/
    std::stringstream methodOutput;
    std::streambuf* testOutput = std::cout.rdbuf(methodOutput.rdbuf());

    librarian.returnBook(1, 4);
    std::cout.rdbuf(testOutput);

    /* Check if the expected output is found in the actual method output */
    REQUIRE(methodOutput.str().find("Book with ID 4 successfully returned!") != std::string::npos);
}
