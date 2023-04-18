#include<stdio.h>

struct process 
{
 int p,bt,priority,tat,wt,ct;
};

void main()
{
 int n,current_ct=0,a[10],k=0,i,j;
 double total_tat=0,total_wt=0;
 printf("Enter the number of prcesses : ");
 scanf("%d",&n);
 struct process p[n];
 for(i=0;i<n;i++)
 {
  printf("Enter the burst time of P%d : ",i);
  scanf("%d",&p[i].bt);
  printf("Enter the priority of P%d : ",i);
  scanf("%d",&p[i].priority);
  p[i].p=i;
 }
 for(i=0;i<n;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
   if(p[j].priority>p[j+1].priority)
   { 
    struct process temp=p[j];
    p[j]=p[j+1];
    p[j+1]=temp;
   }
  }
 }
 printf("\n");
 printf("Gantt Chart\n");
 printf("\n|");
 for(i=0;i<n;i++)
 {
  printf("P%d\t|",p[i].p);
  current_ct+=p[i].bt;
  p[i].ct=current_ct;
  p[i].tat=p[i].ct;
  p[i].wt=p[i].tat-p[i].bt;
 }

 printf("\n0\t");
 for(i=0;i<n;i++)
 {
  printf("\n%d\t",p[i].ct); 
 }
 printf("\n TA Time\tW Time\n");
 for(i=0;i<n;i++)
 {
  printf("P%d\t%d\t\t%d\n",i,p[i].tat,p[i].wt);
 }
 for(i=0;i<n;i++)
 {
  total_tat+=p[i].tat;
  total_wt+=p[i].wt;
 }
 printf("\nTotal Turnaround time : %.2f",total_tat);
 printf("\nTotal Waiting time : %.2f",total_wt);
 printf("\nAverage Turnaround time : %.2f",total_tat/n);
 printf("\nAverage Waiting time : %.2f",total_wt/n);
  
}
