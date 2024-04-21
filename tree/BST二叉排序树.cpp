#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct BTSnode
{
	int data;
	struct BTSnode* left;
	struct BTSnode* right;
}BSTNode,*bstnode;

bstnode initbst(int x)
{
	BSTNode* w=(BSTNode*)malloc(sizeof(BSTNode));
	if(w==NULL)
	{
		printf("内存开辟失败/n");
	}
		w->data=x;
		w->left=w->right=NULL;
		return w;
}

//不需要用查找函数 

bstnode insert(BSTNode* c,int x)//需要返回值 
{
	BSTNode* z=(BSTNode*)malloc(sizeof(BSTNode));
	z->data=x;
	z->left=z->right=NULL;//给左右孩子赋空 
	BSTNode* pre=NULL;
	BSTNode* h=c;//这个赋值不能放在循环里不然会导致一直循环根节点 
	while(h!=NULL)
	{
		if(x<h->data)
		{
			pre=h;
			h=h->left;
		}
		else 
		{
			pre=h;
			h=h->right;
		}
	}
	if(x<pre->data)
	{
		pre->left=z;
	}
	else
	{
		pre->right=z;
	}
	return c;//注意返回树 
}
 
bstnode insert_d(BSTNode* c,int x)//递归版 
{
	if(c==NULL)//若节点为空则数据则需插入在这 
	{
		BSTNode* h=(BSTNode*)malloc(sizeof(BSTNode));;
		h->data=x;
		h->left=h->right=NULL;
		return h;
	}
	if(c->data>x)
	{
		c->left=insert_d(c->left,x);
		return c;
	}
	if(c->data<x)
	{
		c->right=insert_d(c->right,x);
		return c;
	}
}
void inorder(BSTNode* c)
{
	if(c==NULL)
	{
		return;
	}
	if(c->left!=NULL)
	{
		inorder(c->left);
	}
	printf("%d ",c->data);
	if(c->right!=NULL)
	{
		inorder(c->right);
	}
}
void Search(BSTNode* c,int x)
{
	BSTNode* z=c;//需要创建一个新节点 
	while(z!=NULL&&z->data!=x)
	{
		if(z->data>x)
		{
			z=z->left;
		}
		if(z->data<x)
		{
			z=z->right;
		}
		if(z==NULL)
		{
			printf("NO\n");
			
		}
		else
		{
			printf("yes\n");
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[105] ;//创建一个数组来存 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	BSTNode* c=NULL;
	c=initbst(a[1]);
	
	if(c==NULL)
	{
		printf("建树失败/n");
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		c=insert(c,a[i]);//插入函数有返回值需要传给原的树 
	}
		
	inorder(c);
	printf("\n");
	
//	Search(c,3);
	return 0;
}
 
