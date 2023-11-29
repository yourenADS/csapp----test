#include "csapp.h"
int main()
{
    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
        printf("this is child\n");
        int x =0;
        //6秒之后退出
        alarm(6);
        while(1)
        {
            sleep(1);
            printf("%d\n",++x);
        }
        printf("end normal\n");
        exit(0);
    }
int status;
while(1){
    //要是子进程结束。返回
    if(pid = waitpid(-1 , &status,0)>0)
        printf("all end pid == %d \n",pid);
    return 0;
}
return 0;
}