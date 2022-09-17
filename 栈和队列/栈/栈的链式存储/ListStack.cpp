#include<stdio.h>
#include<stdlib.h>

#define Maxsize 50

typedef int Elemtype;

typedef struct Linknode{
	Elemtype data; 
	struct Linknode *next;
}*LiStack;

bool InitLiStack(LiStack &L);	//��ʼ��ջ 
bool Push(LiStack &L,Elemtype x);	//��ջ
bool Pop(LiStack &L);	//��ջ 
bool printStack(LiStack L);	//��ӡջ�� 
bool StackEmpty(LiStack L);	//�п� 


int main(){
	LiStack L;
	Elemtype x;
	InitLiStack(L);
	printf("Input your data:");
	scanf("%d",&x);
	while(x!=999){
		Push(L,x);
		scanf("%d",&x);
	}
	Pop(L);
	printStack(L);
	return 0;
}




bool InitLiStack(LiStack &L)	//��ʼ��ջ 
{
	L=NULL;
	return true; 
} 
bool Push(LiStack &L,Elemtype x)	//��ջ
{
	LiStack S;
	if(L==NULL){
		S=(LiStack)malloc(sizeof(LiStack));
		S->data=x;
		L=S;
	}
	else{
		S=(LiStack)malloc(sizeof(LiStack));
		S->data=x;
		S->next=L;
		L=S;
	}
	return true;
} 
bool Pop(LiStack &L)	//��ջ 
{
	LiStack S;
	S=L;
	L=L->next;
	free(S);
	return true;
}
bool StackEmpty(LiStack L){		//�п� 
	if(L==NULL)
		return true;
	else return false; 
}
bool printStack(LiStack L){	//��ӡջ�� 
	if(StackEmpty(L)){
		printf("The Stack is NULL\n");
		return false;
	} 
	printf("%d",L->data); 
}

