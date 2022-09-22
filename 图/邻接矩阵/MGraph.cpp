#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 5	//������Ŀ�����ֵ 

typedef char VertexType;	// ������������� 
typedef int EdgeType;		//��Ȩͼ��Ȩֵ����������

typedef struct {
	VertexType Vex[MaxVertexNum];	//�����
	EdgeType Edge[MaxVertexNum][MaxVertexNum];	//�߱�
	int vexnum,arcnum; 	//��ǰͼ�Ķ������ͻ��� 
}MGraph;

bool InitGraph(MGraph &M);	//��ʼ��ͼ 
bool Insert(MGraph &M,VertexType x,int type);	//���� 
bool Creat_Graph(MGraph &M);	//����ͼ 

int main(){
	return 0;
} 
bool InitGraph(MGraph &M)	//��ʼ��ͼ 
{
	for(int i = 0;i < MaxVertexNum;i++){
		M.Vex[i] = NULL;
		for(int j = 0;j < MaxVertexNum;j++){
			M.Edge[i][j] = 0;
		}
	}
	return true;
}

bool Insert(MGraph &M,VertexType x,int type)	//����
{
	if(M.Vex[MaxVertexNum] != NULL){
		printf("ͼ������\n");
		return false;
	}
	int i = 1; 
	int j = 1;	
	VertexType m;	//���¶����б������Ķ���
	while(M.Vex[i] != NULL){	//��λ��һ��û�д洢�����λ�ã����ڴ洢�¶��� 
		i++;
	}	
	M.Vex[i] = x;
	switch(type){
	case 1:
		// 1.����ͼ
		printf("������ö�������ӵĶ���:");
		scanf("%c%*c",&m);
		while(m != 'z'){
			
			while(M.Vex[j] != m || j < i){	//��λ���� 
				j++;
			}
		
			if(j >= i){
				printf("ͼ��û�д˶���!\n");
				return false;
			}
			M.Edge[i][j] = M.Edge[j][i] = 1;	//���߸�ֵ 
			printf("��������һ����ö��������ӵĶ���:");
			scanf("%c%*c",&m);
		} 
		break;
		
		//����ͼ 
		case 2:
			printf("������ö���Ļ�β:");
			scanf("%c%*c",&m);
			while(m != 'z'){				
				while(M.Vex[j] != m || j < i){	//��λ���� 
					j++;
				}
				M.Edge[i][j] = 1; 		
				printf("��������һ���ö���Ļ�β:");
				scanf("%c%*c",&m);
			} 
			
			printf("�������Ըö���Ϊ��β�Ķ���:"); 
			scanf("%c%*c",&m);
			
			while(m != 'z'){
				while(M.Vex[j] != m || j < i){	//��λ���� 
					j++;
				}
				M.Edge[j][i] = 1; 
				printf("��������һ��");
				scanf("%c%*c",&m);
			}
			break;
	}
} 

bool Creat_Graph(MGraph &M)	//����ͼ 
{
	//1.��������ͼ
	VertexType x;	//�¶��� 
	while(x != 'z' || M.Vex[MaxVertexNum] == NULL){
		printf("�������¶����ֵ");
		scanf("%c%*c",&x); 	
		Insert(M,x,1);
	}
	return true;
	
	return true;
} 
