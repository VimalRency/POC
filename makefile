

CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -std=c11
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = ems
GTEST_TARGET = gtest_ems
SRC = \
main.c \
employee.c \
attendance.c \
payroll.c \
validation.c \
login.c \
logger.c
TEST_SRC = \
test_ems.cpp \
employee.c \
attendance.c \
payroll.c \
validation.c \
login.c \
logger.c
all:
$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
run:
./$(TARGET)
gtest:
$(CXX) \
$(CXXFLAGS) \
$(TEST_SRC) \
-lgtest \
-lgtest_main \
-pthread \
-o $(GTEST_TARGET)
rungtest:
./$(GTEST_TARGET)
coverage:
$(CXX) \
$(CXXFLAGS) \
-fprofile-arcs \
-ftest-coverage \
$(TEST_SRC) \
-lgtest \
-lgtest_main \
-pthread \
-o $(GTEST_TARGET)
./$(GTEST_TARGET)
gcov employee.c
gcov attendance.c
gcov payroll.c
gcov validation.c
cppcheck:
cppcheck \
--enable=all \
--inconclusive \
--force \
.c .h
valgrind:
valgrind \
--leak-check=full \
--show-leak-kinds=all \
--track-origins=yes \
./$(TARGET)
clean:
rm -f $(TARGET)
rm -f $(GTEST_TARGET)
rm -f .gcov
rm -f .gcda
rm -f .gcno
