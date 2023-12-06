#include<stdio.h>
void f(void);

// 两个定义均为强符号,会覆盖y 
int x = 15213;
int y = 15212;

int main()
{
    printf("x = %x y = %x \n", &x , &y);
    f();
    printf("x = %x y = %x \n", x , y);
    return 0;
}