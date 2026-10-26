#include "payroll.h"
#include "test_framework.h"

void testPayroll(void)
{
    Payroll p;

    float dailySalary;

    printf("\n===== PAYROLL TESTS =====\n");

    p.basicSalary = 60000;

    p.absentDays = 2;

    dailySalary =
        p.basicSalary / 30.0f;

    p.deduction =
        dailySalary *
        p.absentDays;

    p.netSalary =
        p.basicSalary -
        p.deduction;

    EXPECT_TRUE(
        (int)p.deduction == 4000);

    EXPECT_TRUE(
        (int)p.netSalary == 56000);

    EXPECT_TRUE(
        p.netSalary > 0);
}