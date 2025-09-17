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
        int i;
       // printf("%d\n",strlen(str));//
        if(strlen(str)==1){flag=1;}
        if(strlen(str)==2 && str[0]!=str[1]){flag=1;} 
        if(strlen(str)>2){
            int j=0;
        for(i=0;i<(strlen(str)-2);i++){
            if(str[i]!=str[i+2]){j=1;break;}
        }
        int k=0;
         for(int l=0;l<strlen(str)-1;l++){
                if(str[l]!=str[l+1]){k=1;break;}
         }
         if(j==0 && k==1){flag=1;}
        }
        if(flag==1){printf("-1\n");}
        if(flag==0){
            int flag1=0;
            int i;
            for(i=0;i<strlen(str)-1;i++){
                if(str[i]==str[i+1]){flag1=1;break;}
            }
            if(flag1==1){printf("%c%c\n",str[i],str[i+1]);}
            else
            {
                int h=0;
                while(str[h]==str[h+2]){h++;}
                printf("%c%c%c\n",str[h],str[h+1],str[h+2]);
            }
        }
   }
}