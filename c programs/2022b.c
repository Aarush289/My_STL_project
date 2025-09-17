# include<stdio.h>
#include<stdlib.h>
# define debug 1
 int compare(const void* a, const void* b) {
   return (*(long long int*)a - *(long long int*)b);
}
int main(){
    int cases;
    scanf("%d",&cases);
    for(int l=0;l<cases;l++){
        long long int n,x;
        scanf("%lld%lld",&n,&x);
       long long int arr[n];
        for(int i=0;i<n;i++){
            scanf("%lld",&arr[i]);
        }
        if(x>=n){
            long long int max=arr[0];
            for(int i=1;i<n;i++){
                if(max<arr[i]){max=arr[i];}
            }
            printf("%lld\n",max);
        }
        else{
        qsort(arr, n, sizeof(long long int), compare);
        long long int answer=0;
        long long int count=0;
        long long int count1=0;
        while(arr[n-1]>0){
            if(count1<=n-x){
            answer+=arr[n-x];
            for(int i=n-1;i>=n-x;i--)
            {
                arr[i]-=arr[n-x];
                if(arr[i]==0){count++;}
            }
         qsort(arr, n, sizeof(long long int), compare);
        }
        else{
            answer+=arr[count1];
            for(int i=n-1;i>=count1;i--)
            {
                arr[i]-=arr[count1];
                if(arr[i]==0){count++;}
            }
         qsort(arr, n, sizeof(long long int), compare);
        }
        count1=count;
        }
        printf("%lld\n",answer);
        }
    }
}