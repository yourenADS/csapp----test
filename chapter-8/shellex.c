/*  simple  shell    */
#include"csapp.h"

#define MAXARGS    128


void evql(char *cmdline);
int parseline(char *buf,char **argv);
int builtin_command(char **argv);

int main()
{
    char cmdline[MAXARGS];

    while(1)
    {
        printf("> ");
        fgets(cmdline , MAXLINE,stdin);
        if(feof(stdin))
            exit(0);

        evql(cmdline);
    }
    return 0;
}
void evql(char* cmdline)
{
    char *argv[MAXARGS];
    char buf[MAXLINE];   //holds modified commandline
    // judge if run display
    pid_t pid;  //process id
    int bg ;

    strcpy(buf,cmdline);//记录命令行
    bg = parseline(buf,argv);//检查是否在前端显示的运行
    
    if(argv[0] == NULL) //没有文件名
    {
      return ;
    }
    if(!builtin_command(argv))
    {
      if((pid = fork()) == 0)//进程运行该程序
      {
            if(execve(argv[0], argv,environ)<0)
            { // 即运行失败
                  printf("%s : Command not found.\n",argv[0]); //输出文件名
                  exit(0);
            }
      }
      if(!bg)
      {
            int status;
            if(waitpid(pid,&status,0)<0)  //若回收进程失败
                  printf("error return ");
      }else
            printf("%d %s",pid,cmdline); //输出程序的进程号以及命令行
    }
    return ;
    //开一个子进程判断是否是

}

int builtin_command(char **argv)
{
      if(!strcmp(argv[0],"quit"))
            exit(0);//结束
      if(!strcmp(argv[0],"&")) //忽视
            return 1;
      return 0;
}


//将输入的字符串分割为一个个参数
int parseline(char *buf,char **argv)
{
      char *delim;
      int argc;
      int bg = 0;


      buf[strlen(buf)-1] = ' '; //将原本最后一位\n改为' '
      while((*buf) && (*buf == ' '))
      {
            buf++;
      }
      argc = 0;//返回参数的个数
      while((delim = strchr(buf,' ')))
      {
            argv[argc++] = buf;
            *delim = '\0';
            buf = delim +1;
            while(*buf && (*buf == ' '))
                  buf++;
      }
      //末尾是NULL
      argv[argc] =NULL;
      if(argc ==0)
       return 1;

       if(*argv[argc-1] == '&')
       {
            bg = 1;
            argv[--argc] = NULL;
       }

       return bg;

}
