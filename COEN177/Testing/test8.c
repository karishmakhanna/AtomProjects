#include <stdio.h>
 #include <stdlib.h>
 #include <pthread.h>
 void *go(void *);
 #define NTHREADS 10
 pthread_t threads [NTHREADS];

 int main() {
     int i;
     printf("The i value = ");
     for (i = 0; i < NTHREADS; i++) {
     pthread_create(&threads [i], NULL, go, (void *)(size_t)i);
 }
     for (i = 0; i < NTHREADS; i++) {
     pthread_join(threads[i], NULL);
    }
     putchar ('\n');
     return 0;
 }
 void *go (void *arg) {
     printf(" %d, ", (int)(size_t *) arg);
     pthread_exit(0);
 }
