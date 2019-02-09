
// LOG710 Hiver 2019 - Semaine 03 - Exemple 4
// Exemple  manipulation d'un tube (pipe) temporaire (non nomm�s)
// compiler : gcc exe03.4.c -o exe03.4
// executer : ./exe03.4 ls   wc

#include <unistd.h> //pour fork, close
#include <stdio.h>

#define R 0
#define W 1

int main (int argc, char * argv [ ] )
{
   int fd[2] ;

   pipe(fd) ; // creation d'un tube sans nom

   char message[100] ; // pour r�cup�rer un message


   int nboctets ;
   char * phrase = " message envoy� au pere par le fils";

   if (fork() !=0)  // Processus pere
   {
     close(fd[R]) ; // Le p�re ferme le descripteur non utilis� de lecture
     dup2(fd[W], 1) ; // copie fd[W] dans le descripteur 1 ; sortie standard)
     close (fd[W]) ; // fermeture du descripteur d'�criture
                     // A ce niveau : la sortie standard (STDOUT : 1) du processus pere est redirig�e vers l'entr�e du tube

     if(execlp(argv[1], argv[1], NULL) ==-1); // charg� l'image binaire du programme �crivain (par exemple ls ) et l'executer
        perror("error dans execlp") ;
   }

   else // processus fils (lecteur)
   { // fermeture du descripteur non utilis� d'�criture
      close(fd[W]) ;
      // copie fd[R] dans le descripteur 0 : entr�e standard)
      dup2(fd[R],0) ;
      close (fd[R]) ; // fermeture du descripteur de lecture
                      // A ce niveau : l'entree standard (STDIN : 1) du processus fils est redirig�e vers la sortie du tube
      // ex�cute le programme lecteur

      execlp(argv[2], argv[2], NULL) ;  // charg� l'image binaire du programme �crivain (wc ) et l'executer

      perror("connect") ;
    }
    return 0
;
}