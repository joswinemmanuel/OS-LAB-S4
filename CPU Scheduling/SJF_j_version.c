#include<stdio.h>
struct process
{
 int p,bt,at,tat,wt,ct;
};
int n,vis[20];
struct process p[20];
int smallest_bt(int current_at);
void main(){
int count=0,i,j,current_at=0;
printf("Enter no of process:\n");
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++){
printf("Enter the burst time of P%d:",i);
scanf("%d",&p[i].bt);
printf("Enter the arrival time of P%d:",i);
scanf("%d",&p[i].at);
p[i].p=i;
}
for(i=0;i<n;i++){
for(j=0;j<n-i-1;j++){
if(p[j].at>p[j+1].at)
{
struct process temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;}
}
}
j=0;
for(i=0;i<n;i++)
vis[i]=0;
printf("\n");
printf("-------------------------------------------\n|");
do{
i=smallest_bt(current_at);
a[j++]=i;
printf("P%d\t|",p[i].p);
current_at+=p[i].bt;
p[i].ct=current_at;
count++;
}
while(count!=n);
printf("\n-------------------------------------------\n|");
j=0;
printf("0\t");
for(i=0;i<n;i++){
printf("%d\t",p[a[j++]].ct);
}
for(i=0;i<n;i++){
p[i].tat=p[i].ct-p[i].at;
p[i].wt=p[i].tat-p[i].bt;
}
printf("\nTurnaround time\t Burst time\n");
for(i=0;i<n;i++){
printf("P%d| %d\t\t\t%d\n",p[i].p,p[i].tat,p[i].wt);
}
float avgtat=0,avgwt=0;
for(i=0;i<n;i++){
avgtat+=p[i].tat;
avgwt+=p[i].wt;
}
printf("\n%f %f",avgtat/n,avgwt/n);
}
int smallest_bt(int current_at){
int i;
int smallest_bt=100000;
int smallest=0;
for(i=0;i<n;i++){
if(p[i].at>current_at)
break;
else{
if(p[i].bt<smallest_bt&&vis[i]==0){
smallest_bt=p[i].bt;
smallest=i;}
}}
vis[smallest]=1;
return smallest;
}
