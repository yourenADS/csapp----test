// 解决信号不会排队的问题
#include"csapp.h"
void handler(int sig)
{
    //缓存错误数值，使得在处理程序运行期间不会出出现errno的变动
    //保护程序稳定
    int olderrno = errno;

    printf("you call the signal procress \n");
    while((waitpid(-1,NULL,0))>0)
    {
        printf("Handler reaped child\n");
    }
    //还没有完全回收完全
    if(errno != ECHILD)
        printf("error waitpid\n");
    sleep(1);
    errno = olderrno;
}

int main()
{
    int i,n;
    char buf[MAXBUF];

    //设置信号处理函数
    if(signal(SIGCHLD, handler)==SIG_ERR)
       printf("error");
    
    //创建三个进程
    for(i = 0;i<3;i++)
    {
        if(fork()==0)
        {
            //输出pid
            printf("this is %d chile\n",(int)getpid());
            exit(0);
        }
    }

    //从忠端读入

    if((n = read(STDIN_FILENO,buf,sizeof(buf)))<0)
       printf("error");
    
    
    printf("parent processing input\n");
    while(1)
      ; 
      exit(0); 
}