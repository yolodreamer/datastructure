#include <stdlib.h>
#include <stdio.h>
# include <string.h>

typedef struct
{
	int w;//权值
	int f;//父亲节点的下标
	int l,r;//左右孩子节点的下标 
}huffmannode,*huffmantree; 

void find(huffmantree t,int x,int* w1,int* w2)
{
	//先找最小
	int minn=0;
	for(int i=1;i<=x;i++)
	{
		if(t[i].f==i)
		{
			minn=i;
			break;
		}
	} 
	for(int i=1;i<=x;i++)
	{
		if(t[i].f ==i)
		{
			if(t[i].w<t[minn].w)
			{
				minn=i;
			}
		}
	}
	*w1=minn;//最小的根节点的下标保存至W1中
	//找第二小 
	 for(int i=1;i<=x;i++)
	{
		if(t[i].f==i&&i!=(*w1))
		{
			minn=i;
			break;
		}
	} 
	for(int i=1;i<=x;i++)
	{
		if(t[i].f==i&&i!=(*w1))
		{
			if(t[i].w<t[minn].w)
			{
				minn=i;
			}
		}
	}
	*w2=minn;

}

huffmantree inithuffmantree(int *wi,int n)
{
	int m=2*n;
	huffmantree t=(huffmannode*)malloc(sizeof(huffmannode)*m);
	for(int i=1;i<=n;i++)
	{
		t[i].f=t[i].l =t[i].r=0;
		t[i].w=0;
	}
	int w1,w2;
	for(int i=n+1;i<m;i++)
	{
		find(t,i-1,&w1,&w2);
		t[w1].f=t[w2].f=i;
		t[i].f=i;
		t[i].w=t[w1].w+t[w2].w;
		t[i].l=w1;
		t[i].r=w2;
	}
	return t;
}

char** ctreateHuffmanCode(huffmantree t,int n)
{
	char *temp=(char*)malloc(sizeof(char)*n);//0~~n-1
	char **code=(char**)malloc(sizeof(char*)*n);
	int start;//一开始放编码的位置 
	int pos,p;
	for(int i=1;i<=n;i++)
	{
		start=n-1;
		temp[start]='\0';
		pos=i;
		p=t[pos].f;//p是pos的父亲 
		while(t[pos].f!=pos)
		{
			start--;
			if(t[p].l==pos)
			{
				temp[start]='0';
			}else{
				temp[start]='1';
			}
			pos=p;
			p=t[pos].f;	
		}
		code[i-1]=(char*)malloc(sizeof(char)*(n-start));
		strcpy(code[i-1],&temp[start]);
		
	}
	free(temp);
	temp=NULL;
	return code;
} 
int main()
{
	char s[8] = {'A', 'B', 'C', 'D','E', 'F', 'G', 'H'};
	int w[8] = {5, 29, 7, 8,14, 23, 3, 11};
	huffmannode* tree=inithuffmantree(w,8);
	char **code= ctreateHuffmanCode(tree,8); 
	for(int i=0;i<8;i++)
    {
    	printf("%c : %s\n",s[i],code[i]);
	}
	return 0;
 } 
