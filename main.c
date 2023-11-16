#include "path_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LENGTH 1024
/**
* main - Simple shell program
*
* Return: Always 0
*/
int main(void)
{
char *input;

while (1)
{
input = read_input();
if (strcmp(input, "exit") == 0)
{
printf("Exiting the shell.\n");
free(input);
exit(0);
}
execute_command(input);
free(input);
}

return (0);
}
