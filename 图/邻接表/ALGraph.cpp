#include<stdio.h>
#include<stdlib.h>

#define MaxNum 100

typedef int Elemtype;


typedef struct ArcNode{		//�߱��� 
	int adjvex;				//�û���ָ��Ķ���λ��
	struct ArcNode *next;	//ָ����һ������ָ��
	//int Info  			//Ȩֵ	
}ArcNode;

typedef struct VNode{		//����� 
	Elemtype data;			//������Ϣ
	ArcNode *first;			//ָ���һ����ö��������Ķ���ָ�� 
}VNode,AdjList[MaxNum];	

typedef struct{				//�ڽӱ� 
	AdjList vertices;		//ͼ�Ķ����
	int vexnum,arcnum;		//ͼ�Ķ������ͻ��� 
}ALGraph;

bool Init_Graph(ALGraph &G);	//��ʼ��ͼ 
bool Insert(ALGraph &G,Elemtype x);	//���붥�� 
int Search_Graph(ALGraph G,Elemtype x);		//����ͼ���Ƿ����x����
bool creat_Graph(ALGraph &G);		//�����ڽӱ� 
void print_Graph(ALGraph G);	//�����ڽӱ������ṹ��ӡ��ǰͼ 

int main(){
	ALGraph G;
	if(!Init_Graph(G)){
		printf("��ʼ��ʧ��!\n");
		return 0;
	}
	
	printf("��ʼ���ɹ�!\n");
	
	
	for(int j = 1;j <= 3;j++)
		Insert(G,j+96);
	print_Graph(G);
	return 0;
} 

bool Init_Graph(ALGraph &G)		//��ʼ��ͼ
{
	for(int i = 1;i <= MaxNum;i++)
	{
		G.vertices[i].data=0;
		G.vertices[i].first = (ArcNode *)malloc(sizeof(ArcNode));
		G.vertices[i].first->next = NULL;
	}
	G.arcnum = G.vexnum = 0;
	return true;
}

bool Insert(ALGraph &G,Elemtype x)	//���붥�� 
{
	if(G.vexnum == MaxNum){
		printf("ͼ����������ʧ��!");
		return false;
	}
	
	Elemtype temp;
	int j;
	
	
	G.vexnum++;
	G.vertices[G.vexnum].data=x;	//��ֵ 
	ArcNode *S = G.vertices[G.vexnum].first;
	
	while(S->next != NULL){		//�ҵ����һ��ָ���� 
			S = S->next;
	}
	
	printf("��������%c�������ӵĶ���:",x);
	scanf("%c%*c",&temp);

	while(temp != 'z'){
		j = Search_Graph(G,temp);
		printf("j = %d\n",j);
		if(j > MaxNum){
			printf("ͼ��û�д˶��㣡");
			return false;
		}
		
		else if(temp == x){
			printf("��ֹ�뵱ǰ���������\n");
			return 0;
		}
		
		ArcNode *A = (ArcNode *)malloc(sizeof(ArcNode));
		A->adjvex=j;
		
		A->next =S->next;
		S->next = A; 
		
		G.arcnum++;	
		printf("  %d  \n",G.vertices[G.vexnum].first->next->adjvex);
		if(G.vertices[G.vexnum].first->next->next != NULL){
			printf("  %d  \n",G.vertices[G.vexnum].first->next->next->adjvex);
		}
		
		printf("��������һ����%c�������ӵĶ���:",x);
		scanf("%c%*c",&temp);
	} 
	
	return true; 
} 

int Search_Graph(ALGraph G,Elemtype x)		//����ͼ���Ƿ����x����
{
	for(int i = 1;i<=G.vexnum;i++){
		if(x == G.vertices[i].data)
			return i;
	}
	return MaxNum+1;
}
void print_Graph(ALGraph G)	//�����ڽӱ������ṹ��ӡ��ǰͼ 
{
	ArcNode *S;
	printf("���� \n");
	for(int i = 1;i <= G.vexnum;i++){
		printf(" %c ->",G.vertices[i].data);
		S = G.vertices[i].first->next;
		while(S != NULL){
			//printf("%d",S->adjvex);
			printf("%c",G.vertices[S->adjvex].data);
			printf("->");
			S=S->next;
		}
		printf("NULL\n");
	}
}

bool creat_Graph(ALGraph &G)		//�����ڽӱ� 
{
	
}
