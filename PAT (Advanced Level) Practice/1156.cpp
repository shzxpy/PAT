#include<cstdio>
#include<cmath>
bool isprime(int x){//判断是否质数 
	if(x<2){
		return 0;
	}
	if(x>2){
		for(int i=3;i<=sqrt(x);){
			if(x%i==0){
				return 0;
			}
			i+=2;	
		}
	}
	return 1;
}
bool issexy(int x){//判断是否是sexyprime 
	if(isprime(x+6)||isprime(x-6)){
		return 1;
	}
	return 0;
}
int main(){
	int a,b,c;
	scanf("%d",&a);
	b=a-6;
	c=a+6;
	if(issexy(a)){
		printf("Yes\n");
		if(isprime(b)){
			printf("%d",b);
		}else{
			printf("%d",c);
		}
	}else{
		printf("No\n");
		for(int i=a+1;;i++){
			if(issexy(i)){
				printf("%d",i);
				break;
			}
		}
	}
	return 0;
} 
