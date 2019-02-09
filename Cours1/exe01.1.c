
// LOG 710 - Semaine 01 - Exemple 01
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

void gestionnaire_timer (int signum)
{
  static int count = 0;
  printf ("timer a expire %d fois\n", ++count);
}

int main ()
{
  struct sigaction sa;
  struct itimerval timer;

  /* Instale le gestionnaire du signal  SIGVTALRM.  */
  memset (&sa, 0, sizeof (sa));
  sa.sa_handler = &gestionnaire_timer;
  sigaction (SIGVTALRM, &sa, NULL);

  /* Configurer le timer pour expirer apres 250 msec  */
  timer.it_value.tv_sec = 0;
  timer.it_value.tv_usec = 250000;
  /* ... et a chaque 250 msec apres.  */
  timer.it_interval.tv_sec = 0;
  timer.it_interval.tv_usec = 250000;
  /* Demarrer le timer. .  */
  setitimer (ITIMER_VIRTUAL, &timer, NULL);

  /* Simule un certain calcul ...  */
  while (1);
}
