// Name: Karishma Khanna
// Date: 4/8/21
// Title: Lab assignment 2: Programming in C and use of Systems Calls
// Description: (Part 1-4) This program calls fork() on parent processes that
// create child processes to show how fork() works. If the process returns -1,
// meaning creation of the child failed, it will print an error. If it succeeded,
// "parent process" will print, then when 0 is returned to indicate successful
// creation of a child, "child process" will print.

/*Sample C program for Lab assignment 2*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */

/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    pid_t pid;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before forking.\n");
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }
    if (pid) {
        // Parent process
        for (i=0;i<100;i++) {
            printf("\t \t \t Parent Process %d \n", i);
            usleep(n);
        }
    }
    else {
        // Child process
        for (i=0;i<100;i++) {
            printf("Child process %d\n", i);
            usleep(n);
        }
    }
    return 0;
}
