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
      int count=1;
      for(int i=1;i<n;i++){
            if(arr[i]!=arr[i-1]){count++;}
      }
     // printf("%d\n",count);//
      int freq[count];
      for(int i=0;i<count;i++){
        freq[i]=1;
      }
      int k=0;
      for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){freq[k]++;}
            else{k++;}
      }
      /*for(int i=0;i<count;i++){
        printf("%d ",freq[i]);
      }
      printf("\n");*/
      int set=0;
      int p=0;
       int j=0;
      for(int i=0;i<n;){
        set++;
      while(arr[j+1]-arr[j] <=1 && j<n-1){
         j++;
      }
      k=i;
     while(k < j){
        if(freq[p]!=freq[p+1]){set++;}
        k+=freq[p];
        p++;
     }
      j++;
      i=j;
   }
  printf("%d\n",set);
      }
}