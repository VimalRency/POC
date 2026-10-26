#include "validation.h"
#include "test_framework.h"

void testValidation(void)
{
    printf("\n===== VALIDATION TESTS =====\n");

    EXPECT_TRUE(validateEmpId(1000));
    EXPECT_TRUE(validateEmpId(9999));

    EXPECT_FALSE(validateEmpId(999));
    EXPECT_FALSE(validateEmpId(10000));

    EXPECT_TRUE(validateSalary(50000));
    EXPECT_TRUE(validateSalary(0));

    EXPECT_FALSE(validateSalary(-100));

    EXPECT_TRUE(validatePhone("9876543210"));

    EXPECT_FALSE(validatePhone("1234"));

    EXPECT_FALSE(validatePhone("abcd567890"));

    EXPECT_TRUE(validateAttendanceStatus('P'));
    EXPECT_TRUE(validateAttendanceStatus('A'));
    EXPECT_TRUE(validateAttendanceStatus('L'));

    EXPECT_FALSE(validateAttendanceStatus('X'));
}
