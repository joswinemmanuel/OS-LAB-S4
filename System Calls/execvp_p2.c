#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	char *args[] = {"joswin/sample", NULL};
	execvp(args[0], args);
	printf("Empty");
}
