#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    long long int cases;
    scanf("%lld",&cases);
    for(long long int i=0;i<cases;i++)
    {
       long long int w,b;
        scanf("%lld%lld",&w,&b);
        long long int j;
        for(j=0;;j++){
            if(j*(j+1)>2*(w+b)){break;}
        } 
        j--;
        printf("%lld\n",j);
    }
}