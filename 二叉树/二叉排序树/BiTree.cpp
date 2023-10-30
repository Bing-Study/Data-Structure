#include<stdio.h>
#include<stdlib.h>


typedef struct BiNode{	
	int data;
	struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

BiNode *father;	//����� 

bool InitTree(BiTree &B);	//��ʼ�������� 
bool BST_Creat(BiTree &B,int x[],int n);	//�������������� 
int  BST_Insert(BiTree &B,int x);	//�������Ĳ���
BiNode *BST_Search(BiTree B,int x);	//�������Ĳ��� 
void InOrder(BiTree B);	//������������� 
bool BST_Delet(BiTree &B,int x);	//ɾ������ 
BiNode *Search_Next(BiTree B);	//Ѱ�ҽڵ�ĺ��  
int GetDepth(BiTree B);		//�ǵݹ������� 
int Get_Depth(BiTree B);	//�ݹ������� 

void Order(BiTree B);	//�ǵݹ����������  



int main(){
	int x[10]={50,30,70,20,36,63,76,31,40,80};
	BiTree B;
	BiNode *S;
	int i=0;
	int depth;
	
	BST_Creat(B,x,10);
	
	
/*	
	InOrder(B);
	printf("\n");
	S = BST_Search(B,20);
	printf("S->data:%d\n",S->data);
	printf("S's father->data:%d\n",father->data);
	printf("next->data:%d\n",Search_Next(S->rchild)->data);
	
	BST_Delet(B,30);
	InOrder(B);
*/
//	printf("�ǵݹ飺"); 
//	Order(B);
//	printf("\n");
	
	printf("�ǵݹ��������Ϊ��%d",GetDepth(B));
	printf("�ݹ��������Ϊ��%d",Get_Depth(B));
	
	return 0;
}

bool InitTree(BiTree &B)		//��ʼ��������
{
	B = (BiNode *)malloc(sizeof(BiNode));
	B->rchild=B->rchild=NULL;
	return true;
}

int  BST_Insert(BiTree &B,int x)	//�������Ĳ���
{
	if(B == NULL){
		B = (BiNode *)malloc(sizeof(BiNode));
		B->data = x;
		B->lchild = B->rchild = NULL;
		return 1;
	}
	else if(x == B->data)
		return 0;
	else if(x > B->data)
		return BST_Insert(B->rchild,x);
	else if(x < B->data)
		return BST_Insert(B->lchild,x);
}

BiNode *BST_Search(BiTree B,int x)	//�������Ĳ��� 
{
	while(B != NULL && B->data != x){
		if(B->data > x){
			father = B;
			B=B->lchild;
		}
		if(B->data < x){
			father = B;
			B=B->rchild;
			
		}
	} 
	return B;
} 

bool BST_Creat(BiTree &B,int x[],int n)	//�������������� 
{
	B = NULL;
	int i=0;
	while(i < n){
		BST_Insert(B,x[i]);
		i++;
		
	}
}

void InOrder(BiTree B)	//������������� 
{
	if(B != NULL){
		InOrder(B->lchild);
		printf("%d ",B->data);
		InOrder(B->rchild);
	} 
} 

BiNode *Search_Next(BiTree B)	//Ѱ�ҽڵ�ĺ�� 
{
	if(B->lchild == NULL){
		return B;
	}
	return Search_Next(B->lchild);
} 

bool BST_Delet(BiTree &B,int x)	//ɾ������ 
{
/*
���������
(1)�ýڵ���һ��Ҷ�ӽڵ㣬
	ֱ��ɾ������
(2)�ýڵ���һ������������������
	������������������ֱ������ýڵ㲢ɾ��ԭ�ӽڵ�
(3)�ýڵ��������ӽڵ�
	�øýڵ��ֱ�Ӻ���������,(ֱ�Ӻ��Ϊ�ýڵ��������������ߵĽڵ�)
*/ 

	BiNode *S; //�ҵ���ɾ���Ľڵ�
	S = BST_Search(B,x);
	
	if(S->lchild == NULL && S->rchild == NULL)	//���1
	{
		if(father->lchild == S){
			father->lchild = NULL;
		}
		else if(father->rchild == S){
			father->rchild = NULL;
		}
		free(S);
		return true;
	}
	
	else if(S->lchild == NULL && S->rchild != NULL) //���2 
	{
		S->data = S->rchild->data;
		free(S->rchild);
		S->rchild = NULL;
		return true;
	} 
	else if(S->lchild != NULL && S->rchild == NULL) //���2 
	{
		S->data = S->lchild->data;
		free(S->lchild);
		S->lchild = NULL;
		return true;
	} 
	
	else if(S->lchild != NULL && S->rchild != NULL){//���3 
		BiNode *next = Search_Next(S->rchild); 
		BST_Search(B,next->data);	//Ѱ��next�ĸ���� 
		S->data = next->data;
		if(father == S){	//���next�ĸ������S��ͬһ��� 
			father->rchild = next->rchild; 
		}
		else 
		{
			father->rchild = next->rchild;
		}
		free(next);
		return true;
	}
	return false;
} 

void Order(BiTree B){	//�ǵݹ����������
	
	//��ʼ�� 
	BiNode *p=B;
	BiNode *r = NULL; 
	BiNode *S[50];	//ջ 
	int top = 0;	//ջ��ָ��
	
	
/************************************************
					������� 
************************************************/
/*	
	if(p == NULL)
		exit(0);
	
	while(top > 0 || p != NULL){	//ջ�ǿջ�ڵ�ǿ�ʱ 
		if(p != NULL){
			printf("%d ",p->data);
			S[++top] = p;	//���ڵ㲻Ϊ�գ�����ջ
			p = p->lchild;
		}
		else{
			p = S[top--];
			p = p->rchild;
		}
	} 
*/



/************************************************
					������� 
************************************************/

/*	if(B == NULL)
		exit(0);
	while(p != NULL || top > 0){
		if(p != NULL){
			S[++top] = p;
			p = p->lchild;
		}
		else{
			p = S[top--];
			printf("%d ",p->data);
			p = p->rchild;
		}
	}
*/

/************************************************
					������� 
************************************************/
	if(p == NULL)
		exit(0);
	while(p != NULL || top > 0){
		if(p != NULL){
			S[++top] = p;
			p = p->lchild;
		}
		else{
			p = S[top];	//��ȡջ���ڵ�
			//���δ�����������й����� 
			if(p->rchild != NULL && p->rchild != r){
				//��p����������ջ
				p = p->rchild; 
				S[++top] = p;
				//��������p�������� 
				p = p->lchild;
			}
			else {	//�����������ڻ��Ѿ����ʹ�
				p = S[top--];	//��ջ 
				printf("%d ",p->data);	//���ʽڵ� 
				r = p;		//����ϴη��ʽڵ� 
				p = NULL;	//��p�ÿգ�������һ��ѭ�� 
			}
		}
		 
	}

}

int GetDepth(BiTree B)	//�ǵݹ�������
{
	BiNode *p = B;
	BiNode *Q[100];
	int front = -1,rear = -1;
	int last = 0,depth = 0;
	
	if(!p)
		return depth;
	Q[++rear] = p;
	
	while(front < rear)	//p�ǿջ���в�Ϊ��
	{
		p = Q[++front];	//����
		
		if(p->lchild)
			Q[++rear] = p->lchild;
		if(p->rchild)
			Q[++rear] = p->rchild;
		
		if(front == last){
			depth++;
			last = rear;
		} 

	 }
	return depth; 
}
int Get_Depth(BiTree B)	//�ݹ�������
{
	int ldepth;
	int rdepth;
	
	if(!B)
		return 0;
	ldepth = Get_Depth(B->lchild);
	rdepth = Get_Depth(B->rchild);
	return ldepth>rdepth?ldepth + 1:rdepth + 1;
}
