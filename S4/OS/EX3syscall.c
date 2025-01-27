#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
void main()
{
	int status,pid,child_pid;
	pid=fork();
	if(pid==-1)
	{
		printf("child process ceration failed");
		exit(0);
	}
	else if(pid==0)
	{
		printf("inside child process with parent id%d\n",getpid());
		execlp("/bin/date","date",NULL);
		exit(0);
	}
	else
	{
		child_pid=wait(&status);
		printf("inside parent process with id%d\n",getpid());
		printf("child proces created successfully\n");
	}
}

