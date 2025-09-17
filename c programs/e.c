#include<stdio.h>
int main(){
    float e;
    int m;
    float sum=1;
    for(m=1;m<20;m++){
        int factorial=m;
        int number=m;
    for (;number>1;number--){
        factorial=factorial*(number-1);
    }
        e=1*1.0/(factorial);
        sum=sum+e;

    }
    printf("%.10f",sum);
}