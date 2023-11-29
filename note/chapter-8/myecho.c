#include<stdio.h>
int main(int argc, char *argv[] , char *envp[])
{

	for(int i=0;i<argc;i++)
	{
		printf("argv[%d]: %s\n",i,argv[i]);
	}
	int j=0;
	while(envp[j]!=NULL)
	{
		printf("envp[%d]: %s\n",j,envp[j]);
		j++;
	}
	exit(0);
}
