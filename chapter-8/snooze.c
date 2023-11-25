#include"csapp.h"


unsigned int snooze(unsigned int secs){
	unsigned int x = sleep(secs);
	//sleep return the rest time,if return abnormal ,can be not one
	
	printf("Slept for %d of %d secs\n",secs-x,secs);
	return x;
}





int main()
{
	unsigned int x;
	scanf("%d",&x);
	snooze(x);
	return 0;
}
