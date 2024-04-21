#include<stdio.h>
#include<string>
#include<stdlib.h>

typedef struct BTree
{
	char data;
	struct BTree* left;
	struct BTree* right;
}btree,*tree;
int flag;
typedef struct stack
{
	btree* data; //栈里存的是树的节点数据；所以这里用树数据类型 
	struct stack* next;
}sstack;
sstack* s=NULL;
//栈的初始化
 void initstack()
 {
 	s=(sstack*)malloc(sizeof(sstack));
 	if(s==NULL)
 	{
 		printf("内存开辟失败");
		 return ;
	 }
	 s->next=NULL;
 }
 //入栈
 void ppush(btree* w)//把树插入栈中 
 {
 	sstack* h=(sstack*)malloc(sizeof(sstack));
 	h->data=w;
 	h->next=s->next;
 	s->next=h;
  } 
  //出栈：要返回数据所以要用树的类型
  btree* ppop()
  {
  	if(s->next==NULL)
  	{
  		printf("栈为空");
		  return NULL; 
	  }
	  sstack* x=s->next;
	  btree* w=s->next->data;//把头节点的数据释放出来 
	  s->next=x->next;
	  free(x);
	  x=NULL;
	  return w;
   } 
   
//注意这里函数类型为树的类型 判断的关键在于是否有返回值 
tree inittree(char x)//传入一个数据作为树的根节点 
{
	btree* z=(btree*)malloc(sizeof(btree));
	if(z==NULL)
	{
		printf("内存分配失败/n"); 
		return NULL;
	}
	 z->left=z->right=NULL; 
	 z->data=x; 
	 return z;	 
}

tree find(btree* w,char fx)
{
	if(w==NULL||w->data==fx)
	{
		return w;
	}
	if(w->	left!=NULL)
	{
		btree* c=find(w->left,fx);
		if(c!=NULL&&c->data==fx)//递归出口为不为空并且为根节点 
		{
			return c;
		}
	}
	if(w->right!=NULL)
	{
		btree* c=find(w->right,fx);
		if(c!=NULL&&c->data==fx)
		{
			return c;
		}
	}
	return NULL;
}
void insert(btree* w,char x,char fx,int flag)//插入不需要返回值 
{
	//先找到父亲节点的父亲 
	btree* c=find(w,fx); 
	if(c!=NULL)//先判断是否为空后判断左右孩子 
	{
		btree* z=(btree*)malloc(sizeof(btree));
		z->data=x;
		z->left=z->right=NULL;
		if(flag==0)
		{
			c->left=z;
		}
		else
		{
			c->right=z;
		}
	}
 } 
 //遍历
 void perorder(tree w)
 {
 	initstack();
 	if(w==NULL)
 	{
 		return;
	 }
	 ppush(w);
	 while(s->next!=NULL)
	 {
	 	btree* node=ppop();
	 	printf("%c",node->data);
	 	if(node->right!=NULL)
	 	{
	 		ppush(node->right);
		 }
		if(node->left!=NULL)
	 	{
	 		ppush(node->left);
		 }
	 }
  } 
  
//中序遍历
void inorder()
{
	initstack();
	if(w==NULL)
	{
		return;
	}
	btree* node=w;
	btree* k=NULL;
	while(s->next!=NULL||node!=NULL)//栈不为空或树不为空 
	{
		if(node!=NULL)
		{
			ppush(node);
			node=node->left
		 } 
		 else
		 {
		 	k=pop();
		 	printf("%c",k->data);
		 	node=k->right;
		
		}
		
	}
}

void postorder()
{
	initstack();
	if(s->next==NULL)
	{
		return;
		
	}
	btree* node=w;
	btree* k=NULL;
	btree* pre=NULL;
	while(s->next!=NULL||node!=NULL)
	{
		if(node!=NULL)
		{
			ppush(node);
			node=node->left;
			
		}
		else
		{
			k=s->next->data;//得到栈顶元素
			if(k->right!=NULL&&pre!=k->right)//右孩子不为空 和右孩子没被遍历 
			{
				node=k->right;
			 } 
			 else
			 {
			 	k=ppop;
			 	printf("%c",k->data);
			 	pre=k;//用于判断上一次有没有被遍历 
			 	node=NULL;//只有node为空才能循环执行 
			 }
		}
	}
}

int main()
{
	char x;
	int n;
	scanf("%d",&n);
	getchar(); 
	scanf("%c",&x); 
	tree w=NULL;//先赋为空 
	w=inittree(x);
	char fx; 
	for(int i=2;i<=n;i++)
	{   
		getchar();
		scanf("%c %c %d",&x,&fx,&flag);
		insert(w,x,fx,flag);
	}
	perorder(w);
	inorder();
	postorder();
	printf("\n");
	return 0;
}
