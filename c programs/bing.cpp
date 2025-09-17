#include<bits/stdc++.h>
using namespace std;
# define debug 0
int main() {
   long long int k,n;
    scanf("%lld%lld",&k,&n);
   long long int arr[n];
   long long int sum=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        sum+=arr[i];
    }
    sort(arr,arr+n);
   long long int m=(sum/k);
    while(arr[n-1]>m){
       long long int i=(n-1);
        while(arr[i]>m){
            sum-=(arr[i]-m);
            arr[i]=m;
            i--;
        }
        m=(sum/k);
    }
        printf("%lld\n",m);
}