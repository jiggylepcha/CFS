#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

void main(){
	struct timeval start,stop;
	gettimeofday(&start,NULL);
	long int pid=fork();
	long int p,i;
	printf("Process PID : %ld\n",pid);
	if(pid!=0){
        	syscall(323,pid,100);
	}
	if(pid==0){
		i=500000;
		while(i>=0){
			p=p*i*i;
			i--;
		}
		gettimeofday(&stop,NULL);
		printf("Time elapsed %lu PID %ld \n",stop.tv_usec-start.tv_usec,getpid());
	}
	else{
		i=500000;
		while(i>=0){
			p=p*i*i;
			i--;
		}
		gettimeofday(&stop,NULL);
		printf("Time elapsed %lu PID %ld \n",stop.tv_usec-start.tv_usec,getpid());
		wait(pid);
	}
	printf("Done for process %ld",getpid());
}
