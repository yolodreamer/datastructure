#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//����ṹ 
typedef struct EdgeNode
{
	char adj;//�ڽ�� 
	struct EdgeNode* next;
}Edge;

//�������� 
typedef struct VertexNode
{
	char data;
	 struct EdgeNode* first;
}Vertex;
int find(char x)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i].data==x)
		{
			return i;
		}
	}
}
Vertex a[105];
int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		gechar();
		scanf("%c",&a[i].data);
		a[i].first=NULL;//��ʼ��Ϊ�� 
	}	
	//��ʼ����
	char x,y;
	int w;
	for(int i=1;i<=m;i++)
	{
		getchar();
		scanf("%c %c %d",&x,&y,&w);
		
		Edge* s=(Edge*)malloc(sizeof(Edge));
		s->adj=y;
		xi=find(x);
		s->next=a[xi].first;
		a[xi].first=s;
		
		Edge* s=(Edge*)malloc(sizeof(Edge));
		s->adj=x;
		yi=find(y);
		s->next=a[yi].first;
		a[yi].first=s;
	 } 
	return 0;
}
