#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "employee.h"
#include "validation.h"

int validateEmpId(int id)
{
    if(id < 1000 ||
       id > 9999)
    {
        return 0;
    }

    return 1;
}

int validateSalary(float salary)
{
    return (salary >= 0);
}

int validatePhone(char phone[])
{
    int i;

    if(strlen(phone) != 10)
    {
        return 0;
    }

    for(i=0;i<10;i++)
    {
        if(!isdigit(phone[i]))
        {
            return 0;
        }
    }

    return 1;
}

int validateAttendanceStatus(char status)
{
    if(status=='P' ||
       status=='A' ||
       status=='L')
    {
        return 1;
    }

    return 0;
}

int checkDuplicateEmployee(int id)
{
    FILE *fp;
    Employee emp;

    fp = fopen("employees.dat","rb");

    if(fp == NULL)
    {
        return 0;
    }

    while(fread(&emp,sizeof(Employee),1,fp))
    {
        if(emp.empId == id)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}