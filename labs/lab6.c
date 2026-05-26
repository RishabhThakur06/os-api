#include <stdio.h>
#include <stdlib.h>
int mutex = 1, full = 0, empty = 3, x = 0;
void producer();
void consumer();
int wait(int);
int signal(int);
int main() {
int n;
printf("\n1. PRODUCER\n2. CONSUMER\n3. EXIT\n");
while (1) {
printf("\nENTER YOUR CHOICE\n");
scanf("%d", &n);
switch(n) {
case 1:
if ((mutex == 1) && (empty != 0)) {
producer();
} else {
printf("BUFFER IS FULL\n");
}
break;
case 2:
if ((mutex == 1) && (full != 0)) {
consumer();
} else {
printf("BUFFER IS EMPTY\n");
}
break;
case 3:
exit(0);
break;
default:
printf("Invalid choice! Please enter 1, 2, or 3.\n");
}
}
return 0;
}
int wait(int s) {
return (--s); // Decrement semaphore

}
int signal(int s) {
return (++s); // Increment semaphore
}
void producer() {
mutex = wait(mutex); // Enter critical section
full = signal(full); // Increase the number of full slots
empty = wait(empty); // Decrease the number of empty slots
x++; // Produce an item
printf("\nProducer produces the item %d\n", x);
mutex = signal(mutex); // Leave critical section
}
void consumer() {
mutex = wait(mutex); // Enter critical section
full = wait(full); // Decrease the number of full slots
empty = signal(empty); // Increase the number of empty slots
printf("\nConsumer consumes item %d\n", x);
x--; // Consume an item
mutex = signal(mutex); // Leave critical section
}