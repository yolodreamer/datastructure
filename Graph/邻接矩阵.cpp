#include<stdio.h>


int a[105][105];
int d[105];

int n,m;

int main()
{
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)a[i][j]=0;
			else a[i][j]=INF;
		}
		
	}
	int x,y,w;
	for(int i=1;i<=m;i++)
	{
		sanf("%d %d %d",&x,&y,&w);
		d[x][y]=a[y][x]=w;
	}
	retrun 0;
 } 
