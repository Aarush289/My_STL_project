#include<stdio.h>
int count(int k,int n){
    if(k==0){return 0;}
    else{
    if(k%10==n){return 1+count(k/10,n);}
    else{return count(k/10,n);}
    }
}
int main(){
    int k,n;
    scanf("%d%d",&k,&n);
    printf("%d\n",count(k,n));
}