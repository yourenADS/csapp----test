#include"csapp.h"

void sign_print(int sig)
{
    printf("接收信号\n");
    exit(0);
}

int main()
{
    //设置信号处理函数
    if(signal(SIGINT,sign_print) == SIG_ERR)
        {
            printf("error");
            return 0;
        }
    //等待接受信号
    pause();

    return 0;
}