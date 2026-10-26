

==========================================
EMPLOYEE MANAGEMENT SYSTEM
==========================================
CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -std=c11
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = ems
GTEST_TARGET = gtest_ems
------------------------------------------
EMS Source Files
------------------------------------------
SRC = \
main.c \
employee.c \
attendance.c \
payroll.c \
validation.c \
login.c \
logger.c
------------------------------------------
GTEST SOURCE
------------------------------------------
GTEST_SRC = \
test_ems.cpp
------------------------------------------
BUILD PROJECT
------------------------------------------
all:
$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
------------------------------------------
RUN EMS
------------------------------------------
run:
./$(TARGET)
------------------------------------------
GTEST BUILD
------------------------------------------
gtest:
$(CXX) \
$(CXXFLAGS) \
$(GTEST_SRC) \
employee.c \
attendance.c \
payroll.c \
validation.c \
login.c \
logger.c \
-lgtest \
-lgtest_main \
-pthread \
-o $(GTEST_TARGET)
------------------------------------------
GTEST REPORT
------------------------------------------
gtest-report: gtest
@echo "Running Google Tests..."
./$(GTEST_TARGET) | tee gtest_report.txt
------------------------------------------
CODE COVERAGE
------------------------------------------
coverage:
$(CXX) \
$(CXXFLAGS) \
-fprofile-arcs \
-ftest-coverage \
$(GTEST_SRC) \
employee.c \
attendance.c \
payroll.c \
validation.c \
login.c \
logger.c \
-lgtest \
-lgtest_main \
-pthread \
-o $(GTEST_TARGET)
./$(GTEST_TARGET)
gcov employee.c > employee_coverage.txt
gcov attendance.c > attendance_coverage.txt
gcov payroll.c > payroll_coverage.txt
gcov validation.c > validation_coverage.txt
------------------------------------------
CPPCHECK
------------------------------------------
cppcheck:
cppcheck \
--enable=all \
--inconclusive \
--force \
.c .h \
2> cppcheck_report.txt
------------------------------------------
MISRA REVIEW REPORT
------------------------------------------
misra:
cppcheck \
--enable=all \
--inconclusive \
--force \
.c .h \
2> misra_report.txt
------------------------------------------
VALGRIND
------------------------------------------
valgrind:
$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
valgrind \
--leak-check=full \
--show-leak-kinds=all \
--track-origins=yes \
./$(TARGET) \
2> valgrind_report.txt
------------------------------------------
TIMESTAMP REPORT
------------------------------------------
timestamp:
@echo "========== EMS EXECUTION ==========" > build_report.txt
@date >> build_report.txt
@echo "" >> build_report.txt
------------------------------------------
ALL REPORTS
------------------------------------------
reports: timestamp gtest-report coverage cppcheck misra valgrind
@echo "All reports generated"
------------------------------------------
CLEAN
------------------------------------------
clean:
rm -f $(TARGET)
rm -f $(GTEST_TARGET)
rm -f .gcda
rm -f .gcno
rm -f .gcov
rm -f cppcheck_report.txt
rm -f misra_report.txt
rm -f valgrind_report.txt
rm -f gtest_report.txt
rm -f employee_coverage.txt
rm -f attendance_coverage.txt
rm -f payroll_coverage.txt
rm -f validation_coverage.txt
rm -f build_report.txt

