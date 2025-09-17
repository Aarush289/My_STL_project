#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    scanf("%lld",&n);
    long long int low=0;
    long long int high;
    if(n>1000000){ high=1000000;}
    else{  high=n;}
     long long int mid;
     long long int flag=0;
    while(low<high){
            mid=(low+high)/2;
            if((mid*mid*mid)==n){flag=1;break;}
            else{
                if((mid*mid*mid)>n){high=mid;}
                else{low=mid+1;}
            }
            }
            if(n==1 || n==1000000000000000000){flag=1;}
            if(flag==0){printf("Not a perfect cube \n");}
            else{ printf("Yes , perfect cube \n",mid);}
}