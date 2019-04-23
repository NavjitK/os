#include<stdio.h>
int main()
{
	int process[20];
	int priority[20];// for priorities of all processes
	int burstTime[20];// burst time for all processes
	int arrivalTime[20];// arrival time for all processes
	int waitingTime[20];// waiting time for all processes
	int turnAroundTime[20];// turnaround time for all processes
	int completionTime[20];// complettion time for all processes
	int timeQuantum=2;// time slice or time quantam
	int a,b,c;
	int total=0;
	int sort;
	int temp;
	int avgWT;
	int avgTAT;
	printf("Enter no. of processes: ");//total no of processes
	scanf("%d",&a);
	printf("\n");
	printf("Enter priority: ");// inputs of priorities of all processes
	for(b=0;b<a;b++)
	{
		printf("\n");
		printf("Enter priority for process: %d \n",b+1);
		printf("Priority: ");
		scanf("%d",&priority[b]);
		process[b]=b+1;
	}
	printf("\n\n");
	printf("Enter Burst Time: ");// input of burst time of all processes
	for(b=0;b<a;b++)
	{
		printf("\n");
		printf("Enter burst time for process: %d \n",b+1);
		printf("Burst Time: ");
		scanf("%d",&burstTime[b]);
        process[b]=b+1;
	}
	printf("\n\n");
	printf("Enter Arrival Time: ");// input of arrival time of all processes
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
        temp=priority[b];// swapping of values
        priority[b]=priority[sort];
        priority[sort]=temp;
        temp=burstTime[b];// swapping of values
        burstTime[b]=burstTime[sort];
        burstTime[sort]=temp;
        temp=process[b];// swapping of values
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
        total+=waitingTime[b];//total waiting time
    }
    avgWT=total/a;//average waiting time
    total=0;
    // output of all info on screen to user
    printf("\n\n Process\t   Priority\t  Burst Time\t   Arrival Time\t   Waiting Time    \tTurn Around Time");
    
    for(b=0;b<a;b++)
    {
        turnAroundTime[b]=burstTime[b]+waitingTime[b];     
        total+=turnAroundTime[b];//total turn around time
        printf("\n\n Process[%d]\t   %d\t\t    %d\t\t   %d\t\t    %d\t\t\t    %d\n",process[b],priority[b],burstTime[b],arrivalTime[b],waitingTime[b],turnAroundTime[b]);
    }
 
    avgTAT=total/a; //average turnaround time
    printf("\n\n Average Waiting Time=%d\n",avgWT);
    printf("\n\n Average Turnaround Time=%d\n",avgTAT);
 
	return 0;
}
