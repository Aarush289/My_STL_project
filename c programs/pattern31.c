#include<stdio.h>
int main(){
    int i=1,j=1;
    while(i<=5&&j<=9){
    for(int gap=4;gap>=i;gap--){
        printf(" ");
    }
    for(int star=1;star<=j;star=star+1){
        printf("*");
    }
    for(int gap=4;gap>=i;gap--){
        printf(" ");
    }
    printf("\n");
    i++;
    j=j+2;
    }
    i=1,j=7;
    while(i<=4){
    for(int gap=1;gap<=i;gap++){
        printf(" ");
    }
    for(int star=1;star<=j;star=star+1){
        printf("*");
        // printf("t");
    }
    for(int gap=1;gap<=i;gap++){
        printf(" ");
    }
    printf("\n");
    i++;
    j=j-2;
    }

}
