#include <stdio.h>

struct process {
	int p, bt, priority, tat, wt, ct;
};

void main() {
	int n, current_ct=0, a[10], k=0, i, j;
	double total_tat=0, total_wt=0;
	printf("Enter the number of processes : ");
	scanf("%d", &n);
	struct process p[n];
	
	for(i=0; i<n; i++) {
		printf("Enter the burst time of P%d : ", i);
		scanf("%d", &p[i].bt);
		printf("Enter the priority of P%d : ", i);
		scanf("%d", &p[i].priority);
		p[i].p=i;
	}
	
	for(i=0; i<n; i++) {
		for(j=0; j<n-i-1; j++) {
			if(p[j].priority>p[j+1].priority) {
				struct process temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	
	printf("\n");
	printf("Gantt Chart\n");
	printf("--------------------------------\n|");
	for(i=0; i<n; i++) {
		printf("P%d\t|", p[i].p);
		current_ct += p[i].bt;
		p[i].ct = current_ct;
		p[i].tat = p[i].ct;
		p[i].wt = p[i].tat-p[i].bt;
	}
	
	printf("\n--------------------------------\n");
	printf("0\t");
	
	for(i=0; i<n; i++) {
		printf("%d\t", p[i].ct);
	}
	
	printf("\n Turnaround time\tWaiting time\n");
	
	for(i=0; i<n; i++) {
		printf("P%d\t%d\t\t%d\n", i, p[i].tat, p[i].wt);
	}
	
	for(i=0; i<n; i++) {
		total_tat += p[i].tat;
		total_wt += p[i].wt;
	}
	
	printf("\nTotal Turnaround time : %.2f", total_tat);
	printf("\nTotal Waiting time : %.2f", total_wt);
	printf("\nAverage Turnaround time : %.2f", total_tat/n);
	printf("\nAverage Waiting time : %.2f\n", total_wt/n);
}

/*

Enter the number of processes : 4
Enter the burst time of P0 : 6
Enter the priority of P0 : 4
Enter the burst time of P1 : 8
Enter the priority of P1 : 1
Enter the burst time of P2 : 7
Enter the priority of P2 : 3
Enter the burst time of P3 : 3
Enter the priority of P3 : 2

Gantt Chart
--------------------------------
|P1	|P3	|P2	|P0	|
--------------------------------
0	8	11	18	24	
 Turnaround time	Waiting time
P0	8		0
P1	11		8
P2	18		11
P3	24		18

Total Turnaround time : 61.00
Total	Waiting time : 37.00
Average Turnaround time : 15.25
Average Waiting time : 9.25

*/
