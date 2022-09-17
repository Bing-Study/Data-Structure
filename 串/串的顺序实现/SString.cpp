#include <stdio.h>
#include <string.h>
#define Maxsize 255

typedef char Elemtype;

typedef struct {
	Elemtype data[Maxsize];
	int length;
}SString;


bool InitStr(SString &T);	//��ʼ���� 
bool StrAssign(SString &T,char *s); //���ַ���s��ֵ��T
bool PrintStr(SString T);	//��ӡ�ַ��� 
bool StrEmpty(SString T);	//�п� 
int StrCompare(SString &S,SString &T);	//�Ƚ�S,T�Ĵ�С; >0ΪS�� <0ΪT�� =0Ϊ��ͬ�� 
int StrLength(SString S);	//�󴮳� 
int SubStr(SString S,char *arr);	//���Ӵ� 
void getnext(int *next);	//��KMP�㷨��next���� 
int KmpStr(SString &S,SString &T);	//KMP�㷨���Ӵ� 


int main(){
	SString S,T,s; 
	InitStr(S);
	InitStr(T);
	InitStr(s);
	char s1[9]="Abing123";
	char s2[9]="Abing123";
	char s3[7]="bing"; 
	printf("s1:%s\n",s1);
	StrAssign(S,s1);
	StrAssign(T,s2);
	StrAssign(s,s3);
/*	printf("T:");
	PrintStr(T);*/
	
	printf("s3:");
	PrintStr(s);


//	printf("Compare result:%d\n",StrCompare(T,S));

//	printf("strlen:%d  StrLength:%d\n",strlen(S.data),StrLength(S));


/*
	���Ӵ� 
*/
//����ģʽ�㷨 
//	printf("s3 situate:%d",	SubStr(S,s3));

/*
	KMP�㷨 
*/ 
	printf("s3 situate:%d",	KmpStr(S,s));
	return 0;
}

bool InitStr(SString &T){	//��ʼ���� 
	T.length=0; 
} 
bool StrAssign(SString &T,char *s) //���ַ���s��ֵ��T 
{
	int i=1;
	int len=strlen(s);
	for(i=1;i<=len;i++,T.length++)
	{
		T.data[T.length]=s[i-1];
	}
	T.data[T.length]='\0';

} 

bool PrintStr(SString T)	//��ӡ�ַ��� 
{
	if(StrEmpty(T)){
		printf("The String is NULL!\n");
		return false;
	}
	printf("%s",T.data);
	printf("\n");
	
} 
bool StrEmpty(SString T)	//�п� 
{
	if(T.length==0){
		return true;
	}
	else
		return false;
} 
int StrCompare(SString &S,SString &T)	//�Ƚ�S,T�Ĵ�С; >0ΪS�� <0ΪT�� =0Ϊ��ͬ�� 
{
	int i=0;
	if(S.length>T.length)
		return 1;
	else if(S.length<T.length)
		return -1;
	else{
		while(S.data[i]){
			if(S.data[i]<T.data[i])
				return 1;
			else if(S.data[i]>T.data[i])
				return -1;
			i++;
			}
		}
	return 0;
		
	}

int StrLength(SString S)	//�󴮳� 
{
	int i=0;
	while(S.data[i]){
		i++;
	}
		
	return i;
} 
int SubStr(SString S,char *arr)	//ģʽƥ�����Ӵ�
{
	int i=0;	//S��ǰƥ��λ�õ�ָ�� 
	int j=0;	//arr��ָ�� 
	int k=0;	// S��arrƥ���ָ�� 
	int x=S.length+1-strlen(arr);  //ƥ����� 
	for(i=0;i<x;i++){
		if(S.data[i+k]==arr[j]){
			printf("S.data[i+k]:%c arr[j]:%c\n",S.data[i+k],arr[j]);
			k++;
			j++;
			i--;	//��ѭ����,�Ա�һ��i+1,�����������ʱ,��i-1����ƥ�� 
		}
		else{
			k=0;
			j=0;
		}
		if(arr[j]=='\0'){
			return ++i;
		}
	}
	return -1;
} 

void getnext(SString S,int *next){	//��KMP�㷨��next���� 
	int i=1,j=0;
	next[1]=0;
	while(i<S.length){
		if(j == 0 || S.data[i]==S.data[j]){
			++i;
			++j;
			next[i]=j;
		}
		else{
			j = next[j];
		}
	}
	for(i=0;i<=S.length;i++){
		printf("i:%d   next[i]:%d\n",i,next[i]);
	} 
}

int KmpStr(SString &S,SString &T){	//KMP�㷨���Ӵ� 
	int next[T.length];
	int i=1,j=1;
	getnext(T,next);
	
	while(i<=S.length && j<=T.length){
		if(j == 0 || S.data[i] == T.data[j]){
			i++;
			j++;
		}
		else{
			j=next[j];
		}
		if(j>T.length){
			printf("i:%d  T.length:%d\n",i,T.length);
			return i-T.length;
		}
	}
	return -1;
}
