// LOG710 Hiver 2019 - Semaine 03 - Exemple 5
// compiler : gcc exe03.5l.c -o exe03.5l
//            gcc exe03.5r.c -o exe03.5r
// executer (les deux programmes dans le background): ./exe03.5r & ./exe03.5l &

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd,n;
    char message[100];

	// Le tube nomm� montube est un fichier special, il doit exister dans le systeme de fichiers
	// ouverture du tube montube en mode lecture comme n'importe quel fichier ordinaire.
        fd = open("montube", O_RDONLY);

    printf("Ici processus lecteur[%d] \n",getpid());

        if (fd!=-1)
        { // r�cup�rer un message du tube, taille maximale est 100.
       	while ((n = read(fd,message,100))>0)
                   // n est le nombre de caract�res lus
                    printf("%s\n", message);
        }

        else  // Dans ce cas le tube nomm� n'existe pas
              // il faut le cr�e avec la commande : mkfifo montube
		    printf( "d�sol�, le tube n'est pas disponible\n");

        close(fd);
	return 0;
}
