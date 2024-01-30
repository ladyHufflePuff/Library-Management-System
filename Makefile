# Makefile
# Author Student Number: M00857430
# Created: 08/01/2024
# Updated: 13/01/2024

CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic

# default target linked to build executable file
.PHONY: all
all: librarymanagementsystem
# rule to build librarymanagementsystem executmable file
librarymanagementsystem: main.cpp library.o date.o
	$(CXX) $(CXXFLAGS) -o $@ $^
# rule to build library.o object file
library.o: library.cpp library.h
	$(CXX) $(CXXFLAGS) -c $<
# rule to build date.o object file
date.o: date.cpp date.h
	$(CXX) $(CXXFLAGS) -c $<    
# text target to execute catch2 test
.PHONY:test
test: library_test.cpp library.o date.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# clean target to remove object files and executable file
.PHONY: clean
clean:
	$(RM) *.o librarymanagementsystem test


