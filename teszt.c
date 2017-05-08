#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd, ret, pid;
	char buf[32];

	buf[0]=0;

	//Ha gikxer van akkor torli a benntmaradt fifot
	unlink("sajat");
	//ha kesz ezt torold ki!

	ret=mkfifo("sajat", 00666);
	if (ret == -1) {
		perror("Fifo create failed!");
		exit(-1);
	}

	fd=open("sajat", O_RDWR);
	if (fd == -1) {
		perror("Own fifo open is failed!");
		exit(-1);
	}

	strcpy(buf,"ez egy teszt program\0");
	printf("Beleirok a fifob: %s:%lu\n",buf,strlen(buf));
	write(fd,buf,strlen(buf));

	sleep(5);

	strcpy(buf,"ez meg mindig teszt program\0");
	printf("Beleirok a fifob: %s:%lu\n",buf,strlen(buf));
	write(fd,buf,strlen(buf));

	sleep(5);

	close(fd);
	unlink("sajat");
}
