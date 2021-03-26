#include<stdio.h>
main()
{
	int p[20],bt[20],wt[20],tat[20],i,k,n,temp;
	float avgwt,avgtat;
	printf("Enter the number of processes -");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i;
		printf("\n Enter the Burst Time for process %d -",i);
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n;i++)
	for(k=i+1;k<n;k++)
	if(bt[i]>bt[k])
	{
		temp=bt[i];
		bt[i]=bt[k];
		bt[k]=temp;
		
		temp=p[i];
		p[i]=p[k];
		p[k]=temp;
	}
	wt[0]=avgwt=0;
	tat[0]=avgtat=bt[0];
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=tat[i-1]+bt[i];
		avgwt +=wt[i];
		avgtat +=tat[i];
	}
	printf("\t PROCESS	BURST TIME	WAITING TIME	TURNAROUND TIME");
	for(i=0;i<n;i++)
	
	printf("\n\t P%d \t\t %d \t\t %d \t\t %d",p[i],bt[i],wt[i],tat[i]);
	printf("\n Average Waiting time -- %f",avgwt/n);
	printf("\n Average TurnAround time -- %f",avgtat/n);
}



//Output:
//Enter the number of processes -4
//
// Enter the Burst Time for process 0 -6
//
// Enter the Burst Time for process 1 -8
//
// Enter the Burst Time for process 2 -7
//
// Enter the Burst Time for process 3 -3
//         PROCESS        BURST TIME      WAITING TIME    TURNAROUND TIME
//         P3              3               0               3
//         P0              6               3               9
//         P2              7               9               16
//         P1              8               16              24
// Average Waiting time -- 7.000000
// Average TurnAround time -- 13.000000
