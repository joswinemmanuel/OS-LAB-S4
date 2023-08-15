#include <stdio.h>

int findpos(int x);
int blocks[100], jobs[100], no_of_block, no_of_job;

int main() {
	printf("Enter the number of blocks : ");
	scanf("%d", &no_of_block);
	printf("Enter the number of jobs : ");
	scanf("%d", &no_of_job);

	int visited[no_of_job];

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
		int j = findpos(jobs[i]);
		if(j != 100) {
			visited[i] = blocks[j];
			blocks[j] -= jobs[i];
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

int findpos(int x) {
	int smallest=100000, found=0, index=0;
	for(int i=0; i<no_of_block; i++) {
		if(blocks[i] >= x) {
			if(blocks[i] < smallest) {
				found = 1;
				smallest = blocks[i];
				index = i;
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
Enter the size of the blocks : 161 175 500 320 400
Enter the size of the jobs : 140 301 75 200

STATUS
140 Job is allocated to block 161
301 Job is allocated to block 320
75 Job is allocated to block 175
200 Job is allocated to block 400
*/
