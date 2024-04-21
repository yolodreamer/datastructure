#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct BSTnode
{
	int data;
	struct BSTnode* left;
	struct BSTnode* right;
}BSTNode,*BSTtree;

BSTtree initBST(int x)
{
	BSTNode* c=(BSTNode*)malloc(sizeof(BSTNode));
	if(c==NULL)
	{
		printf("�ڴ濪��ʧ��");
		return NULL;
	}
	c->data=x;
	c->left=c->right=NULL;
	return c;
}

BSTtree insert(BSTNode* w,int x)
{
	BSTNode* s=(BSTNode*)malloc(sizeof(BSTNode));//�����ڵ㣻���������� 
	s->data=x;
	s->left=s->right=NULL;
	BSTNode* pre=NULL;
	BSTNode* p=w;
	while(p!=NULL)
	{
		if(p->data>x)
		{
			pre=p;
			p=p->left;
		}
		else
		{
			pre=p;
			p=p->right;
		}
	}
	//��������ǲ��뺯������while�� 
		if(pre->data>x)
		{
			pre->left=s;
		}
		else 
		{
			pre->right=s;
		}
	
	return w;
}

void inorder(BSTNode* w)
{
	if(w==NULL)
	{
		return;
	 } 
	 if(w->left!=NULL)
	 {
	 	inorder(w->left);
	 }
	 
	 printf("%d ",w->data);
	 
	 if(w->right!=NULL)
	 {
	 	inorder(w->right);
	 }
}

BSTtree find(BSTNode* w)//�������Ҫ�������� 
{
	BSTNode* z=w;
	while(z->right!=NULL)
	{
		z=z->right; 
	}
	return z;
}
BSTtree delet(BSTNode* w,int x)
{
	BSTNode* z=w;
	if(z->data>x)
	{
		z->left=delet(z->left,x);
	 } 
	 else if(z->data<x)
	 {
	 	z->right=delet(z->right,x);
	 }
	 else
	 {
	 	
	 	if(z->left!=NULL&&z->right->right!=NULL)
	 	{
	 		BSTNode* c=find(w->left);
	 		z->data=c->data;//�����ݽ��в������ǽڵ� 
	 		z->left=delet(z->left,c->data);
		}
		else
		{
			BSTNode* h=NULL;//�½�һ���ڵ���������һ���ڵ� 
			if(z->left!=NULL)
			{
				h=z->left;
			}
			else 
			{
				h=z->right;
			}
			free(z);
			 z=NULL;
			 return h; 
		}
	 }
	 return z;
	 
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[105];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	BSTNode* w=NULL;
	w=initBST(a[1]);
	if(w==NULL)
	{
		printf("����ʧ��\n");
		return 0;	
	}
	
	for(int i=2;i<=n;i++)
	{
		w=insert(w,a[i]);
	}
	
	inorder(w);
	printf("\n");
	w=delet(w,10);
	printf("\n");
	inorder(w);
	return 0;
}
/*
9 
8 3 10 1 6 14 4 7 13 
*/
