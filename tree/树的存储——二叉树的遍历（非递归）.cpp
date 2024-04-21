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
	btree* data; //ջ���������Ľڵ����ݣ��������������������� 
	struct stack* next;
}sstack;
sstack* s=NULL;
//ջ�ĳ�ʼ��
 void initstack()
 {
 	s=(sstack*)malloc(sizeof(sstack));
 	if(s==NULL)
 	{
 		printf("�ڴ濪��ʧ��");
		 return ;
	 }
	 s->next=NULL;
 }
 //��ջ
 void ppush(btree* w)//��������ջ�� 
 {
 	sstack* h=(sstack*)malloc(sizeof(sstack));
 	h->data=w;
 	h->next=s->next;
 	s->next=h;
  } 
  //��ջ��Ҫ������������Ҫ����������
  btree* ppop()
  {
  	if(s->next==NULL)
  	{
  		printf("ջΪ��");
		  return NULL; 
	  }
	  sstack* x=s->next;
	  btree* w=s->next->data;//��ͷ�ڵ�������ͷų��� 
	  s->next=x->next;
	  free(x);
	  x=NULL;
	  return w;
   } 
   
//ע�����ﺯ������Ϊ�������� �жϵĹؼ������Ƿ��з���ֵ 
tree inittree(char x)//����һ��������Ϊ���ĸ��ڵ� 
{
	btree* z=(btree*)malloc(sizeof(btree));
	if(z==NULL)
	{
		printf("�ڴ����ʧ��/n"); 
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
		if(c!=NULL&&c->data==fx)//�ݹ����Ϊ��Ϊ�ղ���Ϊ���ڵ� 
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
void insert(btree* w,char x,char fx,int flag)//���벻��Ҫ����ֵ 
{
	//���ҵ����׽ڵ�ĸ��� 
	btree* c=find(w,fx); 
	if(c!=NULL)//���ж��Ƿ�Ϊ�պ��ж����Һ��� 
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
 //����
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
  
//�������
void inorder()
{
	initstack();
	if(w==NULL)
	{
		return;
	}
	btree* node=w;
	btree* k=NULL;
	while(s->next!=NULL||node!=NULL)//ջ��Ϊ�ջ�����Ϊ�� 
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
			k=s->next->data;//�õ�ջ��Ԫ��
			if(k->right!=NULL&&pre!=k->right)//�Һ��Ӳ�Ϊ�� ���Һ���û������ 
			{
				node=k->right;
			 } 
			 else
			 {
			 	k=ppop;
			 	printf("%c",k->data);
			 	pre=k;//�����ж���һ����û�б����� 
			 	node=NULL;//ֻ��nodeΪ�ղ���ѭ��ִ�� 
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
	tree w=NULL;//�ȸ�Ϊ�� 
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
