
#include "Sort.h"



//�������� 
Elemtype NList[Maxsize] = {50,10,30,26,18,40,43,32,90,68};

int main(){

	//���������������� ,1Ϊ��ɫ,2Ϊ��ɫ��3Ϊ��ɫ 	
	int Color[9] = {3,1,2,3,1,3,2,1,2};		
	
	
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

//	printf("���ֲ�������");
//	BinarySort(NList,Maxsize); 

//	ColorSort(Color,9);

	HeapSort(NList,Maxsize); 

	printf("�����"); 
	print(NList,Maxsize);	//���� 
	return 0; 
} 
