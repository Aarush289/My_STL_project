#include<bits/stdc++.h>
using namespace std;
#define debug 1
int main(){
    int cases;
    scanf("%d",&cases);
    for(int p=0;p<cases;p++){
        int n;
        scanf("%d",&n);
        char str[n+1];
        scanf("%s",str);
        int count1=0,count0=0;
        for(int i=0;i<strlen(str);i++){
           if(str[i]=='0'){count0++;}
           else{count1++;} 
        }
        if(count1>=count0){printf("Yes\n");}
        else{printf("No\n");}
    }
}