#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a>b){printf("First\n");}
        if(a<b){printf("Second\n");}
        if(a==b){if(c%2==0){printf("Second\n");}else{printf("First\n");}}
    }
}