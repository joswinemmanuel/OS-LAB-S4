#include <stdio.h>

void main() {
	int i, j, n1, n2;
	printf("Enter the number of blocks : ");
	scanf("%d", &n1);
	printf("Enter the number of jobs : ");
	scanf("%d", &n2);
	int a[n1], b[n2], vis[n2], c[n1];
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
		for(j=0; j<n1; j++) {
			if(a[j] >= b[i]) {
	   			vis[i] = a[j];
	   			a[j] = a[j]-b[i];
	   			break;
	  		}
	 	}
	}
	
	printf("\nSTATUS");
	for(i=0; i<n2; i++) {
		if(vis[i] == 0) {
	    		printf("\n%d Job is waiting", b[i]);
	   	} else {
			printf(" \n%d Job is inserted into the block %d", b[i], vis[i]);
	  	}
	}
	printf("\n");     
} 
