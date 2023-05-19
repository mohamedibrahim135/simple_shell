#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_ARGS 10
/**
* main - PID
* Return: Always 0.
*/
int main(void)
{char *args[MAX_ARGS];
int status;
pid_t pid;
char *command;
size_t size = 100;
int num_args = 1;
int i = 0;
while (1)
{printf("#cisfun$ ");
command = malloc(sizeof(char) * (size));
getline(&command, &size, stdin);
while (command[i] != '\n' && command[i] != '\0')
{ i++; }
command[i] = '\0';
args[0] = command;
for (i = 0; command[i] != '\0'; i++)
{
if (command[i] == ' ')
{command[i] = '\0';
args[num_args] = &command[i + 1];
num_args++;
if (num_args >= MAX_ARGS)
{ break; }}}
args[num_args] = NULL;
pid = fork();
if (pid == 0)
{execv(args[0], args);
perror("execv");
exit(EXIT_FAILURE); }
else if (pid < 0)
{ perror("fork"); }
else
{ waitpid(pid, &status, 0); }}
return (0);
}
