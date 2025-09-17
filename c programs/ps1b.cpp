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
      sort(arr,arr+n);
      for(int i=0;i<(n/2);i++){
         printf("%d %d\n",arr[i+1],arr[0]);
      }
   }
}