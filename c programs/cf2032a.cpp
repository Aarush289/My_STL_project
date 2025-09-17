#include<bits/stdc++.h>
using namespace std;
int main(){
   int cases;
   scanf("%d",&cases);
   while(cases--){
    int n;
    scanf("%d",&n);
    int even=0,odd=0;
    int arr[2*n];
    for(int i=0;i<(2*n);i++){
        scanf("%d",&arr[i]);
        if(arr[i]%2==0){even++;}
        else{odd++;}
    }
    int min= even%2;
    int max;
    if(even>odd){max=odd;}
    else{max=even;}
    printf("%d  %d\n",min,max);
   }
}