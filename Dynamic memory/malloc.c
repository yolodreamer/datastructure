#include<stdio.h>
#include<string.h>//strerror头文件
#include<stdlib.h>//malloc头文件名称
#include<errno.h>//erron头文件
int main()
{
    int* p = (int*)malloc(40);//动态内存的开辟
    if (p == NULL)//内存开辟失败，检查一点要有
    {
        printf("%s\n", strerror(errno));
        return 1;
    }
    int i = 0;
    for (i=0; i<10; i++)
    {
        *(p + i) = i;
    }
    for (i=0; i<10;i++)
    {
        printf("%d/n", *(p + i));
    }
    return 0;

}