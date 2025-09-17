#include<stdio.h>
int main(){
    int digits;
    scanf("%d",&digits);
    int number;
    scanf("%d",&number);
    int sum=0;
    int w;
    for (int j=1 ; j<=digits;j++){
        w=number%10;
        w=w+7;
        w=w%10;
        number=number/10;
        for(int i=1;i<j;i++){
            w=w*10;
        }
        sum=sum+w;
    }
    printf("%d",sum);
    int temp=sum;

}