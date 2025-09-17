#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int cases;
    scanf("%lld",&cases);
    for(long long int i=0;i<cases;i++){
         long long int n;
        scanf("%lld",&n);
         long long int arr[n];
         long long int count[n];
        for(long long int j=0;j<n;j++){
            count[j]=0;
            scanf("%lld",&arr[j]);
            arr[j]=arr[j]-j;
                   }
        sort(arr,arr+n);
         long long int num=arr[0];
        long long int j=0;
        for(long long int i=0;i<n;i++){
            if(arr[i]==num){count[j]++;}
            else{num=arr[i];count[++j]++;}
        }
        sort(count,count+n);
        long long int m=n-1;
        long long int answer=0;
        while(m>=0){
            answer+=((count[m]*(count[m]-1))/2);
            m--;
        }
        printf("%lld\n",answer);
        
    }
}