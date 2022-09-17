#include<stdio.h>
#include<stdlib.h>

typedef struct Data{
	char data;
}Elemtype;

typedef struct CSNode{	//�����ֵܱ�ʾ�� 
	Elemtype data;
	struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;

bool InitCS(CSTree &C);	//��ʼ����
bool CreateCS(CSTree &C);//������
void InOrder(CSTree C);	//�ȸ�����
void PostOrder(CSTree C);	//������� 




int main(){
	CSTree C;
	Elemtype x;
	if(!InitCS(C)){
		printf("Init Tree false");
		return 0;
	}
	printf("Init success\n");
	
	
	printf("please input root data:");
	scanf("%c%*c",&x.data);	//%*c:�����������ַ���Ļس� 
	C->data=x; 
	CreateCS(C);	//������ 
	
	InOrder(C);
	printf("\n");
	
	PostOrder(C);
	printf("\n");
	return 0;
}


bool InitCS(CSTree &C)	//��ʼ����
{
	C = (CSNode *)malloc(sizeof(CSNode));
	C->firstchild=C->nextsibling=NULL;
	return true; 
}
bool CreateCS(CSTree &C)//������
{
	Elemtype x;
	CSNode *S;

	
	printf("������%c�ڵ�ĵ�һ�����ӵ����ݣ�",C->data.data);
	scanf("%c%*c",&x.data);
	if(x.data != '9'){
		InitCS(S);
		S->data = x;
		C->firstchild=S;
		CreateCS(S);
	}
	
	printf("������%c�ڵ�����ֵܵ����ݣ�",C->data.data);
	scanf("%c%*c",&x.data);
	if(x.data != '9'){
		InitCS(S);
		S->data = x;
		C->nextsibling=S;
		CreateCS(S);
	}
} 

void InOrder(CSTree C)	//�ȸ�����
{
	if(C != NULL){
		printf("%c ",C->data.data);
		InOrder(C->firstchild);
		InOrder(C->nextsibling);
	} 
} 
void PostOrder(CSTree C)	//�������
{
		if(C != NULL){
			InOrder(C->firstchild);
			printcf("%c ",C->data.data);
			InOrder(C->nextsibling);
	
	}
} 
