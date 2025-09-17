#include<bits/stdc++.h>
using namespace std;
int main(){
   int cases;
   scanf("%d",&cases);
   getchar();
   while(cases--){
        char str[100000];
        scanf("%s",str);
        int flag=0;
        for(int i=0;i<strlen(str)-1;i++){
            if(str[i]!=str[i+1]){flag=1;}
        }
        if(strlen(str)!=1 && flag==1){
            if(str[0]=='a'){
         str[strlen(str)-1]='a';}
         else{ str[strlen(str)-1]='b';}
        }
        printf("%s\n",str);
   }
}