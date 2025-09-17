#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        int n,k;
        scanf("%d%d",&n,&k);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
            arr[i]+=(i+1);
        }
        sort(arr,arr+n);
        int count=0;
        int j=0;
        while(j<n && k>=0){
            k-=arr[j];
            j++;
            count++;
        }
        if(j!=n){count--;}
        else{if(k<0){count--;}}
        printf("%d\n",count);
    }
}