#include <stdio.h>

int queue[20];
int rear = -1;
void enqueue(int process);
int frames, count=0, page_fault=0;

void main() {
	int n, i;
	printf("Enter the number of pages : ");
	scanf("%d", &n);
	int p[n];
	printf("Enter the page sequence : ");
	for(i=0; i<n; i++)
		scanf("%d", &p[i]);
	printf("Enter the number of frames : ");
	scanf("%d", &frames);
	for(i=0; i<n; i++)
		enqueue(p[i]);
	printf("\n\nPage faults : %d", page_fault);
	printf("\npage Hits : %d\n", (n-page_fault));
}

void enqueue(int process) {
	int i, j;
	if(count != frames) {
		rear = (rear+1)%frames;
		queue[rear] = process;
		count++;
		printf("page %d : ", process);
		for(i=0; i<count; i++)
			printf("%d ", queue[i]);
		printf("\n");
		page_fault++;
	} else {
		for(i=0; i<frames; i++)	{
			if(queue[i]==process) {
				printf("page %d : ", process);
				for(j=0; j<frames; j++)
					printf("%d ", queue[j]);
				printf("\n");
				return;
			}
		}
		
	rear = (rear+1)%frames;
	queue[rear] = process;
	printf("page %d : ", process);
	for(j=0; j<frames; j++)
		printf("%d ", queue[j]);
	printf("\n");
	page_fault++;
	}
}

/*
Enter the number of pages : 20 
Enter the page sequence : 7 2 3 1 2 5 3 4 6 7 7 1 0 5 4 6 2 3 0 1
Enter the number of frames : 3
page 7 : 7 
page 2 : 7 2 
page 3 : 7 2 3 
page 1 : 1 2 3 
page 2 : 1 2 3 
page 5 : 1 5 3 
page 3 : 1 5 3 
page 4 : 1 5 4 
page 6 : 6 5 4 
page 7 : 6 7 4 
page 7 : 6 7 4 
page 1 : 6 7 1 
page 0 : 0 7 1 
page 5 : 0 5 1 
page 4 : 0 5 4 
page 6 : 6 5 4 
page 2 : 6 2 4 
page 3 : 6 2 3 
page 0 : 0 2 3 
page 1 : 0 1 3 


Page faults : 17
page Hits : 3
*/
