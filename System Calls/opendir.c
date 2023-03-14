#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

struct dirent *dptr;

int main(int argc,char *argv[]){
	char buff[256];
	DIR *dirp;
	printf("\n\nEnter directory name : ");
	scanf("%s",buff);
	if((dirp=opendir(buff))==NULL){
		printf("Error\n");
		exit(1);
	}
	while(dptr=readdir(dirp)){
		printf("%s\n",dptr->d_name);
	}
	closedir(dirp);
	return 0;
}

/*
Enter directory name : demodir
.
a.c
..
*/
