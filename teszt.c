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

}