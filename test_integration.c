#include <string.h>

#include "employee.h"
#include "attendance.h"
#include "payroll.h"
#include "test_framework.h"

void testIntegration(void)
{
    Employee emp;

    Attendance att;

    Payroll pay;

    printf("\n===== INTEGRATION TESTS =====\n");

    emp.empId = 1000;

    strcpy(emp.name,
           "Rency");

    emp.salary = 60000;

    att.empId = 1000;

    strcpy(att.date,
           "21-11-2026");

    att.status = 'P';
    EXPECT_EQ(
        'P',att.status);
    pay.empId = 1000;

    pay.basicSalary =
        emp.salary;

    pay.presentDays = 1;
    EXPECT_EQ(
        1,pay.presentDays);

    EXPECT_TRUE(
        emp.empId ==
        att.empId);

    EXPECT_TRUE(
        emp.empId ==
        pay.empId);

    EXPECT_TRUE(
        pay.basicSalary ==
        emp.salary);
    
}