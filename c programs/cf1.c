#include<stdio.h>
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int n;
        scanf("%d",&n);
        for(int j=1;j<=((n+4)/5);j++)
        {
            printf("%c",'a');
        }
        for(int j=1;j<=((n+3)/5);j++)
        {
            printf("%c",'e');
        }
        for(int j=1;j<=((n+2)/5);j++)
        {
            printf("%c",'i');
        }
        for(int j=1;j<=((n+1)/5);j++)
        {
            printf("%c",'o');
        }
        for(int j=1;j<=((n)/5);j++)
        {
            printf("%c",'u');
        }
        printf("\n");
        
    }
}