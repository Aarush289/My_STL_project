#include<bits/stdc++.h>
using namespace std;
int main(){
   int cases;
   scanf("%d",&cases);
   while(cases--){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        int count[n];
            for(int j=0;j<n;j++){
                count[j]=j;
                for(int i=j+1;i<n;i++){
                        if(arr[i]>arr[j]){count[j]++;}
                }
            }
            int min=count[0];
            for(int i=1;i<n;i++){
                    if(min>count[i]){min=count[i];}
            }
            printf("%d\n",min);
   }
}