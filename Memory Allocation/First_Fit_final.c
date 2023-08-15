#include <stdio.h>

int main() {
	int no_of_block, no_of_job;
	printf("Enter the number of blocks : ");
	scanf("%d", &no_of_block);
	printf("Enter the number of jobs : ");
	scanf("%d", &no_of_job);

	int blocks[no_of_block], jobs[no_of_job], visited[no_of_job];

	printf("Enter the size of the blocks : ");
	for(int i=0; i<no_of_block; i++) {
		scanf("%d", &blocks[i]);
	}
	printf("Enter the size of the jobs : ");
	for(int i=0; i<no_of_job; i++) {
		scanf("%d", &jobs[i]);
		visited[i] = 0;
	}

	for(int i=0; i<no_of_job; i++) {
		for(int j=0; j<no_of_block; j++) {
			if(blocks[j] >= jobs[i]) {
				visited[i] = blocks[j];
				blocks[j] -= jobs[i];
				break;
			}
		}
	}

	printf("\nSTATUS\n");
	for(int i=0; i<no_of_job; i++) {
		if(visited[i] == 0)
			printf("%d Job is waiting\n", jobs[i]);
		else
			printf("%d Job is allocated to block %d\n", jobs[i], visited[i]);
	}
}

/*
Enter the number of blocks : 5
Enter the number of jobs : 4
Enter the size of the blocks : 100 500 200 300 600
Enter the size of the jobs : 212 417 112 426

STATUS
212 Job is allocated to block 500
417 Job is allocated to block 600
112 Job is allocated to block 288
426 Job is waiting
*/
