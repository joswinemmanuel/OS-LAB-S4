#include<stdio.h>

typedef struct {
    int arrT;
    int compT;
    int burstT;
    int tat;
    int wT;
    int p_name;
} process;

process pr[50],temp;

int main() {
    int n, i, j, com=0;
    float avgTT, avgWT, tTT=0, tWT=0;
    printf("Enter the number of process : ");
    scanf("%d", &n);
    printf("\n");
    for(i=0; i<n; i++){
        printf("Enter the arrival time of P%d : ",i);
        scanf("%d", &pr[i].arrT);
        printf("Enter the burst time of P%d : ",i);
        scanf("%d", &pr[i].burstT);
    }
    
    for(int i=0; i<n; i++) {
    	pr[i].p_name = i;
    }
       
    for(i=0;i<n;i++) {
        for(j=0; j<n-i-1; j++){
            if(pr[j].arrT > pr[j+1].arrT) {
                temp = pr[j];
                pr[j] = pr[j+1];
                pr[j+1] = temp;
            }
        }
    }
    
    printf("\nGantt Chart :\n ");
    printf("|");
    for(int i=0; i<n; i++) {
    	printf(" P%d  |" ,pr[i].p_name);
    }
    printf("\n");
    int st=0;
    printf(" %d",st);
    for(int i=0; i<n; i++) {
    	st = st+pr[i].burstT;
    	printf("     %d", st);
    }
    printf("\n");
    
    for(i=0; i<n; i++) {
        if(com < pr[i].arrT){
            com = pr[i].arrT;
        }
        pr[i].compT = pr[i].burstT+com;
        pr[i].tat = pr[i].compT-pr[i].arrT;
        pr[i].wT = pr[i].tat-pr[i].burstT;
        com = pr[i].compT;
    }
    printf("\nprocess\tarr\ttt\twt\n");
    for(i=0;i<n;i++) {
        printf("P%d\t%d\t%d\t%d\n", i, pr[i].arrT, pr[i].tat, pr[i].wT);
        tTT += pr[i].tat;
        tWT += pr[i].wT;
    }
    avgTT = tTT/n;
    avgWT = tWT/n;
    printf("\nThe average waiting time is : %.2f \n", avgWT);
    printf("The average turn around time is : %.2f \n", avgTT);
}

/*
Enter the number of process : 5

Enter the arrival time of P0 : 2
Enter the burst time of P0 : 6
Enter the arrival time of P1 : 5
Enter the burst time of P1 : 2
Enter the arrival time of P2 : 1
Enter the burst time of P2 : 8
Enter the arrival time of P3 : 0
Enter the burst time of P3 : 3
Enter the arrival time of P4 : 4
Enter the burst time of P4 : 4

Gantt Chart :
 | P3  | P2  | P0  | P4  | P1  |
 0     3     11     17     21     23

process arr     tt      wt
P0      0       3       0
P1      1       10      2
P2      2       15      9
P3      4       17      13
P4      5       18      16

The average waiting time is : 8.00 
The average turn around time is : 12.60 

*/
