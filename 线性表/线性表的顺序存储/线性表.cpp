#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20
typedef int Elemtype ;

typedef struct {
	Elemtype data[MaxSize];		//����һ������λMaxSize�ı� 
	int length;					//���Ա�ĵ�ǰ���� 
}SqList;


bool InitList(SqList &L);				//��ʼ�����Ա� 
bool ListInsert(SqList &L,int i,Elemtype e);	//��i��λ�ò���Ԫ��e 
bool ListDelet(SqList &L,int i);	// ɾ����i��Ԫ�أ�����Ԫ����e����
int LocateElem(SqList L,Elemtype e);			//����Ԫ��e��������λ�á�
void print(SqList);		//��ӡ��ǰ�� 
void ListSort(SqList &L);	//�����㷨 
Elemtype yi(SqList &L);		//22����17ҳ ����1 �� ɾ����СԪ�أ������һλԪ�ز��ա� 
int er(SqList &L);			//22����17ҳ ����2 ��	��Ԫ�����ã��ҿռ临�Ӷ�ΪO(1)
int san(SqList &L,int x);	//22����17ҳ ����3 �� ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1),ɾ������ֵΪx��Ԫ�� 
int si(SqList &L,int s,int l);	//22����17ҳ ����4 �� ����˳���ɾ��ֵ�ڸ���ֵs-l֮�������Ԫ��
int liu(SqList &L);			//17ҳ����6�⣬ɾ��˳����������ظ���Ԫ�ء�
int shi(SqList &L,int p);	//��L�б��������ѭ�������ƶ�p��λ�� ʱ��Ϳռ価���ܸ�Ч�� 
int shiyi(SqList S1,SqList S2);//17ҳ��11�⣬����������S1��S2,Ѱ��S1��S2�ϲ������λ������λ��Ϊlength/2λ�õ��� 
int main(){
	SqList L;
	int e=-1;
	int j;
	int place;
	if(!InitList(L))
		{
			printf("Init LIst false!\n");
			return 0;
		}
	printf("Init success!\n");
	
	for(int i=0,locate=0;i<6;i++,locate+=6){		//��ǰ5�����ݸ�ֵ 
//		printf("please input your data L1:");
//		scanf("%d",&j);
		ListInsert(L,i,locate);	
	}
	print(L); 
	
//	ListInsert(L,3,20);				//�ڵ�8λ��������20 
//	ListInsert(L,80,20);			//���ԷǷ�λ�� 
	
/*	print(L)*/
	
//	ListDelet(L,8,e);				//ɾ����8λ�����ݲ�ʹ��e���� 
//	printf("%d\n",e);
	
	 
//	print(L);
	
//	place=LocateElem(L,0);			//��ȡҪ���ҵ����ݵ�λ�� 
//	if(place==0)
//		printf("The list dont have this data\n"); 
//	else
//		printf("%d\n",place);
			
//	printf("��һ�⣺%d\n",yi(L));		//22����17ҳ ����1 �� 
//	er(L);			//22����17ҳ ����2 �� 
//	print(L);
	
//	san(L,3);
//	print(L);	
	
//	//������
//	int s,l;
//	printf("input:");
//	scanf("%d%d",&s,&l); 
//	si(L,s,l);


//	//������
//	liu(L); 
//	print(L);


//	//��ʮ��
//	int p;
//	printf("p:");
//	scanf("%d",&p);
//	shi(L,p);
//	print(L); 


//	���� 
//	
//	ListSort(L);
//	print(L); 

//��11��
	SqList L2;
	InitList(L2); 
	for(int i=0,locate=8;i<6;i++,locate+=3){		//��ǰ5�����ݸ�ֵ 
//		printf("please input your data L2:");
//		scanf("%d",&j);
		ListInsert(L2,i,locate);	
	}
	print(L2); 

	shiyi(L,L2);
	


	return 0;





} 








