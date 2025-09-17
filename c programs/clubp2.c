#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int low=0,high=n;
    while(1){
        int mid=(low+high)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){break;}
        else{
            if(arr[mid]>arr[mid-1]){
                low=mid+1;
            }
            else{high=mid;}
        }
    }
    printf("%d\n",&arr[mid]);

}