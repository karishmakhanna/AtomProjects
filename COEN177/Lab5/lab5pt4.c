// Name: Karishma Khanna
// Date: 4/29/21
// Title: Lab 5: Synchronization using semaphores, lock, and condition variables
// Description: (Part 4) This program program solves the producer - consumer problem using semaphores.

// Producer - Consumer with semaphores

//Shared data: semaphore full, empty, mutex;
//pool of n buffers, each can hold one item
//mutex provides mutual exclusion to the buffer pool
//empty and full count the number of empty and full buffers
//Initially: full = 0, empty = n, mutex = 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define BUFSIZE 10
#define NP 3
#define NC 2

pthread_t tidP[NP], tidC[NC];
int buff[BUFSIZE];
sem_t *mutex, *full, *empty;
int p, c, in, out;

void *producer(void *arg) {
    int item;
    int p = (int)arg;
    do {
        srand(time(0));
        item = (rand() % 100);  // random number for producer
        sem_wait(empty);
        sem_wait(mutex);
        buff[in] = item; // code to add item to buffer
        in = (in+1) % BUFSIZE; // code to  increment in index
        printf ("Producer #: %d produced item: %d at buffer space: %d\n", p, item, in);
        sleep(5);
        sem_post(mutex);
        sem_post(full);
    } while (1);
    pthread_exit(0);
}

void *consumer(void *arg) {
    int item;
    int c = (int)arg;
    //srand(time(0));
    do {
        sem_wait(full);
        sem_wait(mutex);
        item = buff[out]; // code to remove next item from buffer
        out = (out+1) % BUFSIZE;; // code to increment out index
        printf ("\t\t\tConsumer #: %d consumed item: %d at buffer space: %d\n", c, item, out);
        sleep(10);
        sem_post(mutex);
        sem_post(empty);
    } while (1);
    pthread_exit(0);
}

void cleanup(int sigtype){
    // destroy semaphores before terminating
    sem_unlink("mutex");
    sem_unlink("empty");
    sem_unlink("full");
    printf("\n Terminating\n");
    exit(0);
}

int main () {
    signal(SIGINT,cleanup); // cleanup before starting
    mutex = sem_open("mutex", O_CREAT, 0644, 1); // create mutex semaphore, initially set to 1
    full = sem_open("full", O_CREAT, 0644, 0); // create full semaphore, initally set to 0
    empty = sem_open("empty", O_CREAT, 0644, BUFSIZE); // create empty semaphore, initally set to BUFSIZE (n)
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
        pthread_join(tidP[c], NULL);
        printf("\t\t\tConsumer thread %d returned\n", c);
    }
    printf("Main thread finished\n");
    signal(SIGINT, cleanup); // destroy semaphores
    return 0;
}
