#include<bits/stdc++.h>
using namespace std;
int main(){
   int cases;
   scanf("%d",&cases);
   while(cases--){
        long long int n,k;
        scanf("%lld%lld",&n,&k);
        long long int sum[k];
        long long int flag=0;
        long long int dif1;
        long long int dif2;
        scanf("%lld",&sum[0]);
        if(n==k){
         for(long long int i=1;i<k;i++){
            scanf("%lld",&sum[i]);
             if(i==1){dif1=sum[0];dif2=sum[i]-sum[i-1];}
             else{dif1=dif2;dif2=sum[i]-sum[i-1];}
             if(dif2<dif1){flag=1;}
         }
        }
        else{
            for(long long int i=1;i<k;i++){
            scanf("%lld",&sum[i]); 
             if(i==1){dif1=sum[0];dif2=sum[i]-sum[i-1];}
             else{dif1=dif2;dif2=sum[i]-sum[i-1];}
             if(dif2<dif1 && i!=1){flag=1;}
         }
         if(sum[0]>((n-k+1)*(sum[1]-sum[0]))){flag=1;}
        }
        if(k==1){flag=0;}
         if(flag==1){printf("No\n");}
         else{printf("Yes\n");}
   }
}