#include<bits/stdc++.h>
using namespace std;


long long int findGcd(long long int n,long long int m){
     if(n<m)
        {long long int temp=m;
        m=n;
        n=temp;
        }
    while(n%m!=0){
        n=n-m;
        if(n<m)
        {long long int temp=m;
        m=n;
        n=temp;
        }
    }
    return m;
}



 int main(){
    long long int n,d,e;
    scanf("%lld%lld%lld",&n,&d,&e);
    long long int r;
    long long int product=(e*d)-1;
    while(product%2==0){
        product/=2;
    }
    r=product;
    long long int factor1;
    long long int factor2;
    long long int flag1=0;
    for(long long int w=2;w<n-1;w++){
        if(findGcd(w,n)!=1){continue;}
        long long int m=pow(w,r);
        long long int temp=pow(w,r);
        long long int flag=0;
        if(m%n==1 || m%n==n-1){
            continue;
        }
         while(1){
       long long int temp2=temp;
        temp=temp*temp;
        if(temp%n==1){
            flag=1,
            factor1=findGcd(temp2-1,n);
            factor2=findGcd(temp2+1,n);
            if(factor1!=1 && factor2!=1){flag1=1;}
        }
        if(flag==1){break;}
         }
         if(flag1==1){break;}
    }
    if(flag1==1){printf("factors are %lld and %lld\n",factor1,factor2);}
    else{printf("Not found\n");}
}