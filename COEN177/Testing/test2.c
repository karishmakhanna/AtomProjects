#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NTHREADS 3
void *go(void *);
pthread_t threads[NTHREADS];

int main() {
 static int i;
 for (i = 0; i < NTHREADS; i++)
    pthread_create(&threads[i], NULL, go, (void*)(size_t)i);
 printf("Hello\n");
 return 0;
}

void *go(void *arg) {
 sleep(10);
 printf("Hello %d \n", (int)(size_t *)arg);
 pthread_exit(0);
} 
