#ifndef FUNCTIONS
#define FUNCTIONS

#include <time.h>

void err_exit(char *msg, int err_code);

int validateId(int num, char *campo);

int validateTime(struct tm* time, char *campo);

int validateName(const char* name, int id);

char* intToString(int num);


#endif