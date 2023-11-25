#include "csapp.h"

int main()
{
    pid_t  pid;
    if((pid  = fork())== 0)
    {
        printf("this a child\n");
        pause();
        printf("control should never reach here! \n");
        exit(0);
    }
    //向子进程发送一个终止
    printf("输入1结束子进程\n");
    int x;
    scanf("%d",&x);
    if(x == 1)
       kill(pid,SIGKILL);  //4秒后结束子进程
    exit(0);
}