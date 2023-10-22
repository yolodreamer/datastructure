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

    int* ptr =realloc(p,9000);

    if (ptr != NULL)
    {
        p=ptr;
    }
    for(i=0;i<10;i++)
    {
        printf("%d\n",*(p+i));
    }
    free(p);
    p= NULL;

    return 0;
}
