#include <stdio.h>

int main() {
	int count[50], frames[10], pages[50], no_of_frame, no_of_page, flag, position, page_hit=0;

	printf("Enter the number of pages : ");
	scanf("%d", &no_of_page);

	printf("Enter the reference string : ");
	for(int i=0; i<no_of_page; i++) {
		scanf("%d", &pages[i]);
		count[i] = 0;
	}

	printf("Enter the number of frames : ");
	scanf("%d", &no_of_frame);

	printf("\nPage\t\tFrame\n");
	for(int i=0; i<no_of_frame; i++) {
		frames[i] = -1;
	}

	for(int i=0; i<no_of_page; i++) {
		flag = 0;
		position = 0;
		for(int j=0; j<no_of_frame; j++) {
			if(frames[j] == pages[i]) {
				flag = 1;
				break;
			}

			if(count[frames[position]]>count[frames[j]]) {
				position = j;
			}
		}

		printf("%d\t\t", pages[i]);

		if(flag) {
			printf("Page hit\n");
			page_hit++;
		} else {
			frames[position] = pages[i];

			for(int j=0; j<no_of_frame; j++) {
				printf("%d\t", frames[j]);
			}
			printf("\n");
		}
		count[pages[i]] += 1;
	}

	printf("Page fault : %d\n", no_of_page-page_hit);
	printf("Page hit : %d\n", page_hit);
	return 0;
}

/*
Enter the number of pages : 10
Enter the reference string : 2 3 4 2 1 3 7 5 4 3
Enter the number of frames : 3

Page            Frame
2               2       -1      -1
3               2       3       -1
4               2       3       4
2               Page hit
1               2       1       4
3               2       3       4
7               2       3       7
5               2       3       5
4               2       3       4
3               Page hit
Page fault : 8
Page hit : 2
*/
