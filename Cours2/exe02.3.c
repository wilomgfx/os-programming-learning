// LOG710 Hiver 2015 - Semaine 02 - Exemple 3
// compiler : gcc exe02.3.c -o exe02.3
// executer : ./exe02.3


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{

    pid_t  pid;

	/* Creer un processus fils avec fork */
	pid = fork();

	if (pid < 0) { /* En cas d'erreur  */
		fprintf(stderr, "Creation de processus avec fork echouee");
		exit(-1);
	}
	else if (pid == 0) { /* Processus fils  */
		execlp("/bin/ls", "ls", NULL);  // Charger l'image binaire du programme de la commande Unix/Linux ls
	}
	else { /* Processus pere */
		/* le processus pere va attendre que le processus fils complete */
		wait (NULL);

		printf ("Processus fils a complete");

		exit(0);
	}
}
