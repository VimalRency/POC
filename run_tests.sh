#!/bin/bash

echo "================================="
echo "Building Unit Tests"
echo "================================="

gcc \
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
echo "Executing Tests"
echo "================================="

./tests

