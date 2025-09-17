#include<stdio.h>
int main(){
    int number;
    scanf("%d",&number);
    int factorial=number;
    for (;number>1;number--){
        factorial=factorial*(number-1);
    }
    if (number!=0){printf("%d",factorial);}
    else{printf("1");}
}