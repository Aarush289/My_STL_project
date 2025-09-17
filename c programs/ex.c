#include<stdio.h>
int main(){
    float x;
    scanf("%f",&x);
   
    int m;
    float sum=1,k=1;
    for(m=1;m<10;m++){
        float e=1;
        int factorial=m;
        int number=m;
    for (;number>1;number--){
        factorial=factorial*(number-1);
    }
        e=1*1.0/(factorial);
        for(int f=1;f<=k;f++){
            e=e*x;
        }
        printf("%f\n",e);
        sum=sum+e;
        k=k+1;
    printf("%f\n",sum);
    }
    printf("%f\n",sum);
}