#include "path_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LENGTH 1024
/**
 * execute_command - Executes a command entered by the user.
 *
 * @input: The command entered by the user.
 */
void execute_command(char *input)
{
char *token;
char *args[MAX_LENGTH];
char *savptr;
int i;
pid_t child_pid;
int status;

child_pid = fork();

if (child_pid < 0)
{
perror("Fork error");
exit(1);

}
else if (child_pid == 0)
{

i = 0;
token = strtok_r(input, " ", &savptr);

while (token != NULL)
{
args[i] = token;
token = strtok_r(NULL, " ", &savptr);
i++;
}

args[i] = NULL;
if (execvp(args[0], args) == -1)
{
perror("Command not found");
exit(1);
}
}
else
{
waitpid(child_pid, &status, 0);
if (!WIFEXITED(status))
{
printf("Command failed: %s\n", input);
}
}
}
