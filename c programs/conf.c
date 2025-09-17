#include<stdio.h>
#include<math.h>
int main()
{
    int input;
    scanf("%d",&input);
   int d1=0;
    long long int d=1;
    if(input>2){
            for(int i=3;i<=input;i++){
                if(i%2==0){d=(i*d)+1;}
                else{d=(i*d)-1;}
            }
}
if(input==1){printf("0");}
else{
    d=d%(1000000007);
    printf("%lld",d);}
}
