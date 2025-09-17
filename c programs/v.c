#include<stdio.h>
#include<math.h>
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int n,k;
        scanf("%d%d",&n,&k);
        if(k>n||k==1){printf("%d\n",n);}
        else{
            int count=0;
            while(n>0){
                int i;
                for(i=0;;i++){
                    if(pow(k,i)<=n){}
                    else{count++;break;}
                }
                //printf("%d\t",n);
                n=n-pow(k,i-1);
            }
            printf("%d\n",count);
        }
    }
}