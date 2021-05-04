/* # Name: Anoushka Gupta
 * # Date: 03/12/2021 (Th 9:15am)
 * # Title: Lab9 – File Performance Measurement
 * # Description: Observations
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
pthread_cond_t mutex, empty, full;	//initializing condition variables mutex, empty, full
pthread_mutex_t lock;			//initializing mutex lock

int buff[N];		//creating buffer, initializing write/read indexes and counter (to keep track of buffer capacity)
int write_i = 0;
int read_i = 0;
int counter = 0;

void* produced(void* arg) {	//function to produce items
        int item;
        do {
                item = rand() % 100;	//generating random item to produce
		pthread_mutex_lock(&lock);	//lock the lock
		while (counter == N)		//while buffer is full
			pthread_cond_wait(&empty, &lock);
		buff[write_i++ % 10] = item;	//adding (writing) item into the buffer
		counter++;			//increment counter after adding to buffer
                printf("%d is produced\n", item);
		pthread_cond_signal(&full);	//signal(full)
                pthread_mutex_unlock(&lock);	//unlock the lock
                sleep(1);
        }
        while(1);
}

void* consumed(void* arg) {
        int item;
        do {
                pthread_mutex_lock(&lock);	//lock the lock
                while (counter == 0)		//while buffer is empty
                        pthread_cond_wait(&full, &lock);
                item = buff[read_i++ % 10];	//taking (reading) item from the buffer
		counter--;			//decrement counter after removing from buffer
                printf("\t %d is consumed\n", item);
                pthread_cond_signal(&empty);	//signal(empty)
		pthread_mutex_unlock(&lock);	//unlock the lock
                sleep(1);
        }
        while(1);
}

int main() {				//main function to only initialize/destroy locks and conditions, create/join threads
        srand(time(NULL));

        pthread_mutex_init(&lock, NULL);
	pthread_cond_init(&empty, NULL);
        pthread_cond_init(&full, NULL);

        pthread_create(&prod, NULL, produced, 0);
        pthread_create(&cons, NULL, consumed, 0);

        pthread_join(prod, NULL);
        pthread_join(cons, NULL);

        pthread_cond_destroy(&empty);
        pthread_cond_destroy(&full);
	pthread_mutex_destroy(&lock);

        return 0;
}
