#include<cstdio>
#include<string.h>
#include<stdlib.h>
#include<algorithm> 
#include<iostream>
using namespace std; 
typedef struct AVLNode
{
	int data;
	struct AVLNode* left;
	struct AVLNode* right;
	int h;//记录节点的高度 
}AVLnode,*AVLtree; 
 
AVLtree initAVL(int x)
 {
 	AVLnode* z=(AVLnode*)malloc(sizeof(AVLnode));
	 if(z==NULL)
	 {
	 	return NULL;
	 } 
	  z->data=x;
	  z->left=z->right=NULL;
	  z->h=1;
	  return z;
 }

 
int gethight(AVLtree w)//数值为int型 
 {
 	if(w==NULL)
 	{
 		return 0;
	 }
	 else
	 {
	 	return w->h;
	 }
 }
 
 AVLtree LL_rotation(AVLtree x)
 {
 	AVLnode* c;
 	c=x->left;
 	x->left=c->right;
 	c->right=x;
 	//记得更新高度
	c->h=max(gethight(c->left),gethight(c->right))+1;
 	x->h=max(gethight(x->left),gethight(x->right))+1;
 	return c;
 }
 AVLtree RR_rotation(AVLtree x)
 {
 	AVLnode* c;
 	c=x->right;
 	x->right=c->left;
 	c->left=x;
 	//记得更新高度
	c->h=max(gethight(c->left),gethight(c->right))+1;
 	x->h=max(gethight(x->left),gethight(x->right))+1;
 	return c;
 	
 }
 AVLtree LR_rotation(AVLtree x)
 {
 	x->left=RR_rotation(x->left);
 	x=LL_rotation(x);
 	return x;
 	
 }
 AVLtree RL_rotation(AVLtree x)
 {
 	x->right=LL_rotation(x->right);
 	x=RR_rotation(x);
 	return x;
 }
 
 AVLtree insert(AVLnode* w,int x)
 {
 	if(w==NULL)
 	{
 		AVLnode* c=(AVLnode*)malloc(sizeof(AVLnode));
 		c->data=x;
 		c->left=c->right=NULL;
 		c->h=1;//插入的节点没有孩子节点高度为1
		return c; 
	 }
	 else if(w->data>x)
	 {
	 	 w->left=insert(w->left,x);//找w的左子树 
	 	 //左子树中插入LL LR
		 if(gethight(w->left)-gethight(w->right)>1) //通过高度来判断是否失衡
		 {
		 	AVLnode* z=w->left; 
		 	if(gethight(z->left)>gethight(z->right))//通过比较左右子树的高度来判断是LL还是LR 
		 	{
			 	w=LL_rotation(w);
			 	
		 	}
		 	else
		 	{
		 		w=LR_rotation(w);
		 	
			} 
		 
		 } 
	}
	
		else if(w->data<x)
	 {
	 	w->right=insert(w->right,x);
	 	if(gethight(w->right)-gethight(w->left)>1) //通过高度来判断是否失衡
		 {
		 	AVLnode* z=w->right; 
		 	if(gethight(z->right)>gethight(z->left))//通过比较左右子树的高度来判断是LL还是LR 
		 	{
			 	w=RR_rotation(w);
			 
		 	}
		 	else
		 	{
		 		w=RL_rotation(w);
		 		
			} 
		 } 
	 }
	 w->h=max(gethight(w->left),gethight(w->right))+1;//插入后也要更新高度 
	 return w;
 }
 
 void inorder(AVLtree w)
 {
 	if(w==NULL)
 	{
 		return;
	 }
	 if(w->left!=NULL)
	 {
	 	inorder(w->left);
	 }
	 printf("%d %d\n",w->data,w->h);
	 if(w->right!=NULL)
	 {
	 	inorder(w->right);
	 }
  } 
  
AVLtree find(AVLtree w)
{
	if(w!=NULL)
	{
		w=w->right;
	}	
		return w;
}  
 
AVLtree delet(AVLtree w,int x)
{
	if(w==NULL)
	{
		return w;
	}
	else if(w->data>x)
	{
		w->left=delet(w->left,x);
		if(gethight(w->right)-gethight(w->left)>1)
		{
			if(gethight(w->right)>=gethight(w->left))
			{
				w=RR_rotation(w);
			}
			else
			{
				w=RL_rotation(w);
			}
		}
	 } 
	 else if(w->data<x)
	{
		w->right=delet(w->right,x);
			if(gethight(w->left)-gethight(w->right)>1)
		{
			if(gethight(w->left)>=gethight(w->right))
			{
				w=LL_rotation(w);
			}
			else
			{
				w=LR_rotation(w);
			}
		}
	}
	else
	{
		
		if(w->left!=NULL&&w->right!=NULL)
		{
			AVLnode* z=find(w->left);
			w->data=z->data;
			w->left=delet(w->left,z->data);
			if(gethight(w->right)-gethight(w->left)>1)
		{
			if(gethight(w->right)>=gethight(w->left))
			{
				w=RR_rotation(w);
			}
			else
			{
				w=RL_rotation(w);
			}
		}
			
		}
		else
		{
			AVLnode* z=w;
			if(w->left=NULL)
			{
				w=w->left;
			 } 
			 else 
			{
				w=w->right;
			 } 
			 free(z);
			 z=NULL;
		}
	}
	if(w!=NULL)
	{
		w->h=max(gethight(w->left),gethight(w->right))+1;
	}
	return w;
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
	
	AVLnode* w=NULL;
	w=initAVL(a[1]);
	
	for(int i=2;i<=n;i++)
	{
		w=insert(w,a[i]);
	}
	
	inorder(w);
	 delet(w,5);
	 inorder(w);
	return 0;
 } 
