#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        long long int n;
        scanf("%lld",&n);
        long long int arr[n];
        long long int sum1=0;
        long long int sum2=0;
        long long int n1=0,n2=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&arr[i]);
            if(i%2==0){sum1+=arr[i];n1++;}
            else{sum2+=arr[i];n2++;}
        }
        if(sum1%n1==0 && sum2%n2==0 && (sum1/n1)==(sum2/n2)){
            printf("YES\n");
        }
        else{
            cout <<  "NO" << endl;
        }
    }
}