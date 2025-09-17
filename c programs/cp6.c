#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);}
int main(){
    int cases;
    scanf("%d",&cases);
    for(int j=0;j<cases;j++){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        qsort(arr , n, sizeof(int), compare);
        int avg=arr[0];
        for(int i=1;i<n;i++){
            avg=(avg+arr[i])/2;
        }
        printf("%d\n",avg);
    }
}