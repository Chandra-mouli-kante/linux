#include<stdio.h>

main()

{

	int p[20],bt[20],pri[20],wt[20],tat[20],i, k, n, temp; 	float avgwt, avgtat;

	printf("Enter the number of processes - ");

	scanf("%d",&n);

	for(i=0;i<n;i++)

	{

	   p[i] = i;

	   printf("Enter the Burst Time & Priority of Process %d ---",i); 

	   scanf("%d%d",&bt[i], &pri[i]);

	}

	for(i=0;i<n;i++)

	for(k=i+1;k<n;k++)

	if(pri[i] > pri[k])

	{

		temp=p[i];

		p[i]=p[k];

		p[k]=temp;

		

		temp=bt[i];

		bt[i]=bt[k];

		bt[k]=temp;

		

		temp=pri[i];

		pri[i]=pri[k];

		pri[k]=temp;

	}

	avgwt = wt[0] = 0;

	avgtat = tat[0] = bt[0];

	for(i=1;i<n;i++)

	{

		wt[i] = wt[i-1] + bt[i-1];

		tat[i] = tat[i-1] + bt[i];

		avgwt = avgwt + wt[i];

		avgtat = avgtat + tat[i];

	}

printf("\t PROCESS  |  PRIORITY   |  BURST TIME  |   WAITING TIME  | TURNAROUND TIME");

	for(i=0;i<n;i++)

printf("\n\t   P%d \t  |\t %d \t|\t %d \t|\t %d \t |\t %d", p[i], pri[i], bt[i], wt[i], tat[i]);

	printf("\nAverage Waiting Time is --- %f",avgwt/n); 

	printf("\nAverageTurnaround Time is --- %f",avgtat/n);

}
