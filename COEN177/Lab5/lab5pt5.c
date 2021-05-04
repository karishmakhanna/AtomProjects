// Name: Karishma Khanna
// Date: 4/29/21
// Title: Lab 5: Synchronization using semaphores, lock, and condition variables
// Description: (Part 5) This program program solves the producer - consumer problem using condition variables.

// Producer - Consumer with condition variable

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define BUFSIZE 10
#define NP 3
#define NC 2

pthread_t tidP[NP], tidC[NC];
int buff[BUFSIZE];
pthread_mutex_t mutex;
pthread_cond_t full, empty;
int p, c, in, out, count;

void *producer(void *arg) {
    int item;
    int p = (int)arg;
    do {
        srand(time(0));
        item = (rand() % 100);  // random number for producer
        pthread_mutex_lock(&mutex);
        while(count == BUFSIZE)
            pthread_cond_wait(&empty, &mutex);
        buff[in] = item; // code to add item to buffer
        in = (in+1) % BUFSIZE; // code to  increment in index
        printf ("Producer #: %d produced item: %d at buffer space: %d\n", p, item, in);
        count++;
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);
        sleep(12);
    } while (1);
    pthread_exit(0);
}

void *consumer(void *arg) {
    int item;
    int c = (int)arg;
    //srand(time(0));
    do {
        pthread_mutex_lock(&mutex);
        while (count == 0)
            pthread_cond_wait(&full, &mutex);
        item = buff[out]; // code to remove next item from buffer
        out = (out+1) % BUFSIZE;; // code to increment out index
        printf ("\t\t\tConsumer #: %d consumed item: %d at buffer space: %d\n", c, item, out);
        count--;
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
        sleep(12);
    } while (1);
    pthread_exit(0);
}

int main () {
    //your code to create mutex lock and empty and full condition variables
    pthread_mutex_init(&mutex, NULL); // create mutex
    pthread_cond_init(&empty, NULL); // create empty
    pthread_cond_init(&full, NULL); // create full
    for (p = 0; p < NP; p++)
        pthread_create(&tidP[p], NULL, producer, (void *)(size_t)p); // code to pass arguments to producer thread
    for (c = 0; c < NC; c++)
        pthread_create(&tidC[c], NULL, consumer, (void *)(size_t)c); // code to pass arguments to consumer thread
    // main thread waiting for consumer and producer threads to complete their tasks
    for (p = 0; p < NP; p++) {
        pthread_join(tidP[p], NULL);
        printf("Producer thread %d returned\n", p);
    }
    for (c = 0; c < NC; c++) {
        pthread_join(tidC[c], NULL);
        printf("\t\t\tConsumer thread %d returned\n", c);
    }
    printf("Main thread finished\n");
    // code to destroy mutex lock and empty and full condition variables
    pthread_mutex_destroy(&mutex); // destroy mutex
    pthread_cond_destroy(&empty); // destroy empty
    pthread_cond_destroy(&full); // destroy full
    return 0;
}
