#include<stdio.h>
#include <stdlib.h>

typedef struct AVL_Node{
	int data;
	struct AVL_Node *lchild,*rchild;
	int balance;
}AVL_Node,*AVL_Tree;

AVL_Node *father;	//����һ������㣬����ɾ������ʱ��λ����� 

bool InitTree(AVL_Tree &T);		//��ʼ��ƽ������� 
int Get_High(AVL_Tree T);	//����������ĸ߶� 
bool Insert(AVL_Tree &T,int data);	//�������� 
AVL_Node *Left_Left(AVL_Tree &T);	//ll�����Сʧ����������������һ�� 
AVL_Node *Left_Right(AVL_Tree &T);	//LR,����Сʧ����A��������B��������C��㣬����������������תһ�� 
AVL_Node *Right_Right(AVL_Tree &T);	//RR,��Сʧ����������������һ��
AVL_Node *Right_Left(AVL_Tree &T);	//RL,����Сʧ����A��������B��������C��㣬�������������� 
bool creat(AVL_Tree &T,int x[],int n);	//����ƽ������� 
void InOrder(AVL_Tree T);	//�������ƽ������� 
AVL_Node *AVL_Search(AVL_Tree B,int x);	//ƽ�����Ĳ���
AVL_Node *AVL_Delete(AVL_Tree &T,int x);	//ƽ������ɾ�� 


int main(){
	AVL_Tree T;
	int x[10]={5,10,12,25,35,40,50,60,63,90};
	InitTree(T);
	
	creat(T,x,10);
	InOrder(T);
	printf("\nTree High:%d\n",Get_High(T));
	return 0;
} 

bool InitTree(AVL_Tree &T)		//��ʼ��ƽ������� 
{
	T=NULL; 
} 
int Get_High(AVL_Tree T)	//����������ĸ߶� 
{
	int MAXH,LH,RH;
	if(T != NULL){
		LH=Get_High(T->lchild);
		RH=Get_High(T->rchild);
		MAXH=LH > RH ? LH : RH;
		return MAXH+1;
	}
	else return 0;

}

bool Insert(AVL_Tree &T,int x)	//�������� 
{
	if(T == NULL){
		T = (AVL_Node *)malloc(sizeof(AVL_Node));
		T->lchild=T->rchild=NULL;
		T->data = x;
	}
	
	else if(x > T->data){ 
		Insert(T->rchild,x);//�ݹ���룬���ڵݹ�������¼����·�������нڵ��balanceƽ������
		T->balance = Get_High(T->lchild)-Get_High(T->rchild);
		if(T->balance == 2 || T->balance == -2){	//���T�Ƿ�Ϊ��Сʧ���� 
			if(T->rchild->balance == 1){	//�ж� T�������Ҫ������ת 
				T=Right_Left(T);				//��balanceΪ1ʱ��֤�������ݲ�������T������������������ 
			}
			
			else if(T->rchild->balance == -1){//balanceΪ-1ʱ��֤�������ݲ�������T������������������
				T=Right_Right(T);
			}
		} 
	}
	else if(x < T->data)
	{
		Insert(T->lchild,x);	//�ݹ���룬���ڵݹ�������¼���balanceƽ������ 
		T->balance = Get_High(T->lchild)-Get_High(T->rchild); 
		
		if(T->balance == 2 || T->balance == -2){
			
			if(T->lchild->balance == 1){
				T=Left_Left(T);
			}
			
			if(T->lchild->balance == -1){
				T=Left_Right(T);
			}
			
		}
	}
		
} 


AVL_Node *Left_Left(AVL_Tree &T)		//ll�����Сʧ��������������һ�� 
{
	AVL_Node *K;
	K=T->lchild;
	T->lchild = K->rchild;
	K->rchild = T;
	
	T->balance = Get_High(T->lchild)- Get_High(T->rchild);
	K->balance = Get_High(K->lchild)- Get_High(K->rchild);
	return K;
} 

AVL_Node *Left_Right(AVL_Tree &T)	
{//LR,����Сʧ����A��������B��������C��㣬����������������תһ�� 

	AVL_Node *k,*m;
	k=T->lchild->rchild;
	m=T->lchild;
	
	//1.������һ��
	m->rchild = k->lchild;
	T->lchild = k;	
	k->lchild = m;
	
	//2. ������һ�� 
	T->lchild = k->rchild;
	k->rchild = T; 
 
 
 	//���¼���balanceƽ������
	T->balance = Get_High(T->lchild)- Get_High(T->rchild);
	k->balance = Get_High(k->lchild)- Get_High(k->rchild);
	m->balance = Get_High(m->lchild)- Get_High(m->rchild);
	return k;
} 
AVL_Node *Right_Right(AVL_Tree &T)	//RR,��Сʧ����������������һ��
{
	AVL_Node *k;
	k=T->rchild;
	T->rchild = k->lchild;
	k->lchild = T; 
	
	T->balance = Get_High(T->lchild)- Get_High(T->rchild);
	k->balance = Get_High(k->lchild)- Get_High(k->rchild);
	return k;
} 

AVL_Node *Right_Left(AVL_Tree &T)	//RL,����Сʧ����A��������B��������C��㣬��������������
{
	printf("4\n");
	AVL_Node *k,*m;
	m=T->rchild;
	k=m->lchild;
	
	//����
	m->lchild = k->rchild;
	T->rchild = k;
	k->rchild = m;
	
	//����
	T->rchild = k->lchild;
	k->lchild = T;
	
	//���¼���balanceƽ������ 
	T->balance = Get_High(T->lchild)- Get_High(T->rchild);
	k->balance = Get_High(k->lchild)- Get_High(k->rchild);
	m->balance = Get_High(m->lchild)- Get_High(m->rchild);
	return k;
} 

bool creat(AVL_Tree &T,int x[],int n)	//����ƽ������� 
{
	for(int i=0;i<n;i++){
		Insert(T,x[i]);
	} 
	return true; 
} 

void InOrder(AVL_Tree T)	//�������ƽ������� 
{
	if(T != NULL){
		InOrder(T->lchild);
		printf("%d  ",T->data);
		InOrder(T->rchild);
	}
} 
AVL_Node *AVL_Search(AVL_Tree B,int x)	//�������Ĳ��� 
{
	while(B != NULL && B->data != x){
		if(B->data > x){
			B=B->lchild;
		}
		if(B->data < x){
			B=B->rchild;
		}
	} 
	return B;
} 

AVL_Node *AVL_Delete(AVL_Tree &T,int x)	//ƽ������ɾ�� 
{
	/*
	��4������� 
	1. ɾ��Ҷ�ӽ��
	2.ɾ���Ľ����������
	3.ɾ���Ľ����������
	4.ɾ���Ľ������������ 
	*/ 
	
	if(T->data == x)
	{
		if()
	}
	if(x>T->data){
		AVL_Delete(T->rchild,x);	
		
	} 
} 
