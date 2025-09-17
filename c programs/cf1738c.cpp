#include<bits/stdc++.h>
using namespace std;
int main(){
   int cases;
   scanf("%d",&cases);
   while(cases--){
    int n;
    scanf("%d",&n);
    int even=0,odd=0;
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(arr[i]%2==0){even++;}
        else{odd++;}
    }
    int flag=0;
    if(odd%4==0 || odd%4==3){printf("Alice\n");}
    if(odd%4==2 ){printf("Bob\n");}
    if(odd%4==1 && even%2==0){printf("Bob\n");}
    if(odd%4==1 && even%2==1){printf("Alice\n");}
   }
}