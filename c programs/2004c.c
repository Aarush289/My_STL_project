#include<stdio.h>
#include<stdlib.h>
 int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int n,k;
        scanf("%d%d",&n,&k);
       int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        qsort(arr, n, sizeof(int), compare);
        int sum1=0,sum2=0;
        int answer;
        if(n%2==0){
             for(int j=n-1;j>=0;j-=2){
            sum1+=arr[j];
        }
        for(int j=(n-2);j>=0;j-=2){
            sum2+=arr[j];
        }
            answer=sum1-sum2-k;
        if(answer<0){answer=0;}
        }
        else{
              for(int j=n-1;j>0;j-=2){
            sum1+=arr[j];
        }
        for(int j=(n-2);j>0;j-=2){
            sum2+=arr[j];
        }
            answer=sum1-sum2-k;
        if(answer<0){answer=0;}
        answer+=arr[0];
        }
        printf("%d\n",answer);
    }
}