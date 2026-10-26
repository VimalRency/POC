
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage

SRC = main.c employee.c attendance.c payroll.c validation.c login.c logger.c
HEADERS = employee.h attendance.h payroll.h validation.h
TARGET = ems

TEST_SOURCES = test_runner.c test_validation.c test_employee.c test_attendance.c test_payroll.c test_integration.c
TEST_TARGET = test_ems

.PHONY: all test runtest coverage cppcheck valgrind clean

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	gcc $(CFLAGS) $(SRC) -o $(TARGET)

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_SOURCES) $(SRC)
	gcc $(CFLAGS) $(TEST_SOURCES) employee.c attendance.c payroll.c validation.c -o $(TEST_TARGET)

runtest: test
	./$(TEST_TARGET)

coverage:
	gcc $(CFLAGS) $(COVERAGE_FLAGS) $(TEST_SOURCES) employee.c attendance.c payroll.c validation.c -o $(TEST_TARGET)
	./$(TEST_TARGET)
	gcov employee.c
	gcov attendance.c
	gcov payroll.c
	gcov validation.c

cppcheck:
	cppcheck --enable=all --std=c11 --inconclusive --force *.c

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)
	rm -f *.gcno *.gcda *.gcov *.dat


 


