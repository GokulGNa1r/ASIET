#include<stdio.h>
int main()
{
 	int p[10],bt[10],wt[10],tt[10],n,temp;
 	float avg_tt=0.0,avg_wt=0.0;
 	printf("enter the number of process\n");
 	scanf("%d",&n);
 	
 	printf("enter the burst time for each process:\n");
 	for(int i=0;i<n;i++)
 	{
 		p[i]=i+1;
 		printf("p:%d",i+1);
 		scanf("%d",&bt[i]);
 	}
 	for(int i=0;i<n-1;i++)
 	{
 		for(int j=0;j<n-1;j++)
 		{
 			if(bt[j]>bt[j+1])
 			{
 				temp=p[j];
 				p[j]=p[j+1];
 				p[j+1]=temp;
 				temp=bt[j];
 				bt[j]=bt[j+1];
 				bt[j+1]=temp;
 			}
 		}
 	}	
 	
 	
 	wt[0]=0;
 	for(int i=1;i<n;i++)
 	{
 		wt[i]=wt[i-1]+bt[i-1];
 		avg_wt +=wt[i];
 	}
 	avg_wt /=n;
 	
 	for(int i=0;i<n;i++)
 	{
 		tt[i]=wt[i]+bt[i];
 		avg_tt +=tt[i];
 	}
 	avg_tt /=n;
 	
 	printf("\nprocess\tburst time\twaiting time\tturnaround time\n");
 	for(int i=0;i<n;i++)
 	printf("p%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tt[i]);
 	
 	printf("average waiting time:%f",avg_wt);
 	printf("average turnaround time:%f",avg_tt);
 	printf("\ngantt chart\n\n");
 	printf("\n-----------------------------------\n");
 	for(int i=0;i<n;i++)
 	{
 		printf("\tp%d\t||",p[i]);
 	}
 	
 	printf("\n----------------------------------\n");
 	printf("0");
	for(int i=0;i<n;i++)
	{
		printf("\t%d\t",tt[i]);
	}
	printf("\n");
} 
