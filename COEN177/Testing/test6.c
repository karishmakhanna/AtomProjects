#include <pthread.h>
 #include <stdio.h>
 int value = 0;
 void *runner(void *param);

 int main(){
     int pid;
     pthread_t tid;
     pthread_attr_t attr;
     pid = fork();
     if (pid == 0) {
         pthread_attr_init(&attr);
         pthread_create (&tid,&attr, runner,NULL);
         pthread_join(tid, NULL);
         printf(" %d\n", value);
    }
    else {
        wait(NULL);
    }
}
 void *runner(void *param) {
 value ++;
 pthread_exit(0) ;
}
