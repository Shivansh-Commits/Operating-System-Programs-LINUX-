#include<stdio.h>
#include<unistd.h>
int main()
{
int p = fork();

if(p == 0)
{
printf("CHILD PROCESS ID: %d",getpid());
}
else if(p > 0)
{
printf("PARENT PROCESS ID: %d\n",getppid());
}
else
{
printf("PROCESS COULD NOT BE CREATED");
}

return 0;
}
