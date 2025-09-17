#include<stdio.h>
int main(){
   printf("Decimal Numbers          Roman Numbers\n");
   printf("--------------------------------------\n");
   int i=1,temp,roman=0;
   int flag=0;
   for(;i<=100;i++){
    temp=i;
    printf("%d                     ",i);
    while(temp!=0){
    if(temp<40&&temp>0){
        while(temp/10!=0){
             printf("X"); 
            temp=temp-10;       
        }
        if(temp>=5&&temp!=9){printf("V");
            temp=temp-5;}
        while(temp>0&&temp<4){
            printf("I");
            temp=temp-1;
        }
        if(temp==4){printf("IV");
                        temp=temp-4;}
        if(temp==9){printf("IX");
                        temp=temp-9;}
    
    }
    if(temp>50&&temp<90){
        printf("L");
        temp=temp-50;
    }
    if(temp>=40&&temp<50){printf("XL");
        temp=temp-40;}
    if(temp==50){printf("L");
                        temp=temp-50;}
    if(temp>=90&&temp<100){printf("XC");
        temp=temp-90;}
    if(temp==100){printf("C");
                    temp=temp-100;}
    if(temp==0){printf("\n");break;}
    }
   }
   return 0;
}