#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int pid;
	printf("Using getpid(), The process id of current process: %d\n", getpid());
	printf("fork() creates child process\n");
	if(fork() != 0){
		printf("Parent process starts and wait() executes\n");
		wait(NULL);
		printf("waiting and executes another funtion");
		char *args[] = {"ls",NULL};
		execvp(args[0], args);
		exit(0);
		printf("executes not ends and parent ends");
	} else {
		printf("Child process starts and ends\n");
	}
	printf("exit function\n");
	exit(0);
	printf("exit not executing");
	return 0;
}

/*
Using getpid(), The process id of current process: 13991
fork() creates child process
Parent process starts and wait() executes
Child process starts and ends
exit function
a.out	 getpid_getppid.c  p2.c		program2.sh  program4.sh  program6.sh
demodir  p1.c		   program1.sh	program3.sh  program5.sh  program7.sh
*/
