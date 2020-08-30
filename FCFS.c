#include<stdio.h>
int main()
{
	int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
	int n,sum=0;
	float totalTAT=0,totalWT=0;

	printf("\nNumber of processes: ");
	scanf("%d",&n);
	printf("Burst Time:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&bt[i]);
	printf("Arrival Time:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&at[i]);

	//Completion Time
	for(int i=0;i<n;i++)
	{
		sum+=bt[i];
		ct[i]+=sum;
	}

	//Turn Around Time
	for(int i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		totalTAT+=tat[i];
	}

	//Wating Time
	for(int i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
		totalWT+=wt[i];
	}
	
	printf("Gantt's Chart:\n");
	for(int i=0;i<n;i++)
		printf("P%d\t",i);
	printf("\nAverage Waiting Time: %.2f", totalWT/n);
	printf("\nAverage Turn Around Time: %.2f", totalTAT/n);
	return 0;
}
	
