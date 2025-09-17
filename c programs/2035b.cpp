#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    
    
       int n,m;
       scanf("%d%d",&n,&m);
        if(n==m){printf("1\n");printf("%d\n",n);}
        else{
            printf("3\n");
             int th= (3*n)-(2*m);
            printf("%d %d %d\n",m,m,th);
        }
    }