
#include "Sort.h"

#define Maxsize 10

Elemtype NList[Maxsize] = {50,10,30,26,18,40,43,32,90,68};

int main(){

	
	
	printf("ԭ���飺"); 
	print(NList,Maxsize);
	
	printf("\n");
	
//	printf("ֱ�Ӳ�������");
//	InsertSort(NList,Maxsize);		//ֱ�Ӳ������� 
	

//	printf("ϣ������");
//	ShellSort(NList,Maxsize);		//ϣ������

//	printf("ð������");			//ð������
//	BubbleSort(NList,Maxsize);		 

//	printf("��������:");				//�������� 
//	QuickSort(NList,0,Maxsize-1);

	printf("���ֲ�������");
	BinarySort(NList,Maxsize); 

	print(NList,Maxsize);
	return 0; 
} 
