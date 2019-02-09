// LOG710 Hiver 2019 - Semaine 03 - Exemple 1
// compiler : gcc exe03.1.c -o exe03.1
// executer : ./exe03.1

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
static void action(int sig)
{
	printf("On peut maintemant m'eliminer\n");
	signal(SIGTERM, SIG_DFL);
}

int main()
{
	if( signal(SIGTERM, SIG_IGN) == SIG_ERR)
		printf("Erreur de traitement du code de l'action\n");
	if( signal(SIGUSR2, action) == SIG_ERR)
		printf("Erreur de traitement du code de l'action\n");
	while (1)
		pause();
}

