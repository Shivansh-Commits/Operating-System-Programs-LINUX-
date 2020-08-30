#include<stdio.h>
#include<string.h>
int main()
{
	int et[10],at[10],n,i,j,temp,st[10],ft[10],wt[10],ta[10];
	int totwt=0,totta=0;
	float awt,ata;
	char pn[10][10],t[10];

	printf("\nNumber of processes: ");
	scanf("%d",&n);
	printf("Process name & Arrival Time:\n");
	for(int i=0;i<n;i++)
		scanf("%s %d",pn[i],&at[i]);
	printf("Burst Time:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&et[i]);

	for(int i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(et[i]<et[j])
			{
				temp = at[i];
				at[i] = at[j];
				at[j] = temp;
				temp = et[i];
				et[i] = et[j];
				et[j] = temp;
				strcpy(t,pn[i]);
				strcpy(pn[i],pn[j]);
				strcpy(pn[j],t);
			}
		}
	}

	for(i=0;i<n;i++)
	{
		if(i==0)
			st[i]=at[i];
		else
			st[i]=ft[i-1];
		wt[i]=st[i]-at[i];
		ft[i]=st[i]+et[i];
		ta[i]=ft[i]-at[i];
		totwt+=wt[i];
		totta+=ta[i];
	}
	awt = (float)totwt/n;
	ata = (float)totta/n;
	
	printf("Gantt's Chart:\n");
	for(int i=0;i<n;i++)
		printf("%s\t",pn[i]);
	printf("\nAverage Waiting Time: %.2f", awt);
	printf("\nAverage Turn Around Time: %.2f", ata);
	return 0;
}
	
