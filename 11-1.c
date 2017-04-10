#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

int main()
{
        int fd, ret;
        char buf[32];

        buf[0]=0;




        fd=open("fs/fifo",O_RDWR);      // megnyitom a fifot amit az iment hoztam letre
        if (fd == -1) {
            perror("open() hiba!");
            exit(-1);
        }
        ret=read(fd,buf,32);
printf("olvastam %s",buf); // olvasok belole ugyanazt, ret: mennyit sikerult olvasni
        strcpy(buf,"beleirtam most valamit\0");
        int pid;
        printf("Add meg a pid-et ");
        scanf("%d",&pid);
        kill(pid, SIGALRM);

        write(fd,buf,strlen(buf)); // irok bele valamit, hogy ne legyen ures
        close(fd);
        return 0;
        }

