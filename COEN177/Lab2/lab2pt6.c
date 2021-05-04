// Name: Karishma Khanna
// Date: 4/8/21
// Title: Lab assignment 2: Programming in C and use of Systems Calls
// Description: (Part 6) This program rewrites the program from steps 1-4 by
// replacing the two processes with two parent/child threads instead of if blocks.
// Unlike processes, which do not share memory space, threads within processes
// do share parts of the memory space.

/*Sample C program for Lab assignment 2*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */
#include <pthread.h>    /* pthread_create, pthread_join, pthread_exit */

void *ParentThread(void *ptr) {
    int i, n =* (int *) ptr;
    // Parent process
    for (i=0;i<100;i++) {
        printf("\t \t \t Parent Process %d \n", i);
        usleep(n);
    }
    return NULL;
}

void *ChildThread(void *ptr) {
    int i, n =* (int *) ptr;
    // Child process
    for (i=0;i<100;i++) {
        printf("Child process %d\n", i);
        usleep(n);
    }
    return NULL;
}

/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    pthread_t pthread, cthread; // create parent and child threads
    int n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    int* args = malloc(sizeof(int)); // allocates space in heap to store int, points to space
    args[0] = n; // set the first part of this memory to n
    printf("\nBefore threading.\n");
    pthread_create(&pthread, NULL, ParentThread, (void *) args); // send pthread to parent function
    pthread_create(&cthread, NULL, ChildThread, (void *) args); // send cthread to child function
    pthread_join(pthread, NULL); // wait for pthread process to finish
    pthread_join(cthread, NULL); // wait for cthread process to finish
    pthread_exit(NULL); // exits main and cleans up threads
    return 0;
}
