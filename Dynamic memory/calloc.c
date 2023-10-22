//calloc开辟内存空间会初始化为0
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<stdio.h>
int main()
{
    int *p=(int*)calloc(10,sizeof(int));
    if (p == NULL)
    {
        printf("%s\n",strerror(errno));
        return 1;
    }
     int i=0;
     for ( i = 0; i < 10; i++)
     {
        printf("%d",*(i+p));
     }
     free(p);
     p = NULL;
     return 0;
}