#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define READ 0
#define WRITE 1

main ()
{
	int namedpipe;
	int in, out;

	mknod("/tmp/prob", S_IFIFO | 0666, 0);

	namedpipe = open("/tmp/prob", O_RDWR);
	if (namedpipe == -1)
	{
		perror("!!!Hiba a nyitasban");
		exit(2);
	}
	printf(" Az ELSO megnyitva\n");
}