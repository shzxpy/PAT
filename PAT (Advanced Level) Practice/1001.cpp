#include<cstdio>
int main(){
	int a,b,c;
	int arr[7];
	int i=0,j;
	scanf("%d%d",&a,&b);
	c=a+b;
	if(c<0){ //�ж����� 
		printf("-");
		c=-c;		
	}
	if(c==0){
		arr[i++]=0;
	}
	while(c!=0){//�Ӹ�λ��λ���������� 
		arr[i++]=c%10;
		c=c/10;
	} 
	for(j=i-1;j>=0;j--){//����������� 
		printf("%d",arr[j]);
		if(j%3==0&&j>0){// ÿ��λ���"," 
			printf(",");
		}
	}
	return 0; 
}
