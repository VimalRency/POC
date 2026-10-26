#include <stdlib.h>
#include <string.h>

#include "employee.h"
#include "test_framework.h"

void testEmployee(void)
{
    EmployeeNode *head = NULL;

    EmployeeNode *node =
        (EmployeeNode *)malloc(sizeof(EmployeeNode));

    node->emp.empId = 1000;

    strcpy(node->emp.name,
           "Rency");

    node->next = NULL;

    head = node;

    printf("\n===== EMPLOYEE TESTS =====\n");

    EXPECT_TRUE(
        searchEmployee(head,1000) != NULL);

    EXPECT_FALSE(
        searchEmployee(head,9999) != NULL);

    saveEmployees(head);

    EXPECT_TRUE(1);

    freeList(&head);

    EXPECT_TRUE(head == NULL);
}