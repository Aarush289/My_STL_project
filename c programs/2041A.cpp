#include<bits/stdc++.h>
using namespace std;
int main(){
 int arr[5]={0};
 for(int i=0;i<5;i++){
   int input;
   scanf("%d",&input);
   arr[input-1]++;
 }
 int j;
 for(j=0;j<5;j++){
   if(arr[j]==0){break;}
 }
 printf("%d\n",j+1);
}