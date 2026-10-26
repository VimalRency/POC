#include <stdio.h>
#include <string.h>

#include "logger.h"

int hrLogin(void)
{
    char username[30];
    char password[30];

    printf("\n================================");
    printf("\n        HR ADMIN LOGIN");
    printf("\n================================");

    printf("\nUsername : ");
    scanf("%s", username);

    printf("Password : ");
    scanf("%s", password);

    if(strcmp(username, "admin") == 0 &&
       strcmp(password, "admin123") == 0)
    {
        writeLog("HR Login Success");

        printf("\nLogin Successful\n");

        return 1;
    }

    writeLog("HR Login Failed");

    printf("\nInvalid Username or Password\n");

    return 0;
}
