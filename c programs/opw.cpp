#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        int n,k;
        scanf("%d%d",&n,&k);
        int ans=1;
        while(1){
            if(ans%k==0 && ans%n==0){break;}
            ans++;
        }
        printf("%d\n",ans);
        

        }
    }