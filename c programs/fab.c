#include<stdio.h>
int main()
{
    long long int n;
    scanf("%lld",&n);
    int t = 1000;
    while(t){
        
    long long int sum;
    long long int x;
   long long int y;
    long long int z;
    x=1;
    y=1;
    if(n==1){printf("1\n");}
    if(n==2){printf("1\n");}
    for(int i=1;i<=n-2;i++){
        sum=y+x;
        x=y;
        y=sum;
    }
    if(n>2){printf("%lld\n",sum);}
        t--;
    }
    return 0;
}