// LOG710 Hiver 2019 - Semaine 03 - Exemple 3
// compiler : gcc exe03.3.c -o exe03.3
// executer : ./exe03.3


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 25
#define READ_END	0
#define WRITE_END	1

int main(void)
{
	char write_msg[BUFFER_SIZE] = "Bonjour!";
	char read_msg[BUFFER_SIZE];
	pid_t pid;
	int fd[2];

	/** Creation d'un tube (pipe) temporaire */
	if (pipe(fd) == -1) {
		fprintf(stderr,"Creation du tube echouee");
		return 1;
	}

	/** Creation d'un noureau processus */
	pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Creation du processus fils echouee!");
		return 1;
	}

	if (pid > 0) {  /* Processus pere */
		/* Fermer le descripteur de lecture du tube non utilisee */
		close(fd[READ_END]);

		/* Ecrire sur le tube */
		write(fd[WRITE_END], write_msg, strlen(write_msg)+1);

		/* Fermeture le descripteur d'ecriture du tube (donc le tube sera supprime) */
		close(fd[WRITE_END]);
	}
	else { /* Processus fils */
		/* Fermeture du descripteur d'ecriture non utilise du tube  */
		close(fd[WRITE_END]);

		/* Lire dans le tube */
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		printf("Processus fils a lu :  %s\n",read_msg);

		/* Fermeture du descripteur de lecture du tube */
		close(fd[READ_END]);
	}

	return 0;
}
