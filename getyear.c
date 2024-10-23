#include "types.h"
#include "stat.h"
#include "user.h"
int main(void){
	printf(1,"My system call returns the year%d\n",getyear());
	exit();
}
