#include<stdio.h>

typedef int Elemtype;


void InsertSort(Elemtype A[],int n);	//ֱ�Ӳ������� 
void print(Elemtype A[],int n);			//��ӡ���� 
void ShellSort(Elemtype A[],int n);		//ϣ������
void BubbleSort(Elemtype A[],int n);	//ð������
 

void InsertSort(Elemtype A[],int n)	//ֱ�Ӳ�������
{//����λ�ô�0��ʼ 
	int i = 1,j;
	Elemtype temp; 
	for(i;i < n ;i++){
		j = i-1;		 
		if(A[i]<A[i-1]){		//�ҵ���һλ������ǰһλ����С 
			temp = A[i];
			while(A[j] > temp && j >= 0){	//�ҵ����������е�һ����tempֵС��λ�� 
				A[j+1]=A[j];		//����ڳ�һ��λ�� 
				j--;
			}
			A[j+1] = temp;		//���� 
		}
	} 
} 

void print(Elemtype A[],int n)		//��ӡ����
{
	for(int i = 0;i<n;i++){
		printf("%d  ",A[i]);
	} 
} 


void ShellSort(Elemtype A[],int n)		//ϣ������
{
	int dk;		//����ϣ����������� 
	Elemtype temp;	//������ʱ����
	int i,j; 
	for(dk = n/2;dk >= 1;dk = dk/2){
		for(i = dk;i<n;i++){
			if(A[i]<A[i-dk]){
				temp = A[i];
				for(j = i-dk;j >= 0 && temp<A[j];j-=dk)
					A[j+dk] = A[j];
				A[j+dk] =temp;
			}
			
			
		}
	}
} 

void BubbleSort(Elemtype A[],int n)		//ð������
{
	Elemtype temp;
	int i,j; 
	bool flag;	//��ʾһ���������Ƿ������� 
	for(j = n-1;j >= 0;j--){
		flag = false;
		for(i = 0;i < j;i++){	//
			if(A[i]>A[i+1]){	//���� 
				temp = A[i];
				A[i] = A[i+1];
				A[i+1] = temp;
				flag = true;
			}
		}

		if(flag == false)
			return;
	}

} 
