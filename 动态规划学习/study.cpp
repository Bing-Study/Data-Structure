#include "study.h"

int main(){
	int num[1000];
/*	for(int i = 0; i < 1000; i++){
		num[i] = rand()%1000;

	}
	
	printf("����������г���Ϊ��%d",lengthOfils(num,1000));
*/

	char A[15];
	char B[15];
	
	strcpy(A,"I'm a student");
	strcpy(B,"I'm a teacher");
	
	CompEditDistance(A,B,15,15);
}
