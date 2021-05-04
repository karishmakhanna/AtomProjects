// Name: Karishma Khanna
// Date: 4/8/21
// Title: Lab assignment 2: Programming in C and use of Systems Calls
// Description: (Part 5) This program results in the creation of exactly 7 processes,
// including the parent process. Each process is allowed to create exactly 2 or 0 children.
// I used the fork() system call 6 times inside nested if blocks to achieve this.
// For each node wih two children, if fork() results in pid==0, one child is printed, else
// if pid>0, another nested if block is called with fork() that does the same thing where
// if pid==0, a second child is created, else the parent is called. Three of these structures
// are needed to make 7 processes, so 3*2 fork() calls are invoked.
//                   Parent
//                  |      |
//           Child 1        Child 2
//          |      |        |       |
//    Child 3   Child 4   Child 5   Child 6

/*Sample C program for Lab assignment 2*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */
#include <sys/wait.h>   /* wait */

/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    pid_t fork1, fork2, fork3, fork4, fork5, fork6; // six forks
    printf("\nBefore forking.\n");
    fork1 = fork();
    if(fork1 == -1) {
        printf("Can't fork, Error\n");
        exit(1); // terminate if error
    } else if(fork1) { // in charge of the child 256 branch and parent
        fork2 = fork();
        if(fork2 == -1) {
            printf("Can't fork, Error\n");
            exit(1); // terminate if error
        } else if(fork2) { // in charge of parent
            printf("\nParent Process:\nParent PID:%d\nParent PPID :%d\n",getpid(),getppid()); // calls parent process
            wait(NULL); // wait for children 256
        } else { // in charge of child 256 branch
            fork3 = fork();
            if(fork3 == -1) {
                printf("Can't fork, Error\n");
                exit(1); // terminate if error
            } else if(fork3) { // in charge of child 6 branch and child 2
                fork4 = fork();
                if(fork4 == -1) {
                    printf("Can't fork, Error\n");
                    exit(1); // terminate if error
                } else if(fork4) { // in charge of child 2
                    printf("Child Process 2:\nChild 2 PID :%d\nChild 2 PPID:%d\n",getpid(),getppid()); // calls child 2 process
                    wait(NULL); // wait for child 6
                } else { // in charge of child 6
                    printf("Child Process 6:\nChild 6 PID :%d\nChild 6 PPID:%d\n",getpid(),getppid()); // calls child 6 process
                    exit(0); // return to child 2
                }
                wait(NULL); // wait for child 5
            } else { // in charge of child 5 branch
                printf("Child Process 5:\nChild 5 PID :%d\nChild 5 PPID:%d\n",getpid(),getppid()); // calls child 5 process
                exit(0); // return to child 2
            }
            exit(0); // return to parent
        }
        wait(NULL); // wait for children 134
    } else { // in charge of the child 134 branch
        fork5 = fork();
        if(fork5 == -1) {
            printf("Can't fork, Error\n");
            exit(1); // terminate if error
        } else if(fork5) { // in charge of child 4 branch and child 1
            fork6 = fork();
            if(fork6 == -1) {
                printf("Can't fork, Error\n");
                exit(1); // terminate if error
            } else if(fork6) { // in charge of child 1
                printf("Child Process 1:\nChild 1 PID :%d\nChild 1 PPID:%d\n",getpid(),getppid()); // calls child 1 process
                wait(NULL); // wait for child 4
            } else { // in charge of child 4
                printf("Child Process 4:\nChild 4 PID :%d\nChild 4 PPID:%d\n",getpid(),getppid()); // calls child 4 process
                exit(0); // return to child 1
            }
            wait(NULL); // wait for child 3
        } else { // in charge of child 3 branch
            printf("Child Process 3:\nChild 3 PID :%d\nChild 3 PPID:%d\n",getpid(),getppid()); // calls child 3 process
            exit(0); // return to child 1
        }
        exit(0); // return to parent
    }
    return 0;
}
