// LOG710 Hiver 2019 - Semaine 03 - Exercice 2
// compiler : gcc exercice2.c -o exercice2
// executer : ./exercice2
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include <signal.h>
void handler(int sig){
	int x;
	if (sig == SIGCHLD) {
	   x = wait(NULL);
	   printf("Processus pere %d. Processus  fils %d viens de terminer. \n", getpid(), x);
	   exit(0);
	
	}
}
int main(int argc, char *argv[]) { /*1*/
    int i;
	
	signal(SIGCHLD, handler);
	if (!fork())
	{ /*2*/
	    printf("Je suis le processus fils 1. Mon pid est : %d\n",getpid());
		for (i = 0 ; i <10 ; i++) ;
		//simule un certain calcul /*3*/
		exit(1) ; /*4*/
	}
	/*5*/
	
	while(1) ;
	  
}