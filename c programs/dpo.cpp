#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        int n;
        scanf("%d",&n);
        char str[4];
        if(n>=28)
        {
            str[2]='z';n-=26;
            if(n>=27){str[1]='z';str[0]='a'+n-27;}
            else{
                str[1]='a'+n-2;str[0]='a';
            }
        }
        else{str[2]='a'+n-3;str[1]='a';str[0]='a';}
        printf("%s\n",str);
    }
}