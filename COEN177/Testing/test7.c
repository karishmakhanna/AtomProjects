#include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
 int main() {
     if (fork()) {
         wait(0);
     } else {
     printf("Hello \n");
     exit(0);
     printf(" Completed\n");
    }
    return 0;
}
