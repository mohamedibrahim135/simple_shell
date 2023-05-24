#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include<stdlib.h>
/**
* main - PID
* Return: Always 0.
*/
int main(void)
{
char c[] = "alx simple shell";
char* tok;
tok = strtok(c, " ");
while(tok != NULL)
{
printf("%s\n", tok);
tok = strtok(NULL, " ");
}

}
