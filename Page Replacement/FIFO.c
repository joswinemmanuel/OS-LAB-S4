
#include<stdio.h>
int main(){
	int i, j, frames[10], pages[50], fn, pn, flag, fPos=0, ph=0, phh=0;
	
	printf("Enter the number of pages : ");
	scanf("%d", &pn);
	
	printf("Enter the reference string : ");
	for(i=0; i<pn; i++){
		scanf("%d", &pages[i]);
	}
	
	printf("Enter the number of frames : ");
	scanf("%d", &fn);
	
	printf("\nPage\t\tFrames\n");
	for(i=0; i<fn; i++)
		frames[i] = -1;
		
	for(i=0; i<pn; i++){
		flag = 0;
		for(j=0; j<fn; j++) {
			if(frames[j] == pages[i]) {
				flag = 1;
				break;
			}
		}
		
		if(!flag) {
			frames[fPos] = pages[i];
			fPos = (fPos+1)%fn;
		}
		
		printf("%d\t\t", pages[i]);
		if(flag) {
			printf("Page hit\n");
			phh++;
		} else {
			for(j=0; j<fn; j++) {
				printf("%d\t", frames[j]);
			}
			printf("\n");
		}
		ph++;
	}
	
	printf("Pagefault : %d\n", ph-phh);
	printf("Page hit : %d\n", phh);
	return 0;
}

/*
Enter the number of pages : 20
Enter the reference string : 7 2 3 1 2 5 3 4 6 7 7 1 0 5 4 6 2 3 0 1
Enter the number of frames : 3

Page		Frames
7		7	-1	-1	
2		7	2	-1	
3		7	2	3	
1		1	2	3	
2		Page hit
5		1	5	3	
3		Page hit
4		1	5	4	
6		6	5	4	
7		6	7	4	
7		Page hit
1		6	7	1	
0		0	7	1	
5		0	5	1	
4		0	5	4	
6		6	5	4	
2		6	2	4	
3		6	2	3	
0		0	2	3	
1		0	1	3	
Pagefault : 17
Page hit : 3

*/
