#ifndef ATTENDANCE_H
#define ATTENDANCE_H

typedef struct
{
    int empId;
    char date[20];
    char time[20];
    char status;
} Attendance;

void recordAttendance();
void viewAttendance();
void viewAttendanceFile(void);

#endif