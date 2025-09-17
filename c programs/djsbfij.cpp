#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    long long int cases;
    scanf("%lld",&cases);
    while(cases--){
        long long int n , l , r ;
        scanf("%lld%lld%lld",&n,&l,&r);
        long long int arr[n];
        l--;
        r--;
        for(long long int i=0;i<n;i++){
            cin >> arr[i];
        }
        long long int arr2[r+1];
        for(long long int i=0;i<r+1;i++){
            arr2[i]=arr[i];
        }
        sort(arr2,arr2+(r+1));
        long long int sum1=0;
        for(long long int i=0;i<(r-l+1);i++){
             if(i>=n){break;}
            sum1+=(arr2[i]);
        }
        long long int arr3[n-l];
        long long int j=0;
        for(long long int i=l;i<n;i++){
            arr3[j]=arr[i];
            j++;
        }
        if(debug){cout << arr3[0] << arr3[1] << endl;}
        sort(arr3,arr3+(n-l));
        long long int sum2=0;
        for(long long int i=0;i<(r-l+1);i++){
            sum2+=arr3[i];
        }
        if(debug){cout << sum1 << " " << sum2 << endl;}
        if(sum1>sum2){cout << sum2 << endl;}
        else{cout << sum1 << endl;}

    }
}