#include<stdio.h>
#include<stdlib.h>

#define maxsize 20


typedef int Elemtype;

typedef struct LNode{
	Elemtype data;
	struct LNode *next;
}LNode,*LinkList;

bool InitLink(LinkList &L);	//��ʼ������ 
bool InitNHLink(LinkList &L);//��ʼ����ͷ�ڵ����� 
LinkList List_HeadInsert(LinkList &L);//ǰ�巨�������� 
LinkList List_TailInsert(LinkList &L);//��巨�������� 
bool List_NoHInsert(LinkList &L); //��ͷ�ڵ㴴������ 
void printList(LinkList L);	//��ӡ���� 
Elemtype GetELem(LinkList L,int number);//����Ų��� 
Elemtype LocatElem(LinkList L,Elemtype x);//����ֵ���Ҳ�������������λ�� 
bool InsertELem(LinkList &L,Elemtype data,int number);//���� 
void DeletElem(LinkList &L,Elemtype x);//ɾ�� 
LNode *print_T_List(LinkList L);	//������������� 
bool Delet_M_Elem(LinkList &L);		//ɾ����С�ڵ�(����ڵ�Ψһ) 
bool reverseLink(LinkList &L);	//��������Ҫ�󣺲���ʹ�ø������ռ� 

int main(){
	LinkList L;
	int number,x;	//x:��ȡ����  number����ȡλ�� 
//	InitNHLink(L);
	if(InitLink(L)){
		printf("Init Link success!\n");
	}
	else{
		printf("Init Link failed!\n");
		exit(0);
	}
//	List_HeadInsert(L);		//ͷ�巨��������
	List_TailInsert(L);		//β�巨�������� 
	printList(L);			//��ӡ���� 
//	List_NoHInsert(L);		//������ͷ�ڵ�����	
	//����Ų���
//	printf("input the number:");
//	scanf("%d",&number); 
//	x=GetELem(L,number);


	//����ֵ���Ҳ���������λ�� 
//	printf("input the data:");
//	scanf("%d",&x);
//	number=LocatElem(L,x);
//	printf("Number:%d\n",number); 


//	��������
//	printList(L);
//	printf("Input your data and number:");
//	scanf("%d%d",&x,&number);
//	InsertELem(L,x,number);

//	ɾ������
//	printf("Input you want detet data:");
//	scanf("%d",&x);
//	DeletElem(L,x);

//	������������� 
//	LNode *p=L->next;
//	printf("\n");
//	print_T_List(p);	


//	ɾ�������е���Сֵ(������СֵΨһ)
//	ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)
	Delet_M_Elem(L);
	printList(L); 

//����������,Ҫ��:��ʹ�ø����ռ� 
	reverseLink(L);
	
	printList(L); 
	return 0;
} 

bool InitLink(LinkList &L){
	L=(LNode *)malloc(sizeof(LNode));
	L->next=NULL; 
	if(L->next==NULL)
		return  true;
	return false;
}

bool InitNHLink(LinkList &L){
	L=NULL;
	return true;
} 
LinkList List_HeadInsert(LinkList &L){
	LNode *S;
	int x;
	printf("Input your data:");
	scanf("%d",&x);
	while(x!=999){
		S=(LNode *)malloc(sizeof(LNode));
		S->data=x;
		S->next=L->next;
		L->next=S;	
		printf("Input your data:");
		scanf("%d",&x);
	}
	return L;
} 

LinkList List_TailInsert(LinkList &L){
	LNode *s,*r;
	int x;
	r=L;
	printf("Input your data:");
	scanf("%d",&x);
	while(x!=999){
		s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;
		scanf("%d",&x);	
	}
	r->next=NULL;
	
	return L; 
} 

void printList(LinkList L){
	LNode *S=L->next;
	printf("\n");
	while(S){
		printf("%d   ",S->data);
		S=S->next;
	}
} 
Elemtype GetELem(LinkList L,int number){	//����Ų��� 
	LNode *p=L->next;
	int i=1;
	if(!p){
		printf("The list is NULL!\n");
		return 0;
	} 

	while(p){
		if(i==number){
			printf("%d\n",p->data);
			return p->data;
		}
		p=p->next;
		i++;
	}
	return 0;
} 
Elemtype LocatElem(LinkList L,Elemtype x){
	LNode *p=L->next;
	int i=1;
	if(!p){
		printf("The list dont have this data!");
		return NULL;
	} 
	
	while(p){
		if(p->data==x){
			printf("data:%d\n",p->data); 
			return i;
		}
			
		i++;
		p=p->next;
	}
	return NULL;
} 

bool InsertELem(LinkList &L,Elemtype data,int number){		//���뵽��number��λ��
	LNode *P=L,*S;
	int i=1;
	while(P){
		if(i==number){
			S=(LNode *)malloc(sizeof(LNode));
			S->data=data;
			S->next=P->next;
			P->next=S;
			printf("Insert data success!\n"); 
			return true;
		}
		i++;
		P=P->next;
	} 
	return false;
} 

void DeletElem(LinkList &L,Elemtype x){
	LNode *s=L->next;
	LNode *r=L;
	int i=1;
	if(!s){
		printf("The list is NULL!\n");
		return;
	}
	while(s){
		if(s->data==x){
			r->next=s->next;
			free(s);
			s=r->next;
		}
		else{
			r=r->next;
			s=s->next;
		}
		
	}
}	
bool List_NoHInsert(LinkList &L){	//������ͷ�ڵ����� 
	LNode *p,*r;
	int x;
	printf("Input your data:");
	scanf("%d",&x);
	while(x!=999){
		p=(LNode *)malloc(sizeof(LNode));
		p->data=x;
		p->next=L;
		L=p;
		scanf("%d",&x);
	}
	r=L;
	while(r){
		printf("%d  ",r->data);
		r=r->next;
	}
	return true;
}

LNode *print_T_List(LinkList L){	//�������������  ���õݹ�˼�� 

	if(L->next!=NULL){
		print_T_List(L->next);
	}
	if(L->data!=NULL)
		printf("%d  ",L->data);
} 

bool Delet_M_Elem(LinkList &L){		//ɾ����С�ڵ�(����ڵ�Ψһ) 
	LNode *p,*prior,*r,*t;
	p = L->next;
	prior = L;
	r = p;		//rָ���¼��Сֵ�ڵ� 
	t = prior; 	//p��¼��Сֵ�ڵ�ǰ�� 
	Elemtype temp=p->data;
	while(p){
		if(temp>p->data){
			r=p;
			t = prior; 
			temp=p->data;
		}
		prior = prior->next;
		p=p->next;
	}	//��Сֵ�ڵ�Ϊr,��ǰ��Ϊt; 

	t->next = r->next;

	free(r);
	return true;
} 
bool reverseLink(LinkList &L)	//��������Ҫ�󣺲���ʹ�ø������ռ� 
{
	LNode *p=L->next,*r;
	L->next=NULL;
	int  i =0;
	while(p != NULL){
		r = p->next; 
		p->next = L->next;
		L->next = p;
		p = r;
		
	}
	return true;
} 
