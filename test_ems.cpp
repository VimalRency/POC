

#include <gtest/gtest.h>
extern "C"
{
#include "employee.h"
#include "attendance.h"
#include "payroll.h"
#include "validation.h"
}
#include <cstring>
#include <cstdlib>
#include <cstdio>
/* ============================================
VALIDATION TESTS
============================================ /
TEST(ValidationTest, EmployeeId1000)
{
EXPECT_EQ(1, validateEmpId(1000));
}
TEST(ValidationTest, EmployeeId9999)
{
EXPECT_EQ(1, validateEmpId(9999));
}
TEST(ValidationTest, EmployeeIdBelowRange)
{
EXPECT_EQ(0, validateEmpId(999));
}
TEST(ValidationTest, EmployeeIdAboveRange)
{
EXPECT_EQ(0, validateEmpId(10000));
}
TEST(ValidationTest, PositiveSalary)
{
EXPECT_EQ(1, validateSalary(50000));
}
TEST(ValidationTest, ZeroSalary)
{
EXPECT_EQ(1, validateSalary(0));
}
TEST(ValidationTest, NegativeSalary)
{
EXPECT_EQ(0, validateSalary(-100));
}
TEST(ValidationTest, ValidPhone)
{
EXPECT_EQ(1,
validatePhone((char)"9876543210"));
}
TEST(ValidationTest, ShortPhone)
{
EXPECT_EQ(0,
validatePhone((char)"1234"));
}
TEST(ValidationTest, AlphabetPhone)
{
EXPECT_EQ(0,
validatePhone((char)"abcd567890"));
}
TEST(ValidationTest, PresentAttendance)
{
EXPECT_EQ(1,
validateAttendanceStatus('P'));
}
TEST(ValidationTest, AbsentAttendance)
{
EXPECT_EQ(1,
validateAttendanceStatus('A'));
}
TEST(ValidationTest, LeaveAttendance)
{
EXPECT_EQ(1,
validateAttendanceStatus('L'));
}
TEST(ValidationTest, InvalidAttendance)
{
EXPECT_EQ(0,
validateAttendanceStatus('X'));
}
/* ============================================
EMPLOYEE TESTS
============================================ /
TEST(EmployeeTest, SearchFound)
{
EmployeeNode node;
node.emp.empId = 1000;
node.next = NULL;
EXPECT_NE(nullptr,
searchEmployee(&node,1000));
}
TEST(EmployeeTest, SearchNotFound)
{
EmployeeNode node;
node.emp.empId = 1000;
node.next = NULL;
EXPECT_EQ(nullptr,
searchEmployee(&node,9999));
}
TEST(EmployeeTest, SingleNodeLinkedList)
{
EmployeeNode node;
node.emp.empId = 1001;
EXPECT_EQ(1001,
node.emp.empId);
}
TEST(EmployeeTest, EmployeeNameStorage)
{
Employee emp;
strcpy(emp.name,
"Rency");
EXPECT_STREQ("Rency",
emp.name);
}
TEST(EmployeeTest, EmployeeSalaryStorage)
{
Employee emp;
emp.salary = 50000;
EXPECT_EQ(50000,
(int)emp.salary);
}
TEST(EmployeeTest, EmployeeDepartmentStorage)
{
Employee emp;
strcpy(emp.dept.deptName,
"Finance");
EXPECT_STREQ("Finance",
emp.dept.deptName);
}
/* ============================================
ATTENDANCE TESTS
============================================ /
TEST(AttendanceTest, AttendanceStructure)
{
Attendance att;
att.empId = 1000;
EXPECT_EQ(1000,
att.empId);
}
TEST(AttendanceTest, AttendanceStatusPresent)
{
Attendance att;
att.status='P';
EXPECT_EQ('P',
att.status);
}
TEST(AttendanceTest, AttendanceStatusAbsent)
{
Attendance att;
att.status='A';
EXPECT_EQ('A',
att.status);
}
TEST(AttendanceTest, AttendanceStatusLeave)
{
Attendance att;
att.status='L';
EXPECT_EQ('L',
att.status);
}
TEST(AttendanceTest, AttendanceDate)
{
Attendance att;
strcpy(att.date,
"21-11-2026");
EXPECT_STREQ(
"21-11-2026",
att.date);
}
/* ============================================
PAYROLL TESTS
============================================ /
TEST(PayrollTest, DailySalaryCalculation)
{
float salary = 60000;
float dailySalary =
salary / 30.0f;
EXPECT_EQ(2000,
(int)dailySalary);
}
TEST(PayrollTest, DeductionCalculation)
{
Payroll p;
p.basicSalary = 60000;
p.absentDays = 2;
float dailySalary =
p.basicSalary / 30.0f;
p.deduction =
dailySalary *
p.absentDays;
EXPECT_EQ(4000,
(int)p.deduction);
}
TEST(PayrollTest, NetSalaryCalculation)
{
Payroll p;
p.basicSalary = 60000;
p.absentDays = 2;
float dailySalary =
p.basicSalary / 30.0f;
p.deduction =
dailySalary *
p.absentDays;
p.netSalary =
p.basicSalary -
p.deduction;
EXPECT_EQ(56000,
(int)p.netSalary);
}
TEST(PayrollTest, NetSalaryPositive)
{
Payroll p;
p.netSalary = 56000;
EXPECT_GT(p.netSalary,
0);
}
TEST(PayrollTest, PayrollEmployeeId)
{
Payroll p;
p.empId = 1000;
EXPECT_EQ(1000,
p.empId);
}
/* ============================================
INTEGRATION TESTS
============================================ /
TEST(IntegrationTest,
EmployeeAttendanceMapping)
{
Employee emp;
Attendance att;
emp.empId = 1000;
att.empId = 1000;
EXPECT_EQ(emp.empId,
att.empId);
}
TEST(IntegrationTest,
EmployeePayrollMapping)
{
Employee emp;
Payroll pay;
emp.empId = 1000;
pay.empId = 1000;
EXPECT_EQ(emp.empId,
pay.empId);
}
TEST(IntegrationTest,
SalaryTransfer)
{
Employee emp;
Payroll pay;
emp.salary = 60000;
pay.basicSalary =
emp.salary;
EXPECT_EQ(emp.salary,
pay.basicSalary);
}
TEST(IntegrationTest,
CompletePayrollFlow)
{
Employee emp;
Attendance att;
Payroll pay;
emp.empId = 1000;
emp.salary = 60000;
att.empId = 1000;
att.status = 'P';
pay.empId =
emp.empId;
pay.basicSalary =
emp.salary;
EXPECT_EQ(pay.empId,
att.empId);
EXPECT_EQ(pay.basicSalary,
emp.salary);
}
/* ============================================
MAIN
============================================ /
int main(int argc,
char argv)
{
::testing::InitGoogleTest(
&argc,
argv);
return RUN_ALL_TESTS();
}

