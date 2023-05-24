#include <stdio.h>

int main(int ac, char **av)
{
int i = 1;
for(; av[i] != NULL; i++)
{
printf("%s\n" ,av[i]);
}
printf("%d" , ac)
}
