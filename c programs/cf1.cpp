#include<bits/stdc++.h>
using namespace std;
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>=b){printf("%d\n",a);}
        else
        {int x=b-a;
            if((a-x)<0){printf("0\n");}
            else{printf("%d\n",a-x);}}
    }
}