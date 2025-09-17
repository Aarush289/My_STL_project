#include<bits/stdc++.h>
using namespace std;
#define debug 0
#define size 140
int main(){
    char str[140][141];
    for(int i=0;i<size;i++){
        scanf("%s",str[i]);
    }
   // printf("%s %s\n",str[0],str[1]);//
   int count=0;
   for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
       if(i>0 && i<(size-1)){
        if(j>0 && j<(size-1)){
            if(str[i][j]=='A'){
                if((str[i+1][j+1]=='S' && str[i-1][j-1]=='M' ) || (str[i+1][j+1]=='M' && str[i-1][j-1]=='S')){
                if((str[i+1][j-1]=='M' && str[i-1][j+1]=='S') || ((str[i+1][j-1]=='S' && str[i-1][j+1]=='M'))){count++;}
                }
            }
        }
       }
    }
   }
   printf("%d\n",count);
}