#include <stdio.h>

int main() {
	int frames[10], pages[50], no_of_frame, no_of_page, flag=0, position=0, page_hit=0;

	printf("Enter the number of pages : ");
	scanf("%d", &no_of_page);

	printf("Enter the number of frames : ");
	scanf("%d", &no_of_frame);

	printf("Enter the reference string : ");
	for(int i=0; i<no_of_page; i++) {
		scanf("%d", &pages[i]);
	}

	printf("\nPage\t\tFrame\n");
	for(int i=0; i<no_of_frame; i++) {
		frames[i] = -1;
	}

	for(int i=0; i<no_of_page; i++) {
		flag = 0;
		for(int j=0; j<no_of_frame; j++) {
			if(frames[j] == pages[i]) {
				flag = 1;
				break;
			}
		}

		printf("%d\t\t", pages[i]);

		if(flag == 1) {
			printf("Page hit\n");
			page_hit++;
		} else {
			frames[position] = pages[i];
			position = (position+1) % no_of_frame;

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
Enter the number of pages : 20
Enter the number of frames : 3
Enter the reference string : 7 2 3 1 2 5 3 4 6 7 7 1 0 5 4 6 2 3 0 1

Page            Frame
7               7       -1      -1
2               7       2       -1
3               7       2       3
1               1       2       3
2               Page hit
5               1       5       3
3               Page hit
4               1       5       4
6               6       5       4
7               6       7       4
7               Page hit
1               6       7       1
0               0       7       1
5               0       5       1
4               0       5       4
6               6       5       4
2               6       2       4
3               6       2       3
0               0       2       3
1               0       1       3
Page fault : 17
Page hit : 3
*/
