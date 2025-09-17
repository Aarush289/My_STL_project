#include<stdio.h>
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
                int m=k;
                for(i=0;;i++){
                    k=k*k;
                    if(k<=n){}
                    else{break;}
                }
                if(m>n){k=k/m;}
                k=k/m;
                int b=m/k;
                int l=n/b;
                count=count+l;
                n=n-(l*b);
            }
            printf("%d\n",count);
        }
    }
}