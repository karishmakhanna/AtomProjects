// Name: Karishma Khanna
// Date: 4/8/21
// Title: Lab assignment 2: Programming in C and use of Systems Calls
// Description: (Part 7) This program rewrites the program from steps 1-4 so
// that the child process runs the ls command using execlp(), and that the parent
// process waits until the child process terminates before it exits.

/*Sample C program for Lab assignment 2*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */
#include <sys/wait.h>   /* wait */

/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    pid_t pid;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\nBefore forking.\n");
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
        wait(NULL); // wait for child process to finish
        printf("Child Complete\n"); // display completion message
        exit(0); // indicates successful program termination
    }
    else {
        // Child process
        for (i=0;i<100;i++) {
            printf("Child process %d\n", i);
            usleep(n);
        }
        execlp("/bin/ls", "ls", NULL); // child process runs ls command
        exit(0); // return to parent
    }
    return 0;
}
