#include"csapp.h"

unsigned int snooze(unsigned int secs){
	unsigned int x = sleep(secs);
	//sleep return the rest time,if return abnormal ,can be not one
	printf("you end the sleep\n");
	printf("Slept for %d of %d secs\n",secs-x,secs);
	return x;
}
//直接退出，从中断的地方继续运行
void end_sleep(int sig)
{
    return ;
}

int main(int argc,char* argv[])
{
    if(argc<2)
    {
        printf("error : usage -- snooze2    number]\n");
        return 0;
    }
    //重写信号处理函数
    if(signal(SIGINT,end_sleep) ==SIG_ERR)
    {
       printf("error\n");
       return 0;
    }
    //运行
    unsigned int x =(unsigned int )(*argv[1] - '0');
    printf("%d\n",x);
    snooze(x);
    return 0;
}