# include<stdio.h>
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
        int count=0;
        int have=0;
        for(int i=0;i<n;i++){
            if(arr[i]>=k){have+=arr[i];}
            if(arr[i]==0){if(have>0){count++;have--;}}
        }
        printf("%d\n",count);
    }
}