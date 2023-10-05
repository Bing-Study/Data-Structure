#include<stdio.h>

typedef int Elemtype;


/***************************************
		�����±��0��ʼ
***************************************/ 

void InsertSort(Elemtype A[],int n);	//ֱ�Ӳ������� 
void print(Elemtype A[],int n);			//��ӡ���� 
void ShellSort(Elemtype A[],int n);		//ϣ������
void BubbleSort(Elemtype A[],int n);	//ð������
void QuickSort(Elemtype A[],int low,int high);	//��������
int Partition(Elemtype A[],int low,int high);	//���������һ�˻��� 

void BinarySort(Elemtype A[],int n);	//���ֲ������� 
 

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

void QuickSort(Elemtype A[],int low,int high)	//��������
{//����:Aλ����,lowΪ�����һ��λ��,highΪ�������һ��λ�� 
	if(low<high){
		int pivotpos = Partition(A,low,high);	//����
		QuickSort(A,low,pivotpos-1);
		QuickSort(A,pivotpos+1,high);
	} 
} 
int Partition(Elemtype A[],int low,int high)	//���������һ�˻��� 
{
	Elemtype pivot = A[low];
	while(low<high){
		while(pivot <= A[high] && low < high){//���piovt��ֵ����A[high]λ���ϵ�ֵ	
			high-=1;							//��˵����highλ���ϵ�ֵӦ����pivot֮ǰ��
		}
		A[low] = A[high];				//��A[high]�����ݷŵ�low��λ����
		while(pivot >= A[low] && low < high){
			low+=1;
		}
		A[high] = A[low];
	}
	A[low] = pivot;	//ѭ��������lowλ�õ�ֵ����pivot����λ�� 
	return low;		//����low��ֵ��������λ�����ӱ� 
} 

void BinarySort(Elemtype A[],int n)	//���ֲ������� 
{
	int low,high,mid; 
	int temp;		//��ʱ�������洢������ؼ��֡�
	
	for(int i = 1;i < n;i++){	//�������� 
		low = 0;
		high = i-1;
		temp = A[i]; //��¼�ùؼ��֣���ֹ�ؼ��ֲ�����Ƶ��¹ؼ�����ʧ��
		
		while(low <= high){
			mid = (low + high) / 2;
			if(A[mid] > temp){
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		
		for(int j = i - 1;j >= low;j--){
			A[j+1] = A[j];
		}
		A[low] = temp;
	} 
}
