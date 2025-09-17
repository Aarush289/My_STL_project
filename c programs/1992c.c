#include<stdio.h>
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=n;i>m;i--){
            printf("%d ",i);
        }
        for(int i=1;i<=m;i++){
            printf("%d ",i);
        }
        printf("\n");
    }
}