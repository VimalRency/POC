#ifndef PAYROLL_H
#define PAYROLL_H

typedef struct
{
    int empId;

    float basicSalary;

    int presentDays;
    int absentDays;
    int leaveDays;

    float deduction;
    float netSalary;

} Payroll;

void generatePayroll();
void viewPayroll();
void searchPayroll();
void payrollSummary();
void viewPayrollFile(void);

#endif