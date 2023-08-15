#include <stdio.h>

int frames[10], pages[50], Queue[10], front=-1, rear=-1;

int pop() {
	int t = Queue[rear];
	rear = (rear+1)%10;
	return t;
}

void push(int n) {
	if(rear==-1) {
		rear=0;
	}
	front = (front+1)%10;
	Queue[front] = n;
}


int main() {
	int no_of_frame, no_of_page, flag=0, position=0, page_hit=0;

	printf("Enter the number of pages : ");
	scanf("%d", &no_of_page);

	printf("Enter the number of frames : ");
	scanf("%d", &no_of_frame);

	printf("Enter the reference string : ");
	for(int i=0; i<no_of_page; i++) {
		scanf("%d", &pages[i]);
	}

	for(int i=0; i<no_of_frame; i++)
		frames[i] = -1;

	printf("Page\t\tFrames\n");
	for(int i=0; i<no_of_page; i++) {
		flag = 0;
		for(int j=0; j<no_of_frame; j++) {
			if(frames[j] == pages[i]) {
				flag = 1;
				pop();
				push(j);
				break;
			} else if(frames[j] == -1) {
				frames[j] = pages[i];
				flag = -1;
				push(j);
				break;
			}
		}
		
		printf("%d\t\t", pages[i]);
				
		if(flag == 1) {
			printf("page hit\n");
			page_hit++;
		} else {
			if(flag == 0) {
				position = pop();
				frames[position] = pages[i];
				push(position);
			}
			for(int j=0; j<no_of_frame; j++) {
				printf("%d\t", frames[j]);
			}
			printf("\n");
		}
	}

	printf("Page fault : %d\n", no_of_page-page_hit);
	printf("Page hit : %d\n", page_hit);
}

/*
Enter the number of pages : 10
Enter the number of frames : 3
Enter the reference string : 2 3 4 2 1 3 7 5 4 3
Page            Frames
2               2       -1      -1
3               2       3       -1
4               2       3       4
2               page hit
1               2       1       4
3               2       1       3
7               7       1       3
5               7       5       3
4               7       5       4
3               3       5       4
Page fault : 9
Page hit : 1
*/
