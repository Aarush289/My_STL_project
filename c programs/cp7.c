#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);}
int main(){
    int cases;
    scanf("%d",&cases);
    for(int p=0;p<cases;p++){
        int n,x;
        scanf("%d%d",&n,&x);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        qsort(arr , n, sizeof(int), compare);
        int count[arr[n-1]+1];
        for(int i=0;i<=arr[n-1];i++){
            count[i]=0;
        }
        for(int i=0;i<n;i++){
            count[arr[i]]++;
        }
        int j=0;
        int f=1;
        while(j<n){
            for(int k=j;;k++){
                if(count[k]==0){
                    int l=k/x;
                    int flag=1;
                    for(int m=1;m<=l;m++){
                        if(count[k-(m*x)]>1){flag=0;f=0;count[k-(m*x)]--;break;}
                    }
                    if(flag==1){printf("%d\n",k);f=1;break;}
                    else{j=k+1;}
                }
            }
            if(f==1){break;}
        }
    }

}