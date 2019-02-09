// LOG710 Hiver 2015 - Semaine 02 - Exemple 4
// compiler : gcc exe02.4.c -o exe02.4
// executer : ./exe02.4
// Avec cette version : les processus crees affichent comme pid de leur pere 1. Pourquoi ?

#include <sys/types.h>   	// pour le type pid_t
#include <unistd.h>	// pour fork
#include <stdio.h>	// pour  printf
int main ( )
{	pid_t p;
	int i, n=5;
        printf("Processus pere : %d\n", getpid());
	for (i=1; i<n; i++)
	{  	p = fork();
		if (p > 0 )
		  break;
		sleep(1);
 		printf(" Processus %d  de pere %d. \n", getpid(), getppid());
	}


	return 0;
}
