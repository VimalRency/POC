#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#include "attendance.h"
#include "validation.h"
#include "logger.h"

void recordAttendance()
{
    Attendance a;
    time_t now;

    struct tm *current;
    
    now = time(NULL);
    
    current = localtime(&now);
    strftime(a.date,
         sizeof(a.date),
         "%d-%m-%Y",
         current);
    strftime(a.time,
         sizeof(a.time),
         "%H:%M:%S",
         current);

    FILE *fp = fopen("attendance.dat","ab");

    if(fp == NULL)
    {
        printf("File Error\n");
        return;
    }

    printf("Employee ID : ");
    scanf("%d",&a.empId);


    printf("Status(P/A/L): ");
    scanf(" %c",&a.status);

    if(!validateAttendanceStatus(a.status))
    {
        printf("Invalid Attendance Status\n");
        fclose(fp);
        return;
    }

    fwrite(&a,sizeof(Attendance),1,fp);

    fclose(fp);
    writeLog("Attendance Recorded");

    printf("Attendance Recorded Successfully\n");
}
void viewAttendance()
{
    Attendance a;

    FILE *fp=fopen("attendance.dat","rb");

    if(fp==NULL)
    {
        printf("No Attendance Data\n");
        return;
    }

    while(fread(&a,sizeof(Attendance),1,fp))
    {
        printf("\nID:%d",a.empId);
        printf("\nDate:%s",a.date);
        printf("\nTime : %s",a.time);
        printf("\nStatus:%c\n",a.status);
    }

    fclose(fp);
}
void viewAttendanceFile()
{
    FILE *fp;
    Attendance att;

    fp = fopen("attendance.dat", "rb");

    if(fp == NULL)
    {
        printf("\nattendance.dat not found\n");
        return;
    }

    printf("\n=================================");
    printf("\n ATTENDANCE FILE CONTENTS ");
    printf("\n=================================\n");

    while(fread(&att, sizeof(Attendance), 1, fp))
    {
        printf("\nEmployee ID : %d", att.empId);
        printf("\nDate        : %s", att.date);
        printf("\nStatus      : %c", att.status);
        printf("\n-------------------------------");
    }

    fclose(fp);
}
void attendanceSummary()
{
    Attendance a;

    FILE *fp;

    int id;

    int present = 0;
    int absent = 0;
    int leave = 0;

    printf("Enter Employee ID : ");
    scanf("%d",&id);

    fp = fopen("attendance.dat","rb");

    if(fp == NULL)
    {
        printf("No Attendance Records\n");
        return;
    }

    while(fread(&a,sizeof(Attendance),1,fp))
    {
        if(a.empId == id)
        {
            if(a.status == 'P')
            {
                present++;
            }
            else if(a.status == 'A')
            {
                absent++;
            }
            else if(a.status == 'L')
            {
                leave++;
            }
        }
    }

    fclose(fp);

    printf("\n====== ATTENDANCE REPORT ======");
    printf("\nEmployee ID : %d",id);
    printf("\nPresent     : %d",present);
    printf("\nAbsent      : %d",absent);
    printf("\nLeave       : %d\n",leave);
}
