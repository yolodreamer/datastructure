#include<string.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
int main ()
{
    int *p=(int*)malloc(40);
    if(p== NULL)
    {
    printf("%s\n",strerror(errno));
    return 1;
    }

    int i=0;
    for (i=0;i<10;i++)
    {
        *(p+i)=i+1;
    }

    int* ptr =realloc(p,9000);//拓展空间

    if (ptr != NULL)//realloc有两种，一个是在原本的空间上拓展，还有一种是原来空间不够把原来数据移到新的空间并且开辟新的足够大的空间
    {
        p=ptr;
    }
    for(i=0;i<10;i++)//使用
    {
        printf("%d\n",*(p+i));
    }
    free(p);//借用内存归还
    p= NULL;

    return 0;
}
