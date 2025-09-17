#include<stdio.h>
long long power(int a,int b,int p){
	long long ans=1;
	long long base=a;
	while(b>0){
		if(b%2!=0){
			ans=(ans*base)%p;
			b-=1;
		}
		else{
			base=(base*base)%p;
			b/=2;
		}
	} 
	return ans;
}
long long modInverse(int a,int p){			
	return power(a,p-2,p);
}	
int main(){

	int a,p;
	scanf("%d%d",&a,&p);
	long long result;
	result=modInverse(a,p);
	printf("%lld\n",result);



return 0;
}

