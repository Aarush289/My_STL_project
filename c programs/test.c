#include<stdio.h>
int main(){
    int arr[20],n,x,value,i;
    scanf("%d%d",&n,&x);
    for(i=0;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    value=arr[n];
    for( i=(n-1);i>=0;i--){
        value=(x*value)+arr[i];
    }
    printf("%d\n",value);
}