#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    long long int cases;
    scanf("%lld",&cases);
    while(cases--){
        long long int n;
        scanf("%lld",&n);
        long long int arr[n];
        long long int count=0;
        for(long long int i=0;i<n;i++){
            scanf("%lld",&arr[i]);
            if(arr[i]>0){count++;}
        }
            long long int ans1=0;
            long long int ans2=0;
            long long int i=0;
            if(count==0){
                int max=arr[0];
                for(int j=1;j<n;j++){
                    if(max<arr[j]){max=arr[j];}
                }
                printf("%d\n",max);
            }
            else{
            while(i<n){
                if(arr[i]>0){ans1+=arr[i];}
                i+=2;
            }
            i=1;
            while(i<n){
                if(arr[i]>0){ans2+=arr[i];}
                i+=2;
            }
            if(ans1>ans2){printf("%lld\n",ans1);}
            else{printf("%lld\n",ans2);}
            }
    }
}
