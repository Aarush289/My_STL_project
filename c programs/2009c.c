#include<stdio.h>
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int x,y,k,answer,n1,n2;
        scanf("%d%d%d",&x,&y,&k);
       if(x%k==0){  n1=(x/k);}
       else{n1=x/k+1;}
         if(y%k==0){ n2=(y/k);}
       else{ n2=y/k+1;}
        if(n1<=n2){answer=2*n2;}
        if(n1>n2){if((n1-n2)==1){answer=n1+n2;}
        else{answer=(2*n1)-1;}}
        printf("%d\n",answer);
    }
}