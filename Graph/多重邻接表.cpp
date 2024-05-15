#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ArcBox
{
	int vi,vj,wi;
	struct ArcBox* inext;
	struct ArcBox* jnext;
}Edge;

typedef struct 
{
	int data;
	Edge* first;
}Vertex;

Vertex v[105];
int n,m;

int main()
{
	scanf("%d %d",&n,&m);
	fffor(int i=1;i<=n;i++)
	{
		scanf("%d",&v[i].data);
		v[i].first=NULL;
	}
	
	int x,y,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&x,&y,&w);
		Edge* z=(Edge*)malloc(sizeof(Edge));
		z->vi=x;
		z->vj=y;
		z->wi=w;
		 
		z->inext=v[x].first;
		v[x].first=z;
		
		z->inext=v[y].first;
		v[y].first=z;
	}
	return 0;
	
} 
