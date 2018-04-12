#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<sys/syscall.h>
void main(){
	int a=syscall(323,100000000,10);
	perror("Unable");
	int b=syscall(323,2,-1);
	perror("Unable");
	int c=syscall(323,-4,6);
	perror("Unable");
}
