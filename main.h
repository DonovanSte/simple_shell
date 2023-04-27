#ifndef MAIN_H
#define MAIN_H

/*LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*FUNCTION PROTOTYPES*/
char *_getline(void);
char **split_string(char *string, int *count);
int prompt(int ac, char **av);
char *read_line();

#endif
