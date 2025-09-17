#include<bits/stdc++.h>
using namespace std;
int main(){
   int cases;
   scanf("%d",&cases);
   while(cases--){
    int n,k;
    scanf("%d%d",&n,&k);
    if(n==1){printf("1\n");printf("1\n");}
    else{
    if(k==1 || k==n){printf("-1\n");}
    else{
        printf("3\n");
        if(k%2==0){
            printf("1 %d %d\n",k,k+1);
        }
        else{printf("1 %d %d\n",k-1,k+2);}
   }}
}
}