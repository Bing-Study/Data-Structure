#include<stdio.h>

#define Maxsize 10

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

void Swap(int *a,int *b);	//���� 
void BinarySort(Elemtype A[],int n);	//���ֲ������� 
void ColorSort(int A[],int n);	//������������ 
void Heapify(int A[],int start,int end);	//�����Ѻ��� 
void HeapSort(int A[],int len);		//������ 
 

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
void ColorSort(int A[],int n)	//������������
{
	const int Red = 1,White = 2,Blue = 3;
	//1Ϊ��ɫ,2Ϊ��ɫ��3Ϊ��ɫ
	
	int Insert_Red = 0, Insert_White = 0, i;
	for(i = 0 ; i < n ; i++){
		if(A[i] == White){
			//��ǰ����Ϊ��ɫ�����ɫ�������λ�õ����������� 
			A[i] = A[Insert_White];
			A[Insert_White] = White;
			Insert_White++;
		}
		if(A[i] == Red){
			//��ǰ����Ϊ��ɫ�����ɫ�������λ�õ�����������
			//�����ɫ�������λ�õ�����������	
			A[i] = A[Insert_White];
			A[Insert_White] = A[Insert_Red];
			A[Insert_Red] = Red;
			Insert_Red++;
			Insert_White++;
		}
	}
}

void Swap(int *a,int *b)	//����
{
	int temp = *a;
	*a = *b;
	*b = temp; 
}

void Heapify(int A[],int start,int end)		//�����Ѻ��� 
{
	int dad = start;
	int son = dad * 2 + 1;
	
	
	/*********************************************
				��������� 
				�����������ε����ѵĽṹ 
	**********************************************/
//	while(son <= end){
//		//�ȱȽ������ӽڵ�Ĵ�С��ѡ�����һ�� 
//		if(son + 1 <= end && A[son] < A[son + 1])
//			son++;
//		//�����ڵ�����ӽڵ㣬����ϴ���ѣ�����ѭ�� 
//		if(A[dad] > A[son])
//			return; 
//		else{
//		//���򣬽����ڵ����� 
//			Swap(&A[dad],&A[son]);
//			dad = son;
//			son = dad * 2 + 1; 
//		} 
//	}
	
	/*********************************************
					����С���� 
			�����������ε����ѵĽṹ
			����ṹ�����ѻ���һ�� 
	**********************************************/
	while(son <= end){
		//�ȱȽ������ӽڵ�Ĵ�С��ѡ�����һ�� 
		if(son + 1 <= end && A[son] > A[son + 1])
			son++;
		//�����ڵ�����ӽڵ㣬����ϴ���ѣ�����ѭ�� 
		if(A[dad] < A[son])
			return; 
		else{
		//���򣬽����ڵ����� 
			Swap(&A[dad],&A[son]);
			dad = son;
			son = dad * 2 + 1; 
		} 
	}

	
}

void HeapSort(int A[],int len)		//������
{
	int i;
	
	/*
		��������ѣ������д���ѵĶ����� 
	*/
	for(i = (len / 2) - 1; i >= 0; i--){
		//�����һ�������ӽڵ�Ľڵ�������Ͽ�ʼ�����ѵĽṹ 
		Heapify(A,i,len-1);	
	} 
	
	//������һ���,���ֵ�ڶѵĶ���,��λ��A[0]��
	//����һ��λ�ã������źõ�λ�������һλ����
	//�����½������� 
	for(i = len - 1; i > 0; i--){
		Swap(&A[0],&A[i]);
		//���ڴ�����ѽ������
		//�ڽ��������ݺ�ֻ������һλ���ݲ����ϴ����Ҫ��
		//��������ĶѶ�Ԫ�أ��ڵ���һ�ζѼ���
		//����λ�ô�0��ʼ(�Ѷ�)�� 
		Heapify(A,0,i-1);
		

	} 
}
