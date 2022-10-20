#include<stdio.h>
#include <stdlib.h>


#define Maxsize 10
typedef int Elemtype ;

typedef struct {
	Elemtype data[Maxsize];		//����һ������λMaxSize�ı� 
	int length;					//���Ա�ĵ�ǰ���� 
}SqList;

bool InitList(SqList &L);				//��ʼ�����Ա� 
bool ListInsert(SqList &L,int i,Elemtype e);	//��i��λ�ò���Ԫ��e
bool CreatList(SqList &L);		//�������Ա� 
int Binary_Search(SqList L,Elemtype x);	//�۰���� 


int main(){
	SqList L;
	InitList(L);
	
	CreatList(L);
	printf("find :%d",Binary_Search(L,8));
	return 0; 
}


bool InitList(SqList &L)				//��ʼ�����Ա� 
{
	for(int i;i<Maxsize;i++)
	{
		L.data[i]=0;
	}
	L.length=0;
	return true;
} 

bool ListInsert(SqList &L,int i,Elemtype e)		//��i��λ�ò���Ԫ��e 
{
	 if(i<0||i>Maxsize){		//�ж�λ���Ƿ�Ϸ� 
	 	printf("The place was false!\nInsert false!\n");
	 	return false;
	 }
	 if(L.length==Maxsize){		//�ж����Ա�ǰ�Ƿ����� 
	 	printf("List has full!\n");
	 	return false;
	 } 
	 for(int j=L.length;j>=i;j--){		//������� 
	 	L.data[j+1]=L.data[j];
	 }
	 L.data[i]=e;
	 L.length++;
	 return true;
	 
} 

bool CreatList(SqList &L)		//�������Ա� 
{
	int temp[Maxsize] = {2,6,10,18,30,35,48,56,68,77};
	for(int i=0;i<Maxsize;i++){
		ListInsert(L,i,temp[i]);
	}
} 

int Binary_Search(SqList L,Elemtype x)	//�۰���� 
{
	int i=0;
	int low = 0,high = L.length - 1;
	
	while(low<=high){
		i++;
		printf("%d");
		int mid = (low + high)/2;
		if(x>L.data[mid]){
			low = mid + 1;
		}
		else if(x<L.data[mid]){
			high = mid - 1;
		}
		else if (x == L.data[mid])
			return mid;
	}
	printf(" i = %d",i);
	return Maxsize;
	
} 
