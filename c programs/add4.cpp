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
        if(str[i][j]=='X'){
                if(j<(size-3) && str[i][j+1]=='M'){
                    if(str[i][j+2]=='A' && str[i][j+3]=='S'){count++;}
                } 
                if(j>2 && str[i][j-1]=='M'){
                    if(str[i][j-2]=='A' && str[i][j-3]=='S'){count++;}
                }
                 if(i>2 && str[i-1][j]=='M'){
                    if(str[i-2][j]=='A' && str[i-3][j]=='S'){count++;}
                }
                if(i<(size-3) && str[i+1][j]=='M'){
                        if(str[i+2][j]=='A' && str[i+3][j]=='S'){count++;}
                }
                if(i>2){
                    if(j<(size-3) && str[i-1][j+1]=='M'){
                        if(str[i-2][j+2]=='A' && str[i-3][j+3]=='S'){count++;}
                    }
                    if(j>2 && str[i-1][j-1]=='M'){
                         if(str[i-2][j-2]=='A' && str[i-3][j-3]=='S'){count++;}
                    }
                }
                if(i<(size-3)){
                   if(j<(size-3) && str[i+1][j+1]=='M'){
                        if(str[i+2][j+2]=='A' && str[i+3][j+3]=='S'){count++;}
                    }
                     if(j>2 && str[i+1][j-1]=='M'){
                         if(str[i+2][j-2]=='A' && str[i+3][j-3]=='S'){count++;}
                    }
                }


        }
    }
   }
   printf("%d\n",count);
}