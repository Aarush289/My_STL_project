#include<stdio.h>
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int n,k;
        scanf("%d%d",&n,&k);
        if(k%2==0||n==1||k==n){printf("Yes\n");}
        if(n!=1&&k==1){printf("No\n");}
            else{
                if(k%2!=0&&n>1&&k!=n){
             int even;
            even=n/2;
            int n1,n2;
            n1=((n)/k)+1;
            n2=n1-1;
            int a=n%k;
            int b=k-a;
            int flag=0;
            if(k>n/2){printf("Yes\n");}
            else{
            for(int i=0;i<=a;i++){
                    if((even-(n1*i))%n2==0){if(((even-(n1*i))/n2)<=b && ((even-(n1*i))/n2)>=0){flag=1;break;}}
            }
            if(flag==0){printf("No\n");}
            else{printf("Yes\n");}
            }
                }
        }
    }
}