#include<bits/stdc++.h>
using namespace std;
#define size 1000
int main(){
   int arr1[size];
   int arr2[size];
   for(int i=0;i<size;i++){
      scanf("%d",&arr1[i]);
      scanf("%d",&arr2[i]);
   }
   sort(arr1,arr1+size);
   sort(arr2,arr2+size);
   int max=arr2[size-1];
   if(max<arr1[size-1]){max=arr1[size-1];}
   int freq[max+1];
   for(int i=0;i<=max;i++) {
            freq[i]=0;
   }
   for(int i=0;i<size;i++){
    freq[arr2[i]]++;
   }
   int sum=0;
   for(int i=0;i<size;i++){
        sum+= ((arr1[i]*freq[arr1[i]]));
   }
   printf("%d\n",sum);
}