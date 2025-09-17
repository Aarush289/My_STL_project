#include<bits/stdc++.h>
using namespace std;


int findGcd(int n,int m){
     if(n<m)
        {int temp=m;
        m=n;
        n=temp;
        }
    while(n%m!=0){
        n=n-m;
        if(n<m)
        {int temp=m;
        m=n;
        n=temp;
        }
    }
    return m;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d\n",findGcd(n,m));
    }