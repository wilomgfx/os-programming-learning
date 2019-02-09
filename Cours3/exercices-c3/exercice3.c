#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include <signal.h>
#define N 5
/*0*/
void action(int signum) {
	printf("capture de SIGCONT %d\n", getpid());
}
int main( )
{ pid_t pid[N];
  int i ;
  /*1*/ signal(SIGCONT,action);
  for ( i=0; i<N;i++)
   if ((pid[i]=fork())==0)
    { /*2*/ pause() ;
      while(1) {
        printf("ici fils %d de pid %d \n", i, getpid());
        pause(); 
      }
    }
  /*3*/
  while (1)
    for(i=0; i<N;i++)
      { kill(pid[i], SIGCONT); sleep(1); kill(pid[i], SIGSTOP); }
}
