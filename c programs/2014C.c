#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int n;
        scanf("%d",&n);
        long long int money[n];
        scanf("%lld",&money[0]);
        long long int max=money[0];
        long long int sum=money[0];
        for(int i=1;i<n;i++){
            scanf("%lld",&money[i]);
            sum+=money[i];
        }
        if(n<=2){printf("-1\n");}
        else{
            qsort(money , n, sizeof(long long int), compare);
            long long int x;
            x=(((2*n)*(money[(n/2)]))+1-sum);
            if(x>0){
            printf("%lld\n",x);}
            else{printf("0\n");}
            }
        }
    }
