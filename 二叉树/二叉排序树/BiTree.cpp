#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 11


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
int GetWidth(BiTree B);		//������ 
int Get_Total(BiTree B);	//�������Ľڵ��� 
void Find_Ancestor(BiTree B,int x,BiNode *S[]);	//Ѱ�� data=x�ڵ������ (��ͨ����������x��·��)
BiNode *Find_Parent(BiTree B,int x);	//Ѱ��x�ڵ������ 
bool Judge_Same(BiTree A,BiTree B);		//�ж����Ŷ������Ƿ���ͬ 
void Order(BiTree B);	//�ǵݹ����������  


/**********************
		�������ṹ 
			   50
		    /     \
		   30      70
		  / \     /  \
 		 20 36   63  76
 		   / \   /    \
 		  31 40 72     80
*********************/






int main(){
	int x[MAXSIZE]={50,30,70,20,36,63,76,31,40,72,80};
	int x2[MAXSIZE]={50,30,70,20,36,63,76,31,40,72,80};
	BiNode *Stack[100];	//�ǵݹ����ջ 
	BiTree B;
	BiTree A;
	BiNode *S;
	BiNode *s;
	int i=1;
	int depth;
	
	int data = 100;
	
	BST_Creat(B,x,MAXSIZE);
	BST_Creat(A,x2,MAXSIZE);
	
	
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
	printf("�ǵݹ飺"); 
	Order(B);
	printf("\n");
	
//	printf("�ǵݹ��������Ϊ��%d\n",GetDepth(B));
//	printf("��������Ϊ��%d\n",GetWidth(B));
//	printf("���������ܽ����Ϊ%d\n",Get_Total(B));
//	Order(B);
//	printf("\n");
//	

/********************************
	Ѱ���������Ƚڵ㣨Ѱ��·���� 
********************************/
//	Find_Ancestor(B,80,Stack);

/*****************************
		Ѱ�Ҹ��׽ڵ� 
********************************/
	if(Find_Parent(B,data))
		printf("data = %d �ĸ��ڵ�Ϊ��%d",data,Find_Parent(B,data)->data);
	else	
		printf("�ýڵ㲻����(��ýڵ�Ϊ���ڵ�)");
	return 0;

/*****************************
		�ж������������Ƿ���ͬ�� 
********************************/

//	if(Judge_Same(B,A))
//		printf("SAME\n");
//	
//	else
//		printf("NOT SAME\n"); 

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
/*
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
*/
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

int GetWidth(BiTree B)		//������ 
{
	BiNode *p = B;
	BiNode *Q[100];
	int front = -1,rear = -1;
	int last;
	int i = 0,max = 0;
	
	if(!p)
		return max;
	Q[++rear] = p;
	last = rear;
	
	while(front < rear)	//p�ǿջ���в�Ϊ��
	{
		p = Q[++front];	//����
		i++;
		if(p->lchild)
			Q[++rear] = p->lchild;
		if(p->rchild)
			Q[++rear] = p->rchild;
		
		if(front == last){
			last = rear;
			if(i > max)
				max = i;
			i = 0;
		} 

	 }
	return max; 
}

int Get_Total(BiTree B)	//�������Ľڵ���
{
	BiNode *p = B;
	if(!p)
		return 0;
	
	int lnum,rnum,total;
	lnum = Get_Total(p->lchild);
	rnum = Get_Total(p->rchild);
	total = lnum + rnum + 1;
	
	return total;
}

void Find_Ancestor(BiTree B,int x,BiNode *S[])	//Ѱ�� data=x�ڵ������ 
{
/*	int top = 0;
	BiNode *r = NULL;
	int test = 0;
	BiNode *p = B;
	while(p != NULL || top > 0){
		test++;
		if(p != NULL){
			if(p->data == x){
				printf("top = %d\n",top); 
				break;	//�ҵ��ýڵ㣬�˳�ѭ�� 
			}
			S[++top] = p;
			p = p->lchild;
			
		}
		
		else {	//�ýڵ�Ϊ��
			p = S[top];		//��ȡջ��Ԫ��
			if(p->rchild != NULL && p->rchild != r)	{//������������û�б����ʹ� 
				p=p->rchild;
				if(p->data == x){		//���ýڵ��Ƿ�Ϊx�ڵ� 
					printf("top = %d\n",top); 
					break;
				}
				S[++top] = p;
				p = p->lchild;
			}
			
			else{	//�����������ڻ򱻷��ʹ�
				p = S[top--];
				r = p;
				p = NULL;	
				 //����ϴη��ʹ��Ľڵ㣬�����´�ѭ�� 
			}
			
		}
	}
	
*/	
	
	
//	printf("test = %d\n",test);
//	for(int i = 1;i<=top;i++){
//		p = S[i];
//		printf("%d  ",p->data);	//��ջ����ջ����ӡջ 
//	}
//	printf("\n"); 



}

BiNode *Find_Parent(BiTree B,int x) //Ѱ��data = x�ڵ�ĸ��ڵ�
{
/*	BiTree S[MAXSIZE];
	int top = 0;
	BiNode *p = B;
	BiNode *r = NULL;
	int i = 0;
	if(!p){	//������x�ڵ�Ϊ���ڵ� 
		return NULL;
	}
	
	while(top > 0 || p){
		if(p){
			S[++top] = p;
			if(p->lchild && p->lchild->data == x)
				return p;
			if(p->rchild && p->rchild->data == x)
				return p;
			p = p->lchild;
		}
		else{
			p = S[top];	//��ȡջ��Ԫ��
			if(p->rchild && p->rchild != r){
				p = p->rchild;
				if(p->lchild && p->lchild->data == x)
					return p;
				if(p->rchild && p->rchild->data == x)
					return p;
				S[++top] = p;
				p = p->rchild;
			} 
			else{
				p = S[top--];
				//visite(p);
				r = p;
				p = NULL;
			}
		}
	}
	
	return NULL;
	
	*/
	
	if(!B)
		return NULL;
		
	BiNode *left,*right;
	
	if(B->lchild && B->lchild->data == x)
		return B;
	
	else if(B->rchild && B->rchild->data == x)
		return B; 
	
	left = Find_Parent(B->lchild,x);
    right = Find_Parent(B->rchild,x);
	
	if(left)
		return left;
	else if(right)
		return right;
	

}


bool Judge_Same(BiTree A,BiTree B)		//�ж����Ŷ������Ƿ���ͬ
{
	
	if(!A && !B)	//A,B ��Ϊ�� 
		return true;
		
	if(A == NULL || B == NULL)	//A��BΪ�� 
		return false;
		
	if(A->data != B->data)	//A��B�ڵ�ֵ����ͬ 
		return false;
		
	bool pl,pr;
	
	pl = Judge_Same(A->lchild,B->lchild);
	pr = Judge_Same(A->rchild,B->rchild);
	return pl&&pr; 		

}
