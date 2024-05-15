#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ArcBox
{
	int tailvex,headvex;
	struct Arcbox* hlink,tlink;
	int weight;
}ArcBox;

typedef struct VexNode
{
	int data;
	ArcBox* firstin;
	ArcBox* firstout;
}Vertex;

Vertex v[105];
int n,m;


int main()
{
	scanf("%d %d ",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&v[i].data);
		v[i].firstin=v[i].firstout=NULL;
	}	
	int x,y,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d ",&x,&y,&w);
		ArcBox *z=(ArcBox*)malloc(sizeof(ArcBox));
		z->tailvex=x;
		z->headvex=y;
		z->weight=w;
		
		z->hlink=v[x].firstout;
		v[x].firstout=z;
		
		z->hlink=v[y].firstout;
		v[y].firstout=z;
	}
	return 0;
 } 
