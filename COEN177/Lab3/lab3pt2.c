// Name: Karishma Khanna
// Date: 4/15/21
// Title: Lab 3: Inter-process Communication – Pipes
// Description: (Part 2) This program creates a pipe where the upstream end
// closes the downstream end and writes terminal inputs to the screen, which it
// gets from the downstream end input. The downstream end closes the upstream
// end and reads input with a specified buffer speed, which it writes to the
// screen by sending it upstream. When the children are done, the parent waits
// and then both pipe ends.

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
   int count;
   int i;
   pipe(fds);
   if (fork()==0){
       printf("\nWriter on the upstream end of the pipe -> %d arguments \n",argc);
       close(fds[0]);
       for(i=0;i<argc;i++){
           write(fds[1],argv[i],strlen(argv[i]));
       }
       exit(0);
   }
   else if(fork()==0){
       printf("\nReader on the downstream end of the pipe \n");
       close(fds[1]);
       while((count=read(fds[0],buff,60))>0){
           for(i=0;i<count;i++){
               write(1,buff+i,1);
               write(1," ",1);
           }
           printf("\n");
       }
       exit(0);
    }
   else{
      close(fds[0]);
      close(fds[1]);
      wait(0);
      wait(0);
   }
return 0;
}
