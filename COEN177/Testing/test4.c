#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *go(void *);
pthread_t threads;

int main() {
    int i = 3;
    if (fork() == 0) {
        pthread_create(&threads, NULL, go, &i);
    }
    else if (fork() == 0) {
        pthread_create(&threads, NULL, go, &i);
    }
    pthread_join(threads, NULL);
    return 0;
}

void *go(void *arg) {
    printf("Hello from thread %d with thread ID %d \n", *(int *)arg, (int)pthread_self());
    return 0;
}
