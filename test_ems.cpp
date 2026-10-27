

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
/* ============================================
VALIDATION TESTS
============================================ */
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
char phone[] = "9876543210";
EXPECT_EQ(1,
validatePhone(phone));
}
TEST(ValidationTest, InvalidPhoneShort)
{
char phone[] = "1234";
EXPECT_EQ(0,
validatePhone(phone));
}
TEST(ValidationTest, InvalidPhoneCharacters)
{
char phone[] = "abcd567890";
EXPECT_EQ(0,
validatePhone(phone));
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
============================================ */
TEST(EmployeeTest, EmployeeIdStorage)
{
Employee emp;
emp.empId = 1000;
EXPECT_EQ(1000,
emp.empId);
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
TEST(EmployeeTest, LinkedListSingleNode)
{
EmployeeNode node;
node.emp.empId = 1000;
node.next = NULL;
EXPECT_EQ(1000,
node.emp.empId);
}
TEST(EmployeeTest, SearchEmployeeFound)
{
EmployeeNode node;
node.emp.empId = 1000;
node.next = NULL;
EXPECT_NE(nullptr,
searchEmployee(&node,
1000));
}
TEST(EmployeeTest, SearchEmployeeNotFound)
{
EmployeeNode node;
node.emp.empId = 1000;
node.next = NULL;
EXPECT_EQ(nullptr,
searchEmployee(&node,
9999));
}
/* ============================================
ATTENDANCE TESTS
============================================ */
TEST(AttendanceTest, AttendanceEmployeeId)
{
Attendance att;
att.empId = 1000;
EXPECT_EQ(1000,
att.empId);
}
TEST(AttendanceTest, AttendancePresent)
{
Attendance att;
att.status = 'P';
EXPECT_EQ('P',
att.status);
}
TEST(AttendanceTest, AttendanceAbsent)
{
Attendance att;
att.status = 'A';
EXPECT_EQ('A',
att.status);
}
TEST(AttendanceTest, AttendanceLeave)
{
Attendance att;
att.status = 'L';
EXPECT_EQ('L',
att.status);
}
TEST(AttendanceTest, AttendanceDateStorage)
{
Attendance att;
strcpy(att.date,
"21-11-2026");
EXPECT_STREQ("21-11-2026",
att.date);
}
/* ============================================
PAYROLL TESTS
============================================ */
TEST(PayrollTest, BasicSalaryStorage)
{
Payroll p;
p.basicSalary = 60000;
EXPECT_EQ(60000,
(int)p.basicSalary);
}
TEST(PayrollTest, DailySalaryCalculation)
{
float basicSalary = 60000;
float dailySalary =
basicSalary / 30.0f;
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
dailySalary * p.absentDays;
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


/* ============================================
INTEGRATION TESTS
============================================ */
TEST(IntegrationTest, EmployeeAttendanceMapping)
{
Employee emp;
Attendance att;
emp.empId = 1000;
att.empId = 1000;
EXPECT_EQ(emp.empId,
att.empId);
}
TEST(IntegrationTest, EmployeePayrollMapping)
{
Employee emp;
Payroll pay;
emp.empId = 1000;
pay.empId = 1000;
EXPECT_EQ(emp.empId,
pay.empId);
}
TEST(IntegrationTest, SalaryTransfer)
{
Employee emp;
Payroll pay;
emp.salary = 60000;
pay.basicSalary =
emp.salary;
EXPECT_EQ(emp.salary,
pay.basicSalary);
}
TEST(IntegrationTest, PayrollFlow)
{
Employee emp;
Attendance att;
Payroll pay;
emp.empId = 1000;
emp.salary = 60000;
att.empId = 1000;
att.status = 'P';
pay.empId = emp.empId;
pay.basicSalary = emp.salary;
EXPECT_EQ(att.empId,
pay.empId);
EXPECT_EQ(emp.salary,
pay.basicSalary);
}
/* ============================================
MAIN
============================================ */
int main(int argc, char **argv)
{
::testing::InitGoogleTest(
&argc,
argv);
return RUN_ALL_TESTS();
}
