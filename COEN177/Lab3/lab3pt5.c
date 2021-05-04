// Name: Karishma Khanna
// Date: 4/15/21
// Title: Lab 3: Inter-process Communication – Pipes
// Description: (Part 5) This program implements producer-consumer message
// communication using pipes. The producer and the consumer share a common fixed-
// size buffer. The producer puts messages to the buffer while the consumer
// removes messages from the buffer.


/*Sample C program for Lab assignment 3*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

// main
int main(int argc,char *argv[]){
   int fds[2];
   char buff[60]={}; // initialize buffer to array of nulls
   int count=0;
   int i;
   pipe(fds);
   /*child 1 duplicates upstream into stdout */
   if (fork() == 0) {
       printf("\nWriter on the upstream end of the pipe: \n");
       close(fds[0]); // close downstream end
       printf("\nEnter your message in the reader...\n"); // pauses at "fgets" to execute child 2
       fgets(buff, 60, stdin); // returns from child 2 and reads cin contents into buffer
       printf("\nSent by producer: %s\n", buff); // prints outgoing message contents
       write(fds[1], buff, strlen(buff)); // writes from buffer into upstream pipe end
       memset(buff, 0, sizeof(buff)); // resets the buffer array and resumes execution at the read line in child 2
   }
   /*child 2 duplicates downstream into stdin */
   else if (fork() == 0) {
       printf("Reader on the downstream end of the pipe: \n");
       close(fds[1]); // close upstream end and pauses at "read" to return to fgets in child 1
       count = read(fds[0],buff,60); // returns from end of child 1 and reads from downstream pipe end into buffer
       printf("Received by consumer: %s\n", buff); // prints incoming message contents
       exit(0);
   }
   else {  /*parent closes both ends and wait for children*/
       close(fds[0]);
       close(fds[1]);
       wait(0);
       wait(0);
   }
return 0;
}
