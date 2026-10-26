#include <stdio.h>
#include <time.h>

void writeLog(const char *action)
{
    FILE *fp;

    time_t now;

    fp = fopen("auditlog.dat", "a");

    if(fp == NULL)
    {
        return;
    }

    now = time(NULL);

    fprintf(fp,
            "%s : %s",
            action,
            ctime(&now));

    fclose(fp);
}