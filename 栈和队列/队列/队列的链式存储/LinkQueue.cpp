#include<stdio.h>
#include<stdlib.h>

#define Maxsize 10

typedef int Elemtype;

typedef struct LinkNode{
	Elemtype data;
	struct LinkNode *next;
}LinkNode;
typedef struct {
	LinkNode *front,*rear;
}LinkQueue;

bool InitQueue(LinkQueue &Q);	//��ʼ������ 
bool IsEmpty(LinkQueue &Q);		//�п� 
bool EnQueue(LinkQueue &Q,Elemtype x);	//��� 
bool PopQueue(LinkQueue &Q);	//���� 
bool PrintQ(LinkQueue Q);	//��ӡ����ͷβ 



int main(){
	LinkQueue Q;
	int x;
	InitQueue(Q);
	printf("Input your data:");
	scanf("%d",&x);
	while(x!=999){
		EnQueue(Q,x);
		scanf("%d",&x); 
	}
	PopQueue(Q);
	 PrintQ(Q);
	return 0; 
}

bool InitQueue(LinkQueue &Q){	//��ʼ������ 
	Q.front=Q.rear=(LinkNode *)malloc(sizeof(LinkNode));
	Q.front->next=NULL;
} 
bool IsEmpty(LinkQueue &Q){		//�п� 
	if(Q.front==Q.rear){
		printf("The Queue is empty!\n");
		return true;
	}
	return false;
} 

bool EnQueue(LinkQueue &Q,Elemtype x)	//��� 
{
	LinkNode *L=(LinkNode *)malloc(sizeof(LinkNode));
	L->data=x;
	L->next=NULL;
	Q.rear->next=L;
	Q.rear=L;
} 

bool PopQueue(LinkQueue &Q)		//����
{
	if(IsEmpty(Q)){
		return false;
	}
	LinkNode *p=Q.front->next;
	Q.front->next=p->next; 
	if(p==Q.rear){
		Q.front=Q.rear;
	}
	free(p);
	return true;
} 

bool PrintQ(LinkQueue Q)	//��ӡ����ͷβ 
{
	if(IsEmpty(Q))
		return false;
	printf("The front data is:%d\n",Q.front->next->data);
	printf("The rear data is:%d\n",Q.rear->data);
} 



