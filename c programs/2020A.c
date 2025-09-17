#include<stdio.h>
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int n,k;
        scanf("%d%d",&n,&k);
        int answer =0;
        if(k!=1){
        while(n>0){
            answer+=n%k;
            n/=k;
        }
        }
        else{answer=n;}
        printf("%d\n",answer); 
    }
}