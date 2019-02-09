// LOG710 Hiver 2019 - Semaine 03 - Exercice 1
// compiler : gcc exercice1.c -o exercice1
// executer : ./exercice1
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int count = 0;
static void action(int sig)
{	++count ;
	write(1,"capture du signal SIGINT\n", 26) ;
}
int main()
{	// Specification de l'action du signal
	signal (SIGINT, action);
	printf("Debut:\n");
	do 	{
		   sleep(1);
		} while (count <3);
	return 0;
}

