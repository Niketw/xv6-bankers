#include "types.h"
#include "user.h"
#include "stat.h"
int main(){

	int pid=fork();
	if(pid==0){

		printf(1,"\nIn child process");
		exit();
	}
	else{
		wait();
		printf(1,"\nIn parent process %d\n",pid);
		
	}
	exit();
	return 0;

}