bool InitList(SqList &L)				//��ʼ�����Ա� 
{
	for(int i;i<MaxSize;i++)
	{
		L.data[i]=0;
	}
	L.length=0;
	return true;
} 
bool ListInsert(SqList &L,int i,Elemtype e)		//��i��λ�ò���Ԫ��e 
{
	 if(i<0||i>MaxSize){		//�ж�λ���Ƿ�Ϸ� 
	 	printf("The place was false!\nInsert false!\n");
	 	return false;
	 }
	 if(L.length==MaxSize){		//�ж����Ա�ǰ�Ƿ����� 
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
bool ListDelet(SqList &L,int i)		// ɾ����i��Ԫ�أ�����Ԫ����e����
{
	if(i<0||i>MaxSize){
	 	printf("The place was false!\n");
	 	return false;
	 }
	for(int j=i;j<MaxSize;j++){
	 	L.data[j]=L.data[j+1];
	 }
	L.length--;
	return true;
} 
int LocateElem(SqList L,Elemtype e)				//����Ԫ��e��������λ�á�
{
	int i=0;
	for(int i=0;i<L.length;i++){
		if(L.data[i]==e)
			return i+1;		//λ�ô�0��ʼ���㣬���Է���ֵ��1���൱��λ�ô�1��ʼ���� 
							//���ڹ۲� 
	}
	i=0;
	return i; 
		
} 

void print(SqList L)			//��ӡ��ǰ���Ա�
{
	for(int i=0;i<L.length;i++){	//��ӡ��ǰ���Ա� 
		printf("%d   ",L.data[i]);	
	}
	printf("\n");

} 

//	1.��˳�����ɾ��������Сֵ��Ԫ�أ����ɺ������ر�ɾԪ�ص�ֵ���ճ���λ��
//	   �����һ��Ԫ�������˳���Ϊ�գ�����ʾ������Ϣ���Ƴ����С�

Elemtype yi(SqList &L){		//22����17ҳ ����1 ��
	if(L.length==0){
		printf("The list is empty!\n");
		exit(0);
	}
	
	Elemtype min=L.data[0];
	for(int i=0;i<L.length;i++){
		if(min>L.data[i]){
			min=L.data[i];
		}
	}
	return min; 
}
 

int er(SqList &L)			//22����17ҳ ����2 ��	��Ԫ�����ã��ҿռ临�Ӷ�ΪO(1)
{
	Elemtype x;
	for(int i=0;i<L.length/2;i++){
		x=L.data[i],L.data[i]=L.data[L.length-i-1],L.data[L.length-i-1]=x;
	}
	return 0;
}

int san(SqList &L,int x)	//ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1),ɾ������ֵΪx��Ԫ��
{
	int k=0;;
	for(int i=0;i<L.length;i++){
//		if(L.data[i]==x){		//����ʱ�临�Ӷ�ΪO(n^2),ListDelt�ĸ��Ӷ�ҲΪn 
//			ListDelet(L,i,e);	//��ʱ�临�ӶȲ�������ĿҪ�� 
//			i--;
//		}
		if(L.data[i]!=x){
			L.data[k]=L.data[i];
			k++;
		}
	}
	L.length=k;
	return 0; 
} 

int si(SqList &L,int s,int l)	//22����17ҳ ����4 �� 
//								����˳���ɾ��ֵ�ڸ���ֵs-l֮�������Ԫ��
{
	int i=0,j=0;
	if(s>l){
		printf("the data is illegal!\n");
		return 0;	
	}		
	i=LocateElem(L,s);	//��λs�� 
	j=i+(l-s);			//����s��λ�ö�λl��λ�á� 
	if(i==0){
		printf("the list dont have this data!\n");
		return 0;
	}  
	for(i=i-1;i<L.length;i++){
		L.data[i]=L.data[j];
		j++;
	}
	L.length=L.length-(l-s)-1; 
}

int liu(SqList &L){			//17ҳ����6�⣬ɾ��˳����������ظ���Ԫ�ء�
	Elemtype temp; 
	for(int i=0;i<L.length;i++){
		temp=L.data[i];
		for(int j=i+1;j<L.length;j++){
				
			if(temp==L.data[j])		 
				ListDelet(L,j),j--;
				/*ɾ����һ�����ݺ��������ݻ�ǰ��һλ
				 ��j��ָ���λ��Ҳ��ǰ��һλ
				 ���轫j-1; 
				 */ 
		}
	} 
	return 0;
} 

int shi(SqList &L,int p)	//��L�б��������ѭ�������ƶ�p��λ�ã�ʱ��Ϳռ価���ܸ�Ч 
{
//	Elemtype temp; 		//����һ�������� 
//	//ѭ�������ơ�ʱ�临�Ӷ�O(n*p),�ռ临�Ӷ�O(1)
//	//������p�Σ���������n-p�Ρ� 
//	for(int i=0;i<p;i++){
//		
//		for(int j=0;j<L.length-1;j++){
//			temp=L.data[j];
//			L.data[j]=L.data[(j+1)%L.length];
//			L.data[(j+1)%L.length]=temp; 
//		}
//		print(L);
//	}
//	 printf("\n");



	SqList temp;	//����һ�������Ա�һ�����Ļ������� 
	InitList(temp);
	
	temp=L;		//��ֵ
	/*����˼�룺�����Ա�ֵ�����������ӻ�������ֱ�ӻ�ȡ���ݸ�ֵ��
	L�У�ʹ��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(n); */
	
	for(int i=0;i<L.length;i++){
			L.data[(i+p)%L.length]=temp.data[i];

	}	
}

Elemtype shiyi(SqList S1,SqList S2){
	//17ҳ��11�⣬����������S1��S2,Ѱ��S1��S2�ϲ������λ��
	//��λ��Ϊlength/2λ�õ��� Ҫ���㷨������Ч
	ListSort(S1);
	ListSort(S2); 
	int L1,L2,L;
	L1=S1.length;
	L2=S2.length;
	L=(L1+L2)/2;
	L1=0;L2=0; 
	Elemtype temp;
	for(int i=0;i<L;i++){
		if(S1.data[L1]<=S2.data[L2]){
			temp=S1.data[L1];
			L1++;
		}
		else{ 
			temp=S2.data[L2];
			L2++; 
			} 
	} 
	 
	 
	printf("%d\n",temp);
	
} 
void ListSort(SqList &L)	//�����㷨
{
	Elemtype temp;
	for(int i=0;i<L.length;i++){
		for(int j=L.length-1;j>i-1;j--){
			if(L.data[j]<L.data[j-1]){
				temp=L.data[j];
				L.data[j]=L.data[j-1];
				L.data[j-1]=temp;
			}
		}
	}
} 
