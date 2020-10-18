#include<stdio.h>
#include<stdlib.h>
int comp(char *st1, char *st2)
{
while(*st1 == *st2)
 {
 if(*st1 == '\0' && *st2 == '\0')
 return 1;
 st1++;
 st2++;
 }
 return 0;
}
int main()
{
 int i,n;
 char st[100];
 FILE *fp1, *fp2;
 char *line1 = NULL, *line2 = NULL;
 size_t len1 = 0, len2=0;
 ssize_t read1, read2;
 printf("File 1 Opened\n");
 printf("Enter the number of lines to be written: ");
 scanf("%d", &n);
 printf("Enter your details: \n");
 fp1 = fopen("File1.txt", "w");
 for(i=0;i<=n;i++) {
 fgets(st, sizeof st, stdin);
	 fputs(st, fp1);
 }
 fclose(fp1);
 printf("File 1 Closed\n");
 printf("File 2 opened\n");
 printf("Enter the number of lines: ");
 scanf("%d", &n);
 printf("Enter friends detail: \n");
 fp2 = fopen("File2.txt", "w");
	 for(i=0;i<=n;i++) {
		 fgets(st, sizeof st, stdin);
		 fputs(st, fp2);
	 }
 fclose(fp2);
 printf("File 2 closed\n");
 fp1 = fopen("File1.txt","r");
 fp2 = fopen("File2.txt","r");
	 if(fp1 == NULL || fp2 == NULL)
		 printf("error\n");
		 printf("Duplicate lines in both files\n");
	 while(((read1 = getline(&line1, &len1, fp1)) != -
	1) && ((read2 = getline(&line2, &len2, fp2)) != -1)) {
		 if(read1 == read2) {
		 	if(comp(line1, line2)) {
		 		printf("%s", line1);
		 	}
		 }
	}
 fclose(fp1);
 fclose(fp2);
 if(line1)
 	free(line1);
 if(line2)
 	free(line2);
 return 0;
 }
