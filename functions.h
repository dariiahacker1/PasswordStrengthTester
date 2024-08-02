#ifndef PASSWORDSTRENGTHTESTER_FUNCTIONS_H
#define PASSWORDSTRENGTHTESTER_FUNCTIONS_H

#define MAX_PASSWORD_LENGTH 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

struct info{
    size_t length;
    int similarity ; // 0: not similar, 1: exactly similar
};


void title();

void standard_test(const char *password);

void length_checker(const char *password, struct info *pswd_info);

void similarity_to_popular_passwords(const char *password, struct info *pswd_info);

void conclusion(struct info *pswd_info);

#endif //PASSWORDSTRENGTHTESTER_FUNCTIONS_H
