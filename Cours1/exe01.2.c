
// LOG 710 - Semaine 01 - Exemple 02
#include <linux/kernel.h>
#include <stdio.h>
#include <sys/sysinfo.h>

int main ()
{
  /* Quelques constantes.  */
  const long minute = 60;
  const long hour = minute * 60;
  const long day = hour * 24;
  const double megabyte = 1024 * 1024;
  /* Obtenir les statistiques du systeme en utilisant l'appel systeme sysinfo.  */
  struct sysinfo si;
  sysinfo (&si);
  /* Sommaire de quelques valeurs interessantes.  */
  printf ("Le systeme tourne pour (uptime) : %ld jours %ld:%02ld:%02ld\n",
	  si.uptime / day, (si.uptime % day) / hour,
	  (si.uptime % hour) / minute, si.uptime % minute);
  printf ("Quantite totale de la RAM     : %5.1f MB\n", si.totalram / megabyte);
  printf ("Quantite libre de la  RAM      : %5.1f MB\n", si.freeram / megabyte);
  printf ("Nombre de processus  : %d\n", si.procs);

  return 0;
}
