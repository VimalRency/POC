#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "employee.h"
#include "validation.h"
#include "logger.h"

EmployeeNode* searchEmployee(EmployeeNode *head,int id)
{
    while(head)
    {
        if(head->emp.empId == id)
        {
            return head;
        }

        head = head->next;
    }

    return NULL;
}

void addEmployee(EmployeeNode **head)
{
    EmployeeNode *newNode;

    newNode = (EmployeeNode*)malloc(sizeof(EmployeeNode));

    if(newNode == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }

    printf("\nEnter Employee ID : ");
    scanf("%d",&newNode->emp.empId);

    if(!validateEmpId(newNode->emp.empId))
    {
        printf("Invalid Employee ID\n");
        free(newNode);
        return;
    }

    if(checkDuplicateEmployee(newNode->emp.empId))
    {
        printf("Duplicate Employee ID\n");
        free(newNode);
        return;
    }

    printf("Enter Name : ");
    scanf(" %29s",newNode->emp.name);

    printf("Enter Phone(10 digits) : ");
    scanf("%29s",newNode->emp.phone);

    if(!validatePhone(newNode->emp.phone))
    {
        printf("Invalid Phone Number\n");
        free(newNode);
        return;
    }

    printf("Enter Department ID : ");
    scanf("%d",&newNode->emp.dept.deptId);

    printf("Enter Department Name : ");
    scanf(" %29s",newNode->emp.dept.deptName);

    printf("Enter Role : ");
    scanf(" %14s",newNode->emp.role);

    printf("Enter Salary : ");
    scanf("%f",&newNode->emp.salary);

    if(!validateSalary(newNode->emp.salary))
    {
        printf("Invalid Salary\n");
        free(newNode);
        return;
    }

    newNode->next = NULL;

    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        EmployeeNode *temp=*head;

        while(temp->next)
        {
            temp=temp->next;
        }

        temp->next=newNode;
    }

    saveEmployees(*head);
    writeLog("Employee Added");

    printf("\nEmployee Added Successfully\n");
}


void viewEmployees(EmployeeNode *head)
{
    if(head == NULL)
    {
        printf("\nNo Employees Found\n");
        return;
    }

    while(head)
    {
        printf("\n--------------------------------");
        printf("\nID     : %d",head->emp.empId);
        printf("\nName   : %s",head->emp.name);
        printf("\nPhone  : %s",head->emp.phone);
        printf("\nDept   : %s",head->emp.dept.deptName);
        printf("\nRole   : %s",head->emp.role);
        printf("\nSalary : %.2f",head->emp.salary);
        printf("\n--------------------------------");

        head = head->next;
    }
}

void updateEmployee(EmployeeNode *head)
{
    int id;

    printf("Enter Employee ID : ");
    scanf("%d",&id);

    EmployeeNode *emp = searchEmployee(head,id);

    if(emp == NULL)
    {
        printf("Employee Not Found\n");
        return;
    }

    printf("Enter New Role : ");
    scanf(" %29s",emp->emp.role);

    printf("Enter New Salary : ");
    scanf("%f",&emp->emp.salary);
    writeLog("Employee Updated");

    printf("Record Updated\n");
}

void deleteEmployee(EmployeeNode **head)
{
    int id;

    printf("Enter Employee ID : ");
    scanf("%d",&id);

    EmployeeNode *curr=*head;
    EmployeeNode *prev=NULL;

    while(curr)
    {
        if(curr->emp.empId == id)
        {
            if(prev == NULL)
            {
                *head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }

            free(curr);

            printf("Employee Deleted\n");
            return;
        }

        prev = curr;
        curr = curr->next;
    }
    writeLog("Employee Deleted");

    printf("Employee Not Found\n");
}

void saveEmployees(EmployeeNode *head)
{
    FILE *fp = fopen("employees.dat","wb");

    if(fp == NULL)
    {
        printf("ERROR : Cannot open employees.dat\n");
        return;
    }

    while(head)
    {
        printf("Saving Employee : %d\n",
               head->emp.empId);

        fwrite(&head->emp,
               sizeof(Employee),
               1,
               fp);

        head = head->next;
    }

    fclose(fp);

    printf("employees.dat saved\n");
}

void loadEmployees(EmployeeNode **head)
{
    FILE *fp = fopen("employees.dat","rb");

    Employee emp;

    if(fp == NULL)
    {
        return;
    }

    while(fread(&emp,sizeof(Employee),1,fp))
    {
        EmployeeNode *node;

        node =(EmployeeNode *)malloc(sizeof(EmployeeNode));

        node->emp = emp;
        node->next = *head;

        *head = node;
    }

    fclose(fp);
}

void freeList(EmployeeNode **head)
{
    EmployeeNode *temp;

    while(*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
void employeeSummary()
{
    FILE *fp;
    Employee emp;

    int count = 0;

    float totalSalary = 0.0;

    fp = fopen("employees.dat","rb");

    if(fp == NULL)
    {
        printf("No Employee Data Available\n");
        return;
    }

    while(fread(&emp,sizeof(Employee),1,fp))
    {
        count++;
        totalSalary += emp.salary;
    }

    fclose(fp);

    printf("\n========== EMPLOYEE REPORT ==========");
    printf("\nTotal Employees : %d",count);

    if(count > 0)
    {
        printf("\nAverage Salary  : %.2f",
               totalSalary / count);
    }

    printf("\n");
}
void viewEmployeeFile()
{
    FILE *fp;
    Employee emp;

    fp = fopen("employees.dat", "rb");

    if(fp == NULL)
    {
        printf("\nemployees.dat not found\n");
        return;
    }

    printf("\n=================================");
    printf("\n EMPLOYEE FILE CONTENTS ");
    printf("\n=================================\n");

    while(fread(&emp, sizeof(Employee), 1, fp))
    {
        printf("\nID       : %d", emp.empId);
        printf("\nName     : %s", emp.name);
        printf("\nPhone    : %s", emp.phone);
        printf("\nDept ID  : %d", emp.dept.deptId);
        printf("\nDept     : %s", emp.dept.deptName);
        printf("\nRole     : %s", emp.role);
        printf("\nSalary   : %.2f", emp.salary);
        printf("\n-------------------------------");
    }

    fclose(fp);
}
