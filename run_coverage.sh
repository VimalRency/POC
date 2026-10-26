#!/bin/bash

echo "================================="
echo "Building Coverage"
echo "================================="

gcc \
-fprofile-arcs \
-ftest-coverage \
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
-o tests

echo "================================="
echo "Running Tests"
echo "================================="

./tests

echo "================================="
echo "Generating Coverage"
echo "================================="

gcov employee.c
gcov attendance.c
gcov payroll.c
gcov validation.c

echo "Coverage Complete"

