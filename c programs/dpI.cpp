#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    scanf("%d",&cases);
    for(int p=0;p<cases;p++){
        int n,k;
        scanf("%d%d",&n,&k);
        int pro = n*k;
        if(debug){printf("%d\n",pro);}
        char str[pro+1];
        int j=0;
        int i=0;
        int x=2;
        while(j<pro){
            int t=0;
        for(i=j;i<j+k;i++){
            str[i]='a'+t;t++;
        }
        if(i==pro){break;}
        t=0;
        for(i=j+k;i<(j+(2*k));i++){
           str[i]='a'+t;t++;
        }
        x+=4;
        j+=(2*k);
     }
     str[pro]=0;
     printf("%s\n",str);
    }
}