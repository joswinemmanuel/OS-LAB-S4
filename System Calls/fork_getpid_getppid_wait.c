#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int pid;
	pid = fork();
	
	if(pid<0) {
		fprintf(stderr, "Fork failed");
	}
	else if(pid==0) {
		printf("Child id : %d\n", getpid());
		printf("Parent id : %d\n", getppid());
	}
	else {
		wait(NULL);
		printf("Parent present\n");
		printf("Parent id : %d\n", getpid());
	}
}
