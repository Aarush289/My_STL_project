#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    char string[n][30];
    getchar();
    for(int i=0;i<n;i++){
        fgets(string[i],30,stdin);
    }
    int count=0;
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=i-1;j>=0;j--){
            if(strcmp(string[i],string[j])==0){flag=1;break;}
        }
        if(flag==0){count++;}
    }
    printf("%d\n",count);
}