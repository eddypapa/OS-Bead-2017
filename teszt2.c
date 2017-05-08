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
	int fd, ret;
	char buf[32];

	printf ("PID= %d\n",getpid());

	buf[0]=0;

	fd=open("sajat", O_RDWR);
	if (fd == -1) {
		perror("Own fifo open is failed!");
		exit(-1);
	}

	ret=read(fd,buf,32);
	printf("Kiolvastam a fifobol a kovetkezot: %s\n",buf);

	sleep(5);

	ret=read(fd,buf,32);
	printf("Kiolvastam a fifobol a kovetkezot: %s\n",buf);
	close(fd);
}
