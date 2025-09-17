#include<bits/stdc++.h>
using namespace std;
# define debug 0
int main() {
    long long int n;
    long long int m;
    long long int k;
    scanf("%lld%lld%lld",&n,&m,&k);
    long long int arr[k];
    for(long long int i=0;i<k;i++){
        arr[i]=0;
    }
    int flag=0;
    for(long long int i=0;i<n;i++){
        for(long long int j=0;j<m;j++){
            if((((i+1)*(j+1))-1)>=(k)){flag=1;break;}
            arr[((i+1)*(j+1))-1]++;
        } 
      if(i>=k){break;}
    }
    long long int sum=0;
    long long int i=0;
    while(sum<k){
        sum+=arr[i];
        i++;
    }
    printf("%lld\n",i);
}