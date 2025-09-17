#include<bits/stdc++.h>
using namespace std;
int main(){
   int cases;
   scanf("%d",&cases);
   getchar();
   while(cases--){
      char string[4];
      scanf("%s",string);
      switch(string[1]){
         case '=':
                     if(string[0]!=string[2]){string[0]=string[2];}
                     break;
         case '>':
                     if(string[0]<string[2]){string[1]='<';}
                     if(string[0]==string[2]){string[1]='=';}
                     break;
         case '<':
                     if(string[0]>string[2]){string[1]='>';}
                     if(string[0]==string[2]){string[1]='=';}
                     break;
      }
      printf("%s\n",string);
   }
}