#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main()
{

execlp("ls", "ls", (char *)NULL);

return 0;
}
