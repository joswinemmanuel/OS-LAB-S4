#include <stdio.h>

int main() {
	int i, j, count[50], frames[10], pages[50], fn, pn, flag, fPos, ph=0;
	
	printf("Enter the number of pages : ");
	scanf("%d", &pn);
	
	printf("Enter the reference string : ");
	for(i=0; i<pn; i++) {
		scanf("%d", &pages[i]);
		count[i] = 0;
	}
	
	printf("Enter the number of frames : ");
	scanf("%d", &fn);
	
	printf("\nPage\t\tFrames\n");
	for(i=0; i<fn; i++)
		frames[i] = -1;
		
	for(i=0; i<pn; i++) {
		flag = 0;
		fPos = 0;
		for(j=0; j<fn; j++) {
			if(frames[j] == pages[i]) {
				flag = 1;
				break;
			}
			if(count[frames[fPos]]>count[frames[j]]) {
				fPos = j;
			}
		}
		
		if(!flag) {
			frames[fPos] = pages[i];
		}
		
		printf("%d\t\t",pages[i]);
		if(flag) {
			printf("Page hit\n");
		} else {
			for(j=0; j<fn; j++) {
				printf("%d\t",frames[j]);
		}
		printf("\n");
		ph++;
		}
		count[pages[i]] += 1;
	}
	
	printf("Pagefault : %d\n", ph);
	printf("Page hit : %d\n", (pn-ph));
	return 0;
}

/*
Enter the number of pages : 10
Enter the reference string : 2 3 4 2 1 3 7 5 4 3
Enter the number of frames : 3

Page		Frames
2		2	-1	-1	
3		2	3	-1	
4		2	3	4	
2		Page hit
1		2	1	4	
3		2	3	4	
7		2	3	7	
5		2	3	5	
4		2	3	4	
3		Page hit
Pagefault : 8
Page hit : 2
*/
