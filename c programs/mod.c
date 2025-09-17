#include<stdio.h>
#include<math.h>
int main(){
    int n;
    scanf("%d",&n);
    int m=pow(n,8);
    printf("%d\n",m%15);
}