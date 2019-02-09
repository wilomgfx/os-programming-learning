// LOG710 Hiver 2019 - Semaine 03 - Exemple 5
// compiler : gcc exe03.5l.c -o exe03.5l
//            gcc exe03.5r.c -o exe03.5r
// executer (les deux programmes dans le background): ./exe03.5r & ./exe03.5l &


#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	    int fd;
        char message[100];
        sprintf(message, "bonjour du writer [%d]", getpid());

	    // Le tube nomm� montube est un fichier special, il doit exister dans le systeme de fichiers
	    //Ouverture du tube  montube en mode �criture
        fd = open("montube", O_WRONLY);
        printf("ici writer[%d] \n", getpid());

        if (fd!=-1)
        {   	// D�pot d�un message sur le tube
     		write(fd, message, strlen(message)+1);
        }

        else
             // Dans ce cas le tube nomm� n'existe pas
              // il faut le cr�e avec la commande : mkfifo montube
		     printf( " d�sol�, le tube n'est pas disponible \n");

	    close(fd);
	    return 0;
}
