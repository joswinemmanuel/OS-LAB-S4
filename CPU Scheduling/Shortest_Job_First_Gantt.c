
#include <stdio.h>
#include <stdlib.h>

struct process
{
	int process_id;
	int arrival_time;
	int burst_time;
	int waiting_time;
	int turn_around_time;
};
int main()
{
	int n,i,j;
	int bt=0,k=1,tat=0,sum=0,min;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	struct process proc[n],temp;
	for(i=0;i<n;i++)
	{
		printf("\n");
		printf("Enter arrival time for process%d: ",i+1);
		scanf("%d",&proc[i].arrival_time);
		printf("Enter burst time for process%d: ",i+1);
		scanf("%d",&proc[i].burst_time);
		proc[i].process_id = i+1;
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(proc[i].arrival_time < proc[j].arrival_time)
			{
				temp = proc[j];
				proc[j] = proc[i];
				proc[i] = temp;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		bt+=proc[i].burst_time;
		min = proc[k].burst_time;
		for(j=k;j<n;j++)
		{
			if(bt>=proc[j].arrival_time && proc[j].burst_time<min)
			{
				temp=proc[k];
				proc[k]=proc[j];
				proc[j]=temp;
			}
		}
		k++;
	}
	proc[0].waiting_time=0;
	int wait_time_total=0;
	int turn_around_time_total=0;
	for(i=1;i<n;i++)
	{
		sum+=proc[i-1].burst_time;
		proc[i].waiting_time = sum-proc[i].arrival_time;
		wait_time_total += proc[i].waiting_time;
	}
	for(i=0;i<n;i++)
	{
		tat+=proc[i].burst_time;
		proc[i].turn_around_time = tat - proc[i].arrival_time;
		turn_around_time_total+=proc[i].turn_around_time;
	}
	
	printf("\nGantt chart : \n");
	printf("|");   
	for(i=0; i<n; i++) {
		printf("   %d   |", proc[i].process_id);
	}
	printf("\n0   ");
	for(i=0; i<n; i++) {
		printf("    %d   ", proc[i].turn_around_time+proc[i].arrival_time);
	}
	printf("\n\n");
	
	printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\n");

	for(i=0;i<n;i++)
	{

		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i].process_id,proc[i].burst_time, proc[i].arrival_time, proc[i].waiting_time,proc[i].turn_around_time);
	}
	printf("Average waiting time: %.2f\n", (float)wait_time_total/n);
	printf("Average turn around time: %.2f\n",(float)turn_around_time_total/n);

}

/*
Enter number of processes: 5

Enter arrival time for process1: 2
Enter burst time for process1: 6

Enter arrival time for process2: 5
Enter burst time for process2: 2

Enter arrival time for process3: 1
Enter burst time for process3: 8

Enter arrival time for process4: 0
Enter burst time for process4: 3

Enter arrival time for process5: 4
Enter burst time for process5: 4

Gantt chart : 
|   4   |   1   |   2   |   5   |   3   |
0       3       9       11       15       23   

Process	Burst Time	Arrival Time	Waiting Time	Turn-Around Time
4		3		0		0		3
1		6		2		1		7
2		2		5		4		6
5		4		4		7		11
3		8		1		14		22
Average waiting time: 5.20
Average turn around time: 9.80

*/
