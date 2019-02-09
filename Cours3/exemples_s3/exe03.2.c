// LOG710 Hiver 2019 - Semaine 03 - Exemple 2
// compiler : gcc exe03.2.c -o exe03.2
// executer : ./exe03.2
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
static void action(int sig)
{
	switch (sig)
	{
		case SIGUSR1: printf("Signal SIGUSR1 recu\n");
				break;
		case SIGUSR2: printf("Signal SIGUSR2 recu\n");
				break;
		default:	break;
	}
}
int main()
{
	struct sigaction new_action, old_action;
	new_action.sa_handler = action;
	sigemptyset (&new_action.sa_mask);
  	new_action.sa_flags = 0;

	int i, pid, etat;
	// Specification de l'action du signal

	if( sigaction(SIGUSR1, &new_action,NULL) <0)
		printf("Erreur de traitement du code de l'action\n");

	if( sigaction(SIGUSR2, &new_action,NULL) <0)
		printf("Erreur de traitement du code de l'action\n");

	if((pid = fork()) == 0){
		sleep(1);// Mise en attente d'un signal
		kill(getppid(), SIGUSR1); // Envoyer signal au parent.
	    while(1);
	}
	else {
		kill(pid, SIGUSR2); // Envoyer un signal � l'enfant
		pause();
		printf("Parent : terminaison du fils\n");
		kill(pid, SIGTERM); // Signal de terminaison � l'enfant
		wait(&etat); // attendre la fin de l'enfant
		printf("Parent : fils termine\n");
		}
}
