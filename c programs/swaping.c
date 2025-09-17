#include<stdio.h>
void swap(int *ptr1,int *ptr2){
    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}
int main(){
    int n=24,m=42;
    swap(&n,&m);
    printf("%d\t%d\n",n,m);
}