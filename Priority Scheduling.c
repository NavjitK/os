#include<stdio.h>
int main()
{
	int process[20];
	int priority[20];
	int burstTime[20];
	int arrivalTime[20];
	int waitingTime[20];
	int turnAroundTime[20];
	int completionTime[20];
	int timeQuantum=2;
	int a,b,c;
	int total=0;
	int sort;
	int temp;
	int avgWT;
	int avgTAT;
	printf("Enter no. of processes: ");
	scanf("%d",&a);
	printf("\n");
	printf("Enter priority: ");
	for(b=0;b<a;b++)
	{
		printf("\n");
		printf("Enter priority for process: %d \n",b+1);
		printf("Priority: ");
		scanf("%d",&priority[b]);
		process[b]=b+1;
	}
	printf("\n\n");
	printf("Enter Burst Time: ");
	for(b=0;b<a;b++)
	{
		printf("\n");
		printf("Enter burst time for process: %d \n",b+1);
		printf("Burst Time: ");
		scanf("%d",&burstTime[b]);
        process[b]=b+1;
	}
	printf("\n\n");
	printf("Enter Arrival Time: ");
	for(b=0;b<a;b++)
	{
		printf("\n");
		printf("Enter Arrival Time for process: %d \n",b+1);
		printf("Arrival Time: ");
		scanf("%d",&arrivalTime[b]);
        process[b]=b+1;
	}
	printf("\n");
	printf("Initial Time Quantum for every process: %d",timeQuantum);
	for(b=0;b<a;b++)
	{
		sort=b;
        for(c=b+1;c<a;c++)
        {
            if(priority[c]<priority[sort])
                sort=c;
        }
        temp=priority[b];
        priority[b]=priority[sort];
        priority[sort]=temp;
        temp=burstTime[b];
        burstTime[b]=burstTime[sort];
        burstTime[sort]=temp;
        temp=process[b];
        process[b]=process[sort];
        process[sort]=temp;
	}
	waitingTime[0]=0;
	for(b=1;b<a;b++)
    {
        waitingTime[b]=0;
        for(c=0;c<b;c++)
        {
            waitingTime[b]+=burstTime[c];
        }
        total+=waitingTime[b];
    }
    avgWT=total/a;
    total=0;
    
    printf("\n\n Process\t   Priority\t  Burst Time\t   Arrival Time\t   Waiting Time    \tTurn Around Time");
    
    for(b=0;b<a;b++)
    {
        turnAroundTime[b]=burstTime[b]+waitingTime[b];     
        total+=turnAroundTime[b];
        printf("\n\n Process[%d]\t   %d\t\t    %d\t\t   %d\t\t    %d\t\t\t    %d\n",process[b],priority[b],burstTime[b],arrivalTime[b],waitingTime[b],turnAroundTime[b]);
    }
 
    avgTAT=total/a; 
    printf("\n\n Average Waiting Time=%d\n",avgWT);
    printf("\n\n Average Turnaround Time=%d\n",avgTAT);
 
	return 0;
}
