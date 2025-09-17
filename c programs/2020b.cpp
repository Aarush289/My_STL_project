#include<bits/stdc++.h>
using namespace std;
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        long long int n;
        scanf("%lld",&n);
        long long int x=sqrt(n);
        long long int m=(x+1)*(x+1);
        long long int answer=n+x;
        if(answer>=m){answer++;}
        printf("%lld\n",answer);
    }
}