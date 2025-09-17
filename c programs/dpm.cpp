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
        }
        int count[k];
          int arr1[k];
        int arr2[k];
        for(int i=0;i<k;i++){
            count[i]=0;
            arr1[i]=0;
            arr2[i]=0;
        }

        for(int i=0;i<n;i++){
            count[arr[i]-1]++;
        }
       for(int i=0;i<k;i++){
            if(count[i]==0){printf("0 ");continue;}
            int j=0;
            int p=n-1;
            while(arr[j]<(i+1)){j++;}
            while(arr[p]<(1+i)){p--;}
            printf("%d ",(p-j+1)*2);
       }
       printf("\n");
    }
}