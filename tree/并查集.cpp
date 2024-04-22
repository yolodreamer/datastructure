#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int f[100005];
int n,m,p,x,y,fx,fy;

int find(int x)
{
	if(f[x]==x)
	{
		return x;
	}
	else
	{
		return f[x]=find(f[x]);
	}
}

int main()
{
	scanf("%d %d %d",&n,&m,&p);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		fx=find(x);
		fy=find(y);
		f[fx]=fy;
	}
	for(int i=1;i<=p;i++)
	{
		scanf("%d %d",&x,&y);
		fx=find(x);
		fy=find(y);
		if(fx==fy)
		{
			printf("Yes\n");	
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
 } 
