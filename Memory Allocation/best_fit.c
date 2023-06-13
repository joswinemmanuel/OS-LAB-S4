#include <stdio.h>

int n1, n2, a[20], b[20];
int findindex(int x);

void main(){
	int i, j;

	printf("Enter the number of blocks : ");
	scanf("%d", &n1);
	printf("Enter the number of jobs : ");
	scanf("%d", &n2);
	int vis[n2], c[n1];
	printf("Enter the size of blocks : ");
	for(i=0; i<n1; i++) {
	 	scanf("%d", &a[i]);
		c[i] = a[i];
	}
	printf("Enter the size of process : ");
	for(i=0; i<n2; i++) {
	 	vis[i] = 0;
	 	scanf("%d", &b[i]);
	}
	for(i=0; i<n2; i++) {
	 	j=findindex(b[i]);
	   	if(j != 100) {
	     		a[j] = a[j]-b[i];
	     		vis[i] = c[j];
	   	}
	}

	printf("\nSTATUS");
	for(i=0; i<n2; i++) {
	 	if(vis[i]==0) {
	    		printf("\n%d Job is waiting",b[i]);
	   	} else {
	    		printf("\n%d Job is inserted into the block %d", b[i], vis[i]);
	    	}
	}
	printf("\n");   
}

int findindex(int x) {
	int found=0, index, smallest=10000, i;
	for(i=0; i<n1; i++) {
		if(a[i] >= x) {
		 	if(a[i] < smallest) {
		     		found = 1;
		      		index = i;
		     		smallest = a[i];
		   	}
	     	}
	}
	if(found == 0)
		return 100;
	else
		return index;
}

/*
Enter the number of blocks : 5
Enter the number of jobs : 4
Enter the size of blocks : 161 175 500 320 400
Enter the size of process : 75 140 200 301

STATUS
75 Job is inserted into the block 161
140 Job is inserted into the block 175
200 Job is inserted into the block 320
301 Job is inserted into the block 400
*/
		    
		    
		    
