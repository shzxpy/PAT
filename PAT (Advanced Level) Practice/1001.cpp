#include<cstdio>
int main(){
	int a,b,c;
	int arr[7];
	int i=0,j;
	scanf("%d%d",&a,&b);
	c=a+b;
	if(c<0){ //判断正负 
		printf("-");
		c=-c;		
	}
	if(c==0){
		arr[i++]=0;
	}
	while(c!=0){//从各位把位数传入数组 
		arr[i++]=c%10;
		c=c/10;
	} 
	for(j=i-1;j>=0;j--){//反向输出数组 
		printf("%d",arr[j]);
		if(j%3==0&&j>0){// 每三位添加"," 
			printf(",");
		}
	}
	return 0; 
}
