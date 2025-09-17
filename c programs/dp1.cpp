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
      int max=arr[0];
      int min=arr[0];
      for(int i=1;i<n;i++){
         if(max<arr[i]){max=arr[i];}
         if(min>arr[i]){min=arr[i];}
      }
     printf("%d\n", (n-1)*(max-min));
   }
}
