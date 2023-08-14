#include <stdio.h>
#include <unistd.h>

int main() {
	char *args[] = {"./sample", NULL};
	// run file or executable file of another program saved as sample
	// gcc program.c -o sample
	execvp(args[0], args);
	printf("Empty");
}
 
