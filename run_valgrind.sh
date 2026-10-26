#!/bin/bash

echo "================================="
echo "Building EMS"
echo "================================="

gcc main.c \
employee.c \
attendance.c \
payroll.c \
validation.c \
login.c \
logger.c \
-o ems

echo "================================="
echo "Running Valgrind"
echo "================================="

valgrind \
--leak-check=full \
--show-leak-kinds=all \
--track-origins=yes \
.\ems


