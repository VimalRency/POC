#include <stdio.h>

#include "payroll.h"
#include "employee.h"
#include "attendance.h"
#include "logger.h"

void generatePayroll()
{
    Payroll p;

    Employee emp;
    Attendance att;

    FILE *empFp;
    FILE *attFp;
    FILE *payFp;

    int id;
    int found = 0;

    printf("Enter Employee ID : ");
    scanf("%d", &id);

    empFp = fopen("employees.dat", "rb");

    if(empFp == NULL)
    {
        printf("Employee File Not Found\n");
        return;
    }

    printf("\nChecking Employee File...\n");

    while(fread(&emp, sizeof(Employee), 1, empFp))
    {
        printf("Found Employee : %d\n",
               emp.empId);

        if(emp.empId == id)
        {
            found = 1;

            p.empId = emp.empId;
            p.basicSalary = emp.salary;

            break;
        }
    }

    fclose(empFp);

    if(found == 0)
    {
        printf("Employee Not Found\n");
        return;
    }

    p.presentDays = 0;
    p.absentDays = 0;
    p.leaveDays = 0;

    attFp = fopen("attendance.dat", "rb");

    if(attFp == NULL)
    {
        printf("Attendance File Not Found\n");
        return;
    }

    printf("\nChecking Attendance Records...\n");

    while(fread(&att, sizeof(Attendance), 1, attFp))
    {
        printf("ID=%d Status=%c\n",
               att.empId,
               att.status);

        if(att.empId == id)
        {
            if(att.status == 'P')
            {
                p.presentDays++;
            }
            else if(att.status == 'A')
            {
                p.absentDays++;
            }
            else if(att.status == 'L')
            {
                p.leaveDays++;
            }
        }
    }

    fclose(attFp);

    printf("\nPresent Days : %d",
           p.presentDays);

    printf("\nAbsent Days  : %d",
           p.absentDays);

    printf("\nLeave Days   : %d\n",
           p.leaveDays);

    if(p.presentDays == 0 &&
       p.absentDays == 0 &&
       p.leaveDays == 0)
    {
        printf("No Attendance Records Found\n");
        return;
    }

    {
        float dailySalary;

        dailySalary = p.basicSalary / 30.0f;

        p.deduction =
            p.absentDays * dailySalary;

        p.netSalary =
            p.basicSalary - p.deduction;
    }

    payFp = fopen("payroll.dat", "ab");

    if(payFp == NULL)
    {
        printf("Payroll File Error\n");
        return;
    }

    fwrite(&p,
           sizeof(Payroll),
           1,
           payFp);

    fclose(payFp);
    writeLog("Payroll Generated");

    printf("\n");
    printf("\n========== PAYROLL GENERATED ==========");
    printf("\nEmployee ID  : %d", p.empId);
    printf("\nBasic Salary : %.2f", p.basicSalary);
    printf("\nPresent Days : %d", p.presentDays);
    printf("\nAbsent Days  : %d", p.absentDays);
    printf("\nLeave Days   : %d", p.leaveDays);
    printf("\nDeduction    : %.2f", p.deduction);
    printf("\nNet Salary   : %.2f", p.netSalary);
    printf("\n");
    
}
void viewPayrollFile()
{
    FILE *fp;
    Payroll p;

    fp = fopen("payroll.dat", "rb");

    if(fp == NULL)
    {
        printf("\npayroll.dat not found\n");
        return;
    }

    printf("\n=================================");
    printf("\n PAYROLL FILE CONTENTS ");
    printf("\n=================================\n");

    while(fread(&p, sizeof(Payroll), 1, fp))
    {
        printf("\nEmployee ID : %d", p.empId);
        printf("\nBasic Salary: %.2f", p.basicSalary);
        printf("\nPresent Days: %d", p.presentDays);
        printf("\nAbsent Days : %d", p.absentDays);
        printf("\nLeave Days  : %d", p.leaveDays);
        printf("\nDeduction   : %.2f", p.deduction);
        printf("\nNet Salary  : %.2f", p.netSalary);
        printf("\n-------------------------------");
    }

    fclose(fp);
   
}

void viewPayroll()
{
    Payroll p;

    FILE *fp;

    fp = fopen("payroll.dat", "rb");

    if(fp == NULL)
    {
        printf("No Payroll Records\n");
        return;
    }

    while(fread(&p, sizeof(Payroll), 1, fp))
    {
        printf("\n================================");
        printf("\nEmployee ID  : %d", p.empId);
        printf("\nBasic Salary : %.2f",
               p.basicSalary);
        printf("\nPresent Days : %d",
               p.presentDays);
        printf("\nAbsent Days  : %d",
               p.absentDays);
        printf("\nLeave Days   : %d",
               p.leaveDays);
        printf("\nDeduction    : %.2f",
               p.deduction);
        printf("\nNet Salary   : %.2f",
               p.netSalary);
        printf("\n================================");
    }

    fclose(fp);
}

void searchPayroll()
{
    Payroll p;

    FILE *fp;

    int id;
    int found = 0;

    printf("Enter Employee ID : ");
    scanf("%d", &id);

    fp = fopen("payroll.dat", "rb");

    if(fp == NULL)
    {
        printf("No Payroll Records\n");
        return;
    }

    while(fread(&p, sizeof(Payroll), 1, fp))
    {
        if(p.empId == id)
        {
            found = 1;

            printf("\n========== PAYROLL ==========");
            printf("\nEmployee ID  : %d",
                   p.empId);
            printf("\nBasic Salary : %.2f",
                   p.basicSalary);
            printf("\nPresent Days : %d",
                   p.presentDays);
            printf("\nAbsent Days  : %d",
                   p.absentDays);
            printf("\nLeave Days   : %d",
                   p.leaveDays);
            printf("\nDeduction    : %.2f",
                   p.deduction);
            printf("\nNet Salary   : %.2f\n",
                   p.netSalary);

            break;
        }
    }

    fclose(fp);

    if(found == 0)
    {
        printf("Payroll Record Not Found\n");
    }
}

void payrollSummary()
{
    Payroll p;

    FILE *fp;

    int count = 0;

    float totalSalary = 0.0f;

    fp = fopen("payroll.dat", "rb");

    if(fp == NULL)
    {
        printf("No Payroll Records\n");
        return;
    }

    while(fread(&p, sizeof(Payroll), 1, fp))
    {
        count++;

        totalSalary += p.netSalary;
    }

    fclose(fp);

    printf("\n========= PAYROLL SUMMARY =========");
    printf("\nEmployees Processed : %d",
           count);
    printf("\nTotal Salary Paid   : %.2f",
           totalSalary);

    if(count > 0)
    {
        printf("\nAverage Salary      : %.2f",
               totalSalary / count);
    }

    printf("\n");
}
