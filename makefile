CC=gcc
CXX=g++
CFLAGS=-Wall -Wextra -std=c11
CXXFLAGS=-Wall -Wextra -std=c++17
TARGET=ems
COV_TARGET=ems_cov
GTEST_TARGET=gtest_ems
SRC=main.c employee.c attendance.c payroll.c validation.c login.c logger.c
OBJ=employee.o attendance.o payroll.o validation.o login.o logger.o
.PHONY: all run gtest cppcheck valgrind coverage misra reports clean
all:
 $(CC) $(CFLAGS) $(SRC) -o $(TARGET)
run:
 ./$(TARGET)
gtest-obj:
 $(CC) -c employee.c
 $(CC) -c attendance.c
 $(CC) -c payroll.c
 $(CC) -c validation.c
 $(CC) -c login.c
 $(CC) -c logger.c
gtest: gtest-obj
 $(CXX) test_ems.cpp \
 employee.o attendance.o payroll.o \
 validation.o login.o logger.o \
 -lgtest -lgtest_main -pthread \
 -o $(GTEST_TARGET)
rungtest:
 ./$(GTEST_TARGET)
gtest-report:
 ./$(GTEST_TARGET) > gtest_report.txt
coverage:
 $(CC) -fprofile-arcs -ftest-coverage \
 main.c employee.c attendance.c payroll.c \
 validation.c login.c logger.c \
 -o $(COV_TARGET)
cppcheck:
 echo "CPPCHECK REPORT - $$(date)" > cppcheck_report.txt
 cppcheck --enable=all --inconclusive --force .c .h 2>>    cppcheck_report.txt
valgrind:
 echo "VALGRIND REPORT - $$(date)" > valgrind_report.txt
 valgrind \
 --leak-check=full \
 --show-leak-kinds=all \
 --track-origins=yes \
 ./$(TARGET) 2>> valgrind_report.txt
misra:
 echo "MISRA REVIEW REPORT - $$(date)" > misra_report.txt
 cppcheck --enable=all --inconclusive --force .c .h 2>>  misra_report.txt
reports:
 echo "COVERAGE REPORT - $$(date)" > coverage_report.txt
 gcov employee.c >> coverage_report.txt
 gcov attendance.c >> coverage_report.txt
 gcov payroll.c >> coverage_report.txt
 gcov validation.c >> coverage_report.txt
 gcov login.c >> coverage_report.txt
 gcov logger.c >> coverage_report.txt
clean:
 rm -f $(TARGET)
 rm -f $(COV_TARGET)
 rm -f $(GTEST_TARGET)
 rm -f .o
 rm -f .gcda
 rm -f .gcno
 rm -f .gcov
 rm -f gtest_report.txt
 rm -f cppcheck_report.txt
 rm -f misra_report.txt
 rm -f valgrind_report.txt
 rm -f coverage_report.txt

