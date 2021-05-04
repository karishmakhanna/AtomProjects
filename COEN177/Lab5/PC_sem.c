/* # Name: Anoushka Gupta
 * # Date: 02/07/2021 (Th 9:15am)
 * # Title: Lab5 – Synchronization using semaphores, lock, and condition variables
 * # Description: Producer Consumer Problem using semaphores
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>

#define N 10

pthread_t cons, prod;
sem_t *mutex, *empty, *full;	//sem mutex, empty, full declaration

int buff[N];		//creating buffer and initializing read/write indexes
int write_i = 0;
int read_i = 0;

void unlinkSemaphore(int x) {	//function to unlink semaphores when closing program
        sem_unlink("mutex");
        sem_unlink("empty");
        sem_unlink("full");
        printf("\nUnlink\n");
        exit(0);
}

void* produced(void* arg) {	//function to produce items
        int item;
        do {
                sem_wait(empty);	//waiting (opening) sem empty, mutex
                sem_wait(mutex);
                item = rand() % 100;	//generating random item to produce
                buff[write_i++ % 10] = item;	//adding (writing) item into the buffer
                printf("%d is produced\n", item);
                sem_post(mutex);	//post (signal) sem mutex, full
                sem_post(full);
                sleep(1);
        }
        while(1);
}

void* consumed(void* arg) {	//function to consume items
        int item;
        do {
                sem_wait(full);		//waiting (opening) sem full, mutex
                sem_wait(mutex);
                item = buff[read_i++ % 10];	//taking (reading) item from the buffer
                printf("\t %d is consumed\n", item);
                sem_post(mutex);	//post (signal) sem mutex, empty
                sem_post(empty);
                sleep(1);
        }
        while(1);
}

int main() {
        srand(time(NULL));
        signal(SIGINT, unlinkSemaphore);
        mutex = sem_open("mutex", O_CREAT, 0644, 1);	//sem open to initialize mutex=1, empty=N, full=0
        empty = sem_open("empty", O_CREAT, 0644, N);
        full = sem_open("full", O_CREAT, 0644, 0);

        pthread_create(&prod, NULL, produced, NULL);	//creating threads for producer and consumer
        sleep(4);
        pthread_create(&cons, NULL, consumed, NULL);

        pthread_join(prod, NULL);			//joining threads for producer and consumer
        pthread_join(cons, NULL);

        sem_unlink("mutex");		//unlinking semaphores
        sem_unlink("empty");
        sem_unlink("full");

        return 0;
}
