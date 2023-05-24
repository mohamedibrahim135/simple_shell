#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
/**
 * main - PID
 * Return: Always 0.
 */
int main(void)
{
pid_t pid;
int i;
char *args[] = {"is", "-l", "/tmp", NULL};
int status;
for (i = 0; i < 5; i++)
{
pid = fork();
if(pid < 0)
{
fprintf(stderr, "failed to create process\n");
exit(1);
} 
else if (pid == 0)
{
execve("/bin/ls", args, NULL);
fprintf(stderr, "Failed to execute command\n");
exit(1);
}
else
{
wait(&status);
}
}
return 0;
}
