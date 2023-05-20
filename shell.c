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
{char *args[3];
int status;
pid_t pid;
char *command;
char *end = "fail";
size_t size = 100;
int i = 0, j;
while (1)
{printf("#cisfun$ ");
command = malloc(sizeof(char) * (size));
getline(&command, &size, stdin);
while (command[i] != '\n' && command[i] != '\0')
{ i++; }
command[i] = '\0';
j = 0;
args[j] = command;
for (i = 0; command[i] != '\0'; i++)
{
if (command[i] == ' ')
{
j++;
args[j] = end;
break; }}
j++;
args[j] = NULL;
pid = fork();
if (pid == 0)
{execve(args[0], args, NULL);
perror("./shell");
exit(EXIT_FAILURE); }
else if (pid < 0)
{ perror("fork"); }
else
{ waitpid(pid, &status, 0); }}
return (0); }
