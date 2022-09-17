#include<stdio.h>

#define Maxsize 20

typedef int Elemtype;

typedef struct{
	Elemtype data[Maxsize];
	int top;
}SqStack;
 
bool Initstack(SqStack &S);	//��ʼ��ջ 
bool StackEmpty(SqStack S);	//�ж�ջ�� 
bool Push(SqStack &S,Elemtype data);	//��ջ 
bool PrintStack(SqStack &S);	//��ӡ��ǰջ��Ԫ�� 
bool Pop(SqStack &S);	//��ջ 




int main(){
	SqStack S;
	Elemtype x;
	Initstack(S);
	printf("Input your data:");
	scanf("%d",&x);
	while(S.top==Maxsize-1 || x!=999){
		Push(S,x);
		scanf("%d",&x);
	}
	Pop(S);
	PrintStack(S);
	return 0;
}


bool Initstack(SqStack &S){	//��ʼ��ջ 
	S.top=-1;
	return true; 
} 
bool StackEmpty(SqStack S)	//�ж�ջ��
{
	if(S.top==-1){
		printf("The stack is empty");
		return true;
	} 
	else 
		return false;
} 

bool Push(SqStack &S,Elemtype data)	//��ջ
{
	if(S.top==Maxsize-1){
		printf("The stack is full");
		return false;
	} 
	S.data[++S.top]=data;
	return true;
} 

bool PrintStack(SqStack &S)	//��ӡ��ǰջ��Ԫ��
{
	printf("%d",S.data[S.top]);
} 

bool Pop(SqStack &S)	//��ջ
{
	if(StackEmpty(S)){
		printf("The stack is empty!");
		return false; 
	} 
	S.top--;
	return false;
	
} 

