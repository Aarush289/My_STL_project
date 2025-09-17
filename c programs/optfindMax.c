#include<stdio.h>
int findMax(int i,int n,int arr[]){
    int l1,l2;
    if(i==n){return arr[i];}
    int mid= (i+n)/2;
    l1=findMax(i,mid,arr);
    l2=findMax(mid+1,n,arr);
    if(l1>l2){return l1;}
    else{return l2;}
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d\n",findMax(0,n-1,arr));
}