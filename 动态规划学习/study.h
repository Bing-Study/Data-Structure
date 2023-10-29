#include<stdio.h> 
#include<stdlib.h>
#include <string.h>


int lengthOfils(int num[],int n);		//�����������������г���(��̬�滮��)

int getmax(int a,int b);		//�����ֵ 
int getmin(int a,int b,int c);	//��������Сֵ 

//int CompEditDistance(char *A,char *B,int m,int n);	//����С�༭���루��̬�滮���� 

int lengthOfils(int num[],int n)		//�����������������г���(��̬�滮��)
{
	int dp[n];
	int max = 1;
	for(int i = n-1; i >= 0; i--){
		dp[i] = 1;
		for(int j = i+1; j < n; j++){
			if(num[j] > num[i]){
				dp[i] = getmax(dp[i],dp[j]+1);
			}
		}		
		if(max < dp[i])
			max = dp[i];
		
	} 
	
	return max;

 }
 
 
int getmax(int a,int b)		//�����ֵ
{
 	if(a > b)
		return a;
	else 
		return b; 
} 


// ����Щ��bugδ���� 

//int CompEditDistance(char *A,char *B,int m,int n)	//����С�༭���루��̬�滮����
//{
//	/***********************************************
//		(1)ɾ�� ����Ϊ1 
//		(2)�滻 ����Ϊ1 
//		(3)���� ����Ϊ0
//		(4)����һ���ַ� 
//	************************************************/
//
//	int dp[m][n];
//	//������dp[i][j]��ʾΪA[i-1]��B[j-1]�����ַ�֮��ı༭���� 
//	int t;
//	for(int i = 1; i < m; i++)
//		dp[i][0] = i;
//	for(int j = 1; j < n; j++)
//		dp[0][j] = 0;
//		
//	for(int i = 1; i < m; i++){
//		for(int j = 1; j < n; j++){
//			t = (A[i] == B[j]) ? 0 : 1;
//			dp[i][j] = getmin(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1])+1;
//		}
//	} 
//	
//	for(int i = 1; i < m; i++){
//		for(int j = 1; j < n; j++)
//			printf("%2d ",dp[i][j]);
//		
//		printf("\n");
//	}
//		printf("\n");
//		printf("\n");
//		printf("\n");
//		printf("\n");
//}


int getmin(int a,int b,int c)	//��������Сֵ
{
	int min;
	if(a > b)
		min = b;
	else min = a;
	if(min > c)
		min = c;
	return min; 
}
	
