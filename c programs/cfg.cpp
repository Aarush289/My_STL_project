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
      int sum=0;
      int s=1;
      int count=0;
      int j=1;
      for(int i=0;i<n;i++){
      sum+=arr[i];
      while(j*j<sum){
        j++;
      }
      if(j*j==sum && j%2==1){count++;}
      }
      printf("%d\n",count);
   }
}