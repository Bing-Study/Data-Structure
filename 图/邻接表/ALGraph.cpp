#include<stdio.h>
#include<stdlib.h>

#define MaxNum 100

typedef int Elemtype;

bool visited[MaxNum];		//���ʱ������ 

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

typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode;
typedef struct {
	LinkNode *front,*rear;
}LinkQueue;





bool Init_Graph(ALGraph &G);	//��ʼ��ͼ 
bool Insert(ALGraph &G,Elemtype x);	//���붥�� 
int Search_Graph(ALGraph G,Elemtype x);		//����ͼ���Ƿ����x����
bool Creat_Graph(ALGraph &G);		//�����ڽӱ� 
void print_Graph(ALGraph G);	//�����ڽӱ������ṹ��ӡ��ǰͼ 
bool Insert_Edge(ALGraph &G,Elemtype x,Elemtype y);	//������x,y�����ı�
void BFSTraverse(ALGraph G);		//��ͼG���й�������������� 
void BFS(ALGraph G,Elemtype v,LinkQueue &Q);	//��v������������������������
void DFS_Judge_Circle(ALGraph G);		//������������ж��Ƿ���ڻ�· 

bool InitQueue(LinkQueue &Q);	//��ʼ������
bool IsEmpty(LinkQueue &Q);		//�п� 
bool EnQueue(LinkQueue &Q,Elemtype x);	//��� 
int PopQueue(LinkQueue &Q);	//���� 


int main(){
	ALGraph G;
	if(!Init_Graph(G)){
		printf("��ʼ��ʧ��!\n");
		return 0;
	}
	
	printf("��ʼ���ɹ�!\n");
	
	
	Creat_Graph(G);
	
	BFSTraverse(G);
	
	
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

bool Creat_Graph(ALGraph &G)		//�����ڽӱ� 
{
	int x,y;
	//��������ͼ 
	Elemtype data[MaxNum]={'a','b','c','d','e'};	//�����
	//��ϵ�� 
	Elemtype Edge[MaxNum*2][2]={{'a','b'},{'a','c'},{'b','d'},{'d','c'},{'c','e'},};
	
	for(int i = 0;i <= MaxNum;i++){	//���붥�� 
		if(data[i] == NULL)
			break;
		G.vertices[i+1].data = data[i];
		G.vexnum++;
		printf("%c ",G.vertices[i+1].data);
	}
	
	
	printf("\n");
	
	for(int i = 0;i <= MaxNum;i++){	//�����ϵ 
		if(Edge[i][0] == NULL){
			break;
		}
	
		
	//�����ϵ 
	Insert_Edge(G,Edge[i][0],Edge[i][1]);
	Insert_Edge(G,Edge[i][1],Edge[i][0]);
	}

	
}

bool Insert_Edge(ALGraph &G,Elemtype x,Elemtype y)	//������x,y�����ı�
{
	int i,j;
	i=Search_Graph(G,x);	//��ȡ�������������ڱ��е�λ�� 
	j=Search_Graph(G,y);
	
	ArcNode *S=G.vertices[i].first;
	
	ArcNode *A=(ArcNode *)malloc(sizeof(ArcNode));
	
	A->adjvex = j;
	A->next = S->next;
	S->next = A;
	G.arcnum++;
	
} 


void BFSTraverse(ALGraph G)		//��ͼG���й�������������� 
{
	LinkQueue Q;
	for(int i = 1;i <= G.vexnum;i++){
		visited[i] = false;
	}
	
	InitQueue(Q);	//��ʼ������ 
	for(int i = 1;i <= G.vexnum;i++){
		if(!visited[i]){
			BFS(G,G.vertices[i].data,Q);
		}
	} 
} 

void BFS(ALGraph G,Elemtype v,LinkQueue &Q)	//��v������������������������
{
	int j;
	ArcNode *S;
	int i = Search_Graph(G,v);
	
	printf("%c ",G.vertices[i].data);
	visited[i] = true;
	
	
	EnQueue(Q,i);	//��v������� 
	
	while(!IsEmpty(Q)){
		j = PopQueue(Q);	//���ӣ�����ȡ���ӵ�ֵ 
		S= G.vertices[j].first->next;	//��ȡ����������ͼ�е�ָ�� 
		while(S != NULL){
			if(!visited[S->adjvex]){
				EnQueue(Q,S->adjvex);
				printf("%c ",G.vertices[S->adjvex].data);
				visited[S->adjvex] = true;
			}//if
			S = S->next; 
			
		} 
	}
	printf("\n");
} 















bool InitQueue(LinkQueue &Q){	//��ʼ������ 
	Q.front=Q.rear=(LinkNode *)malloc(sizeof(LinkNode));
	Q.front->next=NULL;
} 
bool IsEmpty(LinkQueue &Q){		//�п� 
	if(Q.front==Q.rear){
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

int PopQueue(LinkQueue &Q)		//����
{
	int x;
	if(IsEmpty(Q)){
		return false;
	}
	LinkNode *p=Q.front->next;
	x = p->data;
	Q.front->next=p->next; 
	if(p==Q.rear){
		Q.front=Q.rear;
	}
	free(p);
	return x;
} 

void DFS_Judge_Circle(ALGraph G)		//������������ж��Ƿ���ڻ�· 
{
	visited[MaxNum] = false; 
	int S[MaxNum];	//ջ�����ڴ洢������Ϣ�����б���
	int top = 0;//ջ��ָ�� 
	VNode p = G.vertices[0];//�ӵ�һ�����㿪ʼ���� 
	if(p == NULL){
		return 0;
	}
	
	
	while(p != NULL || top > 0){
		if(p != NULL){
			S[++top] = p->data;	//���ڵ���Ϣ����ջ�� 
			p=p.first->next; 
		}
		else{
			p = S[top--];
			if(visited[p->data] == true)
				return false;
			
		}
	}
}
