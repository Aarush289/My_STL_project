#include<stdio.h>
int findMax(int i,int arr[],int n){
    if(i==n){return arr[n-1];}
    int l=findMax(i+1,arr,n);
    if(l>arr[i]){return l;}
    else{return arr[i];
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d\n",findMax(1,arr,n));
}