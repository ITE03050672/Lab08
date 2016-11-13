#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	int pid,i,p_id,s_id;
	int status = 0;
	for(i=0;i<3;i++)
	{
		pid=fork();
		if (pid ! = 0) {
			/* parent */
			printf("I am the parent process, my son process id is %d\n",pid);
			pid = wait(&status);
			
		} 
		else {
			/* child */
			p_id = getppid();
			s_id = getpid();
			printf("I am the child process, my process id is %d , my parent process id is %d\n",s_id,p_id);
			exit(status);
		}
	}
	return 0;
}
