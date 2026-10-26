
#include "test_framework.h"

int totalTests = 0;
int passedTests = 0;

void testValidation(void);
void testEmployee(void);
void testAttendance(void);
void testPayroll(void);
void testIntegration(void);

int main(void)
{
    testValidation();

    testEmployee();

    testAttendance();

    testPayroll();

    testIntegration();

    printf("\n===========================\n");

    printf("Tests Passed : %d\n",
           passedTests);

    printf("Tests Run    : %d\n",
           totalTests);

    printf("Success Rate : %.2f%%\n",
           ((float)passedTests /
            totalTests) * 100.0f);

    return 0;
}
