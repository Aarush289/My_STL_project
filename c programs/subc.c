#include<stdio.h>
#include<string.h>
void task(char *ptr1,char *ptr2,int k){
    for(int i=0;i<k;i++){
        *(ptr2+i)=*(ptr1+i);
        printf("%c",*(ptr2+i));
    }
    printf("\n");
    return ;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    char inp[10000];
    getchar();
    scanf("%s",inp);
    char output[k];
    task(inp+n,output,k);
}