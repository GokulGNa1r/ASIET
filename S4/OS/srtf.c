#include<stdio.h>
int main()
{
	int n,p[10],at[10],bt[10],ct[10],wt[10],tt[10],temp[10],count=0,smallest,time;
	double avg_tt=0,avg_wt=0,end=0;
	printf("enter the no of process:\n");
	scanf("%d",&n);
	printf("enter the at,bt:");
	for(int i=0;i<n;i++)
	{
		printf("p%d:",i+1);
		scanf("%d%d",&at[i],&bt[i]);
		temp[i]=bt[i];
	}
	
	bt[9]=9876;
	for(time=0;count!=n;time++)
	{
		smallest=9;
		for(int i=0;i<n;i++)
		{
			if(at[i]<=time&&bt[i]<bt[smallest]&&bt[i]>0)
			{
				smallest=i;
			}
		}
			bt[smallest]--;
			
			if(bt[smallest]==0)
			{
				count++;
				end=time+1;
				ct[smallest]=end;
				tt[smallest]=end-at[smallest];
				wt[smallest]=end-at[smallest]-temp[smallest];
			}
		
	}

    printf("\n---------------------------------------------------------------------------------\n");
    printf("\nPID\tAT\tBT\tCT\tTT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], temp[i], ct[i], tt[i], wt[i]);
        avg_wt += wt[i];
        avg_tt += tt[i];
    }
    
    printf("Average Waiting Time: %f\n", avg_wt / n);
    printf("Average Turnaround Time: %f\n", avg_tt / n);

	printf("-------------------------------------------------------------------------------------------------\n");
	for(int i=0;i<n;i++){
	printf("|\tp%d\t|",i+1);
	}
	printf("\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("%d\t\t",0);
	for(int i=0;i<n;i++){
	printf("%d\t\t",ct[i]);
	}
	printf("\n");

	printf("-------------------------------------------------------------------------------------------------\n");
    
}
