#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
       char str[n+1];
       getchar();
       scanf("%s",str);
       int i=0;
       int ans=0;
       while(str[i]!=0 || i<n){
            int count=0;
           while(str[i]!='1' && i<n){count++;if(count>=m){i+=(k-1); ans++;break;} i++;}
            i++;
       }
       printf("%d\n",ans);
        }
    }