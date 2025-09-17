#include<stdio.h>
int count(int k,int n){
    if(k==0){return 0;}
    else{
    if(k%10==n){return 1+count(k/10,n);}
    else{return count(k/10,n);}
    }
}
int bigCount(int low,int high,int k){
    if(low==high){return count(low,k);}
    else{return (count(low,k)+bigCount(low+1,high,k));}
}
int main(){
    int low,high,k;
    scanf("%d%d%d",&low,&high,&k);
    printf("%d\n",bigCount(low,high,k));
    return 0;
}