#include<cstdio>
int main(){
	int num,exp,count;
	double coe;
	double arr[1001]={};
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d %lf",&exp,&coe);
		arr[exp]+=coe;
	}
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d %lf",&exp,&coe);
		arr[exp]+=coe;
	}
	for(int i=0;i<1001;i++){
		if(arr[i]!=0){
			count++;
		}
	}
	printf("%d",count);
	for(int i=1000;i>=0;i--){
		if(arr[i]!=0){
			printf(" %d %0.1f",i,arr[i]);//保留1位小数 
		}
	}
	return 0;
} 
