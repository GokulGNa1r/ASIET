#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd,fd2;
	char wbuf[128];
	char rbuf[128];
	fd=open("dir.txt",O_RDWR);
	printf("enter the txt to the written:\n");
	scanf("%s",wbuf);
	write(fd,wbuf,strlen(wbuf));
	close(fd);
	fd2=open("dir.txt",O_RDWR);
	printf("\n the contents are:\n");
	read(fd2,rbuf,100);
	printf("%s \n",rbuf);
	close(fd2);
	return 0;
}
