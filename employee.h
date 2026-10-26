#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define NAME_LEN 50
#define PHONE_LEN 15
#define ROLE_LEN 50
#define DEPT_LEN 50
#include "validation.h"
typedef struct
{
    int deptId;
    char deptName[DEPT_LEN];
} Department;

typedef struct
{
    int empId;
    char name[NAME_LEN];
    char phone[PHONE_LEN];

    Department dept;

    char role[ROLE_LEN];

    float salary;
} Employee;

typedef struct EmployeeNode
{
    Employee emp;
    struct EmployeeNode *next;
} EmployeeNode;

void addEmployee(EmployeeNode **head);
void viewEmployees(EmployeeNode *head);
EmployeeNode* searchEmployee(EmployeeNode *head, int id);
void updateEmployee(EmployeeNode *head);
void deleteEmployee(EmployeeNode **head);

void saveEmployees(EmployeeNode *head);
void loadEmployees(EmployeeNode **head);

void freeList(EmployeeNode **head);
void employeeSummary(void);
void attendanceSummary(void);
void viewEmployeeFile(void);


#endif