#include <stdio.h>
#include <stdlib.h>
 
int mutex=1, full=0, empty=3, x=0;

int wait(int s) {
    return --s;
}
 
int signal(int s) {
    return ++s;
}
 
void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("Producer produced the item %d\n", x);
    mutex = signal(mutex);
}
 
void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("Consumer consumed item %d\n", x);
    x--;
    mutex = signal(mutex);
}
 
int main() {
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("\n1.Producer\n2.Consumer\n3.Exit\n");
    while(1) {
        printf("\nEnter your choice : ");
        scanf("%d", &n);
        switch(n) {
            case 1:    
            	if((mutex==1)&&(empty!=0))
                	producer();
                else
                	printf("Buffer is full\n");
                break;
            case 2:
                if((mutex==1)&&(full!=0))
               		consumer();
               	else
                        printf("Buffer is empty\n");
                break;
            case 3:
                exit(0);
               	break;
        }
    }
   
    return 0;
}
 
