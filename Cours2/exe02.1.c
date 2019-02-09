// LOG710 Hiver 2015 - Semaine 02 - Exemple 1
// compiler : gcc exe02.1.c -o exe02.1
// executer : ./exe02.1


#include <sys/types.h>   // pour le type pid_t
#include <unistd.h>		// pour fork
#include <stdio.h>		// pour perror, printf

int a=20;


int main ()
{
	pid_t pid;

switch (pid = fork())
	{
	case -1:
	    /* ici pid est -1, the fork echouee */
	    /* raisons possibles: manque d’espace memoire ou le */
		/* ou nombre maximal de creations autorisees est atteint */
	    perror("L'operation fork() a echouee!");
	    break;

	case 0:// seul le processus fils execute  ce  "case"
	    /* pid zero est le fils */
	    printf("ici le processus fils %d, le PID de mon pere est %d. \n",getpid(),getppid());
	    a+=10;
	    break;

	default:// seul le processus pere execute cette instruction
	    /* pid plus grand que zero est le parent prenant le pid du fils */
	    printf("ici processus pere %d, le PID de mon fils est %d. \n",getpid(), pid);
	    a+=100;
	}
	// les deux processus executent ce qui suit
	printf("Fin du Process %d. avec a = %d\n", getpid(),a );
	return 0;
}
