#include<stdio.h>
#include<unistd.h>
int main()
{
int p = fork();

if(p == 0)
{ 
printf("THIS IS CHILD PROCESS");
}
else if(p > 0)
{
printf("THIS IS PARENT PROCESS\n");

}
else
{
printf("PROCESS COULD NOT BE CREATED");
}

return 0;
}
