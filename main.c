
#include<stdio.h>

#include "employee.h"
#include "attendance.h"
#include "payroll.h"
#include "login.h"

int main()
{
    EmployeeNode *head = NULL;
    

    if(!hrLogin())
    
    {
    return 0;
    }
    loadEmployees(&head);

    int choice;
    int id;

  

    do
    {
        printf("\n");
        printf("\n=================================");
        printf("\n EMPLOYEE MANAGEMENT SYSTEM");
        printf("\n=================================");
        printf("\n1. Add Employee");
        printf("\n2. View Employees");
        printf("\n3. Search Employee");
        printf("\n4. Update Employee");
        printf("\n5. Delete Employee");
        printf("\n6. Record Attendance");
        printf("\n7. View Attendance");
        printf("\n8. Generate Payroll");
        printf("\n9. View Payroll");
        printf("\n10. Employee Report");
        printf("\n11. Attendance Report");
        printf("\n12. Search Payroll");
        printf("\n13. Payroll Summary");
        printf("\n14. View Employee File");
        printf("\n15. View Attendance File");
        printf("\n16. View Payroll File");
        printf("\n0. Exit");
        printf("\n=================================");
        printf("\nEnter Choice : ");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addEmployee(&head);
                break;

            case 2:
                viewEmployees(head);
                break;

            case 3:
            {
                printf("Enter Employee ID : ");
                scanf("%d",&id);

                EmployeeNode *emp =
                    searchEmployee(head,id);

                if(emp)
                {
                    printf("\nEmployee Found");
                    printf("\nName : %s",
                        emp->emp.name);
                }
                else
                {
                    printf("Employee Not Found");
                }
                break;
            }

            case 4:
                updateEmployee(head);
                break;

            case 5:
                deleteEmployee(&head);
                break;

            case 6:
                recordAttendance();
                break;

            case 7:
                viewAttendance();
                break;

            case 8:
                generatePayroll();
                break;

            case 9:
                viewPayroll();
                break;
            case 10:
                employeeSummary();
                break;
            
            case 11:
                attendanceSummary();
                break;
            
            case 12:
                searchPayroll();
                break;
            
            case 13:
                payrollSummary();
                break;
            case 14:
                viewEmployeeFile();
                break;
            
            case 15:
                viewAttendanceFile();
                break;
            
            case 16:
                viewPayrollFile();
                break;
            case 0:
                saveEmployees(head);
                freeList(&head);
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    }while(choice!=0);

    return 0;
}
