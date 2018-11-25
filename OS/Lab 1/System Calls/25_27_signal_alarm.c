#include <stdio.h>
#include <sys/signal.h>

#define  EVER  ;;

void main();
int times_up();

void main()
{
	signal (SIGALRM, times_up);         /* go to the times_up function  */
		                                /* when the alarm goes off.     */
	alarm (10);                         /* set the alarm for 10 seconds */

	for (EVER)                          /* endless loop.                */
   ;                                /* hope the alarm works.        */
}

int times_up(sig)
int sig;                               /* value of signal              */
{
	printf("Caught signal #< %d >n", sig);
	printf("Time's up!  I'm outta here!!\n");
	exit(sig);                          /* return the signal number     */
}
