#include<stdio.h>

void reverse(char arr[], int m){
    if(m==0){return;}
    if(m==1){char temp = arr[0];
    arr[0]=arr[m];
    arr[m]=temp; return;}
    char temp = arr[0];
    arr[0]=arr[m];
    arr[m]=temp;
    reverse(arr+1,m-2);
}
int main(){
    int n;
    scanf("%d",&n);
    char arr[1000];
   getchar();
    fgets(arr, 1000, stdin);
   reverse(arr,n-1);
    printf("%s",arr);
}