#include "path_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LENGTH 1024
/**
 * read_input - Reads input from the user.
 *
 * Return: A dynamically allocated string containing user input.
 */
char *read_input(void)
{
char *input = NULL;
size_t len = 0;
ssize_t rread;

printf("$ ");
fflush(stdout);
rread = getline(&input, &len, stdin);

if (rread == -1)
{
if (feof(stdin) || strcmp(input, "exit\n") == 0)
{
printf("Exiting the shell.\n");
free(input);
exit(0);
}
else
{
perror("Read error");
exit(1);
}

}
if (rread > 0 && input[rread - 1] == '\n')
{
input[rread - 1] = '\0';
}
return  (input);
}
