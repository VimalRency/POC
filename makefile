

=========================================
Employee Management System
=========================================
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
COVFLAGS = -fprofile-arcs -ftest-coverage
TARGET = ems
TEST_TARGET = ems_tests
=========================================
Main Application Sources
=========================================
SRC = \
main.c \
employee.c \
attendance.c \
payroll.c \
validation.c \
login.c \
logger.c
HEADERS = \
employee.h \
attendance.h \
payroll.h \
validation.h \
login.h \
logger.h
=========================================
Unit Testing
=========================================
TEST_SRC = \
test_runner.c \
test_validation.c \
test_employee.c \
test_attendance.c \
test_payroll.c \
test_integration.c \
employee.c \
attendance.c \
payroll.c \
validation.c
=========================================
Targets
=========================================
.PHONY: all build run test coverage cppcheck valgrind clean
all: build
=========================================
Build EMS
=========================================
build:
$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
=========================================
Run EMS
=========================================
run: build
./$(TARGET)
=========================================
Build Test Executable
=========================================
test:
$(CC) $(CFLAGS) $(TEST_SRC) -o $(TEST_TARGET)
=========================================
Run Unit Tests
=========================================
runtest: test
./$(TEST_TARGET)
=========================================
Code Coverage
=========================================
coverage:
$(CC) $(CFLAGS) $(COVFLAGS) \
test_runner.c \
test_validation.c \
test_employee.c \
test_attendance.c \
test_payroll.c \
test_integration.c \
employee.c \
attendance.c \
payroll.c \
validation.c \
-o $(TEST_TARGET)
./$(TEST_TARGET)
gcov employee.c
gcov attendance.c
gcov payroll.c
gcov validation.c
=========================================
Static Analysis
=========================================
cppcheck:
cppcheck \
--enable=all \
--inconclusive \
--std=c11 \
--force \
.c
=========================================
Memory Check
=========================================
valgrind: build
valgrind \
--leak-check=full \
--show-leak-kinds=all \
--track-origins=yes \
./$(TARGET)
=========================================
Cleanup
=========================================
clean:
rm -f $(TARGET)
rm -f $(TEST_TARGET)
rm -f .gcda
rm -f .gcno
rm -f .gcov
rm -f employees.dat
rm -f attendance.dat
rm -f payroll.dat
rm -f auditlog.dat
