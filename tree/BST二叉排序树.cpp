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
		printf("�ڴ濪��ʧ��/n");
	}
		w->data=x;
		w->left=w->right=NULL;
		return w;
}

//����Ҫ�ò��Һ��� 

bstnode insert(BSTNode* c,int x)//��Ҫ����ֵ 
{
	BSTNode* z=(BSTNode*)malloc(sizeof(BSTNode));
	z->data=x;
	z->left=z->right=NULL;//�����Һ��Ӹ��� 
	BSTNode* pre=NULL;
	BSTNode* h=c;//�����ֵ���ܷ���ѭ���ﲻȻ�ᵼ��һֱѭ�����ڵ� 
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
	return c;//ע�ⷵ���� 
}
 
bstnode insert_d(BSTNode* c,int x)//�ݹ�� 
{
	if(c==NULL)//���ڵ�Ϊ������������������� 
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
	BSTNode* z=c;//��Ҫ����һ���½ڵ� 
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
	int a[105] ;//����һ���������� 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	BSTNode* c=NULL;
	c=initbst(a[1]);
	
	if(c==NULL)
	{
		printf("����ʧ��/n");
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		c=insert(c,a[i]);//���뺯���з���ֵ��Ҫ����ԭ���� 
	}
		
	inorder(c);
	printf("\n");
	
//	Search(c,3);
	return 0;
}
 
