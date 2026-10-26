#include <stdio.h>
#include <string.h>

#include "attendance.h"
#include "test_framework.h"

void testAttendance(void)
{
    Attendance att;

    FILE *fp;

    printf("\n===== ATTENDANCE TESTS =====\n");

    att.empId = 1000;

    strcpy(att.date,
           "21-11-2026");

    att.status = 'P';

    fp = fopen("attendance.dat","wb");

    fwrite(&att,
           sizeof(Attendance),
           1,
           fp);

    fclose(fp);

    fp = fopen("attendance.dat","rb");

    fread(&att,
          sizeof(Attendance),
          1,
          fp);

    fclose(fp);

    EXPECT_TRUE(att.empId == 1000);

    EXPECT_TRUE(att.status == 'P');

    EXPECT_TRUE(
        strcmp(att.date,
               "21-11-2026") == 0);
}
