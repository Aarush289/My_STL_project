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
      int flag=0;
      for(int i=1;i<n;i++){
         if(arr[i-1]==arr[i]){flag=1;break;}
      }
      if(flag==1){printf("YES\n");}
      else{printf("NO\n");}
   }
}