#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <stdio.h>

extern int totalTests;
extern int passedTests;

#define EXPECT_TRUE(condition) \
do { \
    totalTests++; \
    if(condition) { \
        passedTests++; \
        printf("[PASS] %s\n", #condition); \
    } \
    else { \
        printf("[FAIL] %s\n", #condition); \
    } \
} while(0)

#define EXPECT_FALSE(condition) \
do { \
    totalTests++; \
    if(!(condition)) { \
        passedTests++; \
        printf("[PASS] !(%s)\n", #condition); \
    } \
    else { \
        printf("[FAIL] !(%s)\n", #condition); \
    } \
} while(0)

#endif