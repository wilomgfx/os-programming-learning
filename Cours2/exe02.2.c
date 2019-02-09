// LOG710 Hiver 2015 - Semaine 02 - Exemple 2
// compiler : gcc exe02.2.c -o exe02.2
// executer : ./exe02.2

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main ()
{ 	char* arg[] = {"/bin/ps", "f", NULL};
	printf("Bonjour..\n");
	execvp("/bin/ps", arg);
	printf("Echec de execvp\n");
	printf("Erreur %s\n",strerror(errno));
    return 0;
}
