#include<stdio.h>
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int low=0;
    int high=n-1;
    int flag=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k){flag=1;break;}
        if(arr[mid]>k){high=mid-1;}
        if(arr[mid]<k){low=mid+1;}
    }
    if(flag==1){printf("YES\n");}
    else{printf("No\n");}
}