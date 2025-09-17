# include<stdio.h>
#include<stdlib.h>
# define debug 1
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}
int main(){
    int cases;
    scanf("%d",&cases);
    for(int l=0;l<cases;l++){
        int n,x;
        scanf("%d%d",&n,&x);
        int arr[n];
        scanf("%d",&arr[0]);
        int max=arr[0];
        int count1=1;
        for(int i=1;i<n;i++){
            scanf("%d",&arr[i]);
            if(max<arr[i]){max=arr[i];count1=1;}
            if(max==arr[i]){count1++;}
        }
        count1--;
        if(debug){printf("%d\n",count1);}
        if(debug){printf("%d\n",max);}
        qsort(arr, n, sizeof(int), compare);
        int answer=0;
        int count=0;
        while(count<n){
            int count2=count;
            if(count!=0){
            if(arr[i-k]<=arr[i-k+1+count2]){
                    answer+=arr[i-k];
                    for(int m=i;m>i-k-count;m--){
                        if(arr[m]!=0){arr[m]-=arr[i-k];if(arr[m]==0){count++;}}
                    }
                 }
            }
            else{
                answer+=arr[i-k+1];
                for(int j=i;j>i-k-count2;j--){
                    arr[j]-=arr[i];
                    if(arr[j]==0){count++;}
            }
            }
        }
    }
}