#include<stdio.h>
#include <stdlib.h>

typedef struct AVL_Node{
	int data;
	struct AVL_Node *lchild,*rchild;
	int balance;
}AVL_Node,*AVL_Tree;

int Get_High(AVL_Tree T,int x);	//����������ĸ߶� 
bool Insert(AVL_Tree &T,int data);	//�������� 
bool Left_Left(AVL_Tree &T);	//ll�����Сʧ����������������һ�� 
bool Left_Right(AVL_Tree &T);	//LR,����Сʧ����A��������B��������C��㣬����������������תһ�� 
bool Right_Right(AVL_Tree &T);	//RR,��Сʧ����������������һ��
bool Right_Left(AVL_Tree &T);	//RL,����Сʧ����A��������B��������C��㣬�������������� 
bool creat(AVL_Tree &T,int x[],int n);	//����ƽ������� 

int main(){
	return 0;
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
		T->lchild = T->rchild = NULL;
		T->data = x;
	}
	
	else if(x > T->data){ 
		Insert(T->rchild,x);//�ݹ���룬���ڵݹ�������¼���balanceƽ������
		T->balance = Get_High(T->lchild)-Get_High(T->lchild);
		
		if(T->balance == 2 || T->balance == -2){	//���T�Ƿ�Ϊ��Сʧ���� 
		
			if(T->rchild->balance == 1){	//�ж� T�������Ҫ������ת 
				Right_Left(T);				//��balanceΪ1ʱ��֤�������ݲ�������T������������������ 
			}
			
			else if(T->rchild->balance == -1){//balanceΪ-1ʱ��֤�������ݲ�������T������������������
				Right_Right(T);
			}
				
		} 
	}
	else if(x < T->data)
	{
		Insert(T->lchild,x);	//�ݹ���룬���ڵݹ�������¼���balanceƽ������ 
		T->balance = Get_High(T->lchild)-Get_High(T->lchild); 
		
		if(T->balance == 2 || T->balance == -2){
			
			if(T->lchild->balance == 1){
				Left_Left(T);
			}
			
			if(T->lchild->balance == -1){
				Left_Right(T);
			}
			
		}
	}
		
} 


bool Left_Left(AVL_Tree &T)		//ll�����Сʧ��������������һ�� 
{
	AVL_Node *K;
	K=T->lchild;
	T->lchild = K->rchild;
	K->rchild = T;
	
	T->balance = Get_High(T->lchild)- Get_High(T->rchild);
	K->balance = Get_High(K->lchild)- Get_High(K->rchild);
	
} 

bool Left_Right(AVL_Tree &T)	
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
} 
bool Right_Right(AVL_Tree &T)	//RR,��Сʧ����������������һ��
{
	AVL_Node *k;
	k=T->rchild;
	T->rchild = k->lchild;
	k->lchild = T; 
	
	T->balance = Get_High(T->lchild)- Get_High(T->rchild);
	k->balance = Get_High(k->lchild)- Get_High(k->rchild);
} 

bool Right_Left(AVL_Tree &T)	//RL,����Сʧ����A��������B��������C��㣬��������������
{
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
} 

bool creat(AVL_Tree &T,int x[],int n)	//����ƽ������� 
{
	
	return true; 
} 
