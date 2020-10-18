#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<dirent.h>
int main()
{
 int pid;
 pid = fork();
 if(pid < 0) {
 printf("PROCESS COULD NOT BE CREATED\n");
 } else if(pid == 0) {
 printf("I AM FIRST CHILD\n");
 DIR *d;
 struct dirent *dir;
 d = opendir(".");
 if(d) {
 while((dir = readdir(d)) != NULL) {
 printf("%s\n", dir -> d_name);
 }
 }
 closedir(d);
 exit(0);
 } else if(pid > 0) {
 	wait(0);
 	printf("I AM FIRST PARENT\n");
 	int spid = fork();
 		if(spid < 0) 
 		{
 		printf("Process could not be created\n");
 		} 
 		else if(spid == 0) 
 		{
 		sleep(5);
 		printf("I AM SECOND CHILD\n");
 		} 
 		else if(spid > 0) 
 		{
 		printf("I AM SECOND PARENT\n");
 		exit(0);
 	}
 }
 return 0;
}
