
CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -std=c11
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = ems
GTEST_TARGET = gtest_ems
SRC = main.c \
employee.c \
attendance.c \
payroll.c \
validation.c \
login.c \
logger.c
GTEST_SRC = test_ems.cpp
all:
$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
run:
./$(TARGET)
gtest:
$(CXX) $(CXXFLAGS) \
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
rungtest:
./$(GTEST_TARGET)
gtest-report:
./$(GTEST_TARGET) > gtest_report.txt
coverage:
$(CXX) $(CXXFLAGS) \
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
cppcheck:
cppcheck \
--enable=all \
--inconclusive \
--force \
.c .h \
2> cppcheck_report.txt
valgrind:
valgrind \
--leak-check=full \
--show-leak-kinds=all \
--track-origins=yes \
./$(TARGET) \
2> valgrind_report.txt
clean:
rm -f $(TARGET)
rm -f $(GTEST_TARGET)
rm -f .gcda
rm -f .gcno
rm -f .gcov
rm -f gtest_report.txt
rm -f cppcheck_report.txt
rm -f valgrind_report.txt
rm -f employee_coverage.txt
rm -f attendance_coverage.txt
rm -f payroll_coverage.txt
rm -f validation_coverage.txt
