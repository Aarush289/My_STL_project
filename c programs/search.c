#include<stdio.h>
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int array[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    int l=0;
    int flag=0;
    int m=n-1;
    while(l <= m){
    if(k==array[(m+l)/2]){break;}
    if(m==l&&array[m]!=k)
    {
        printf("Not possible");
        flag=1;
        break;
    }
    if(k>array[((m+l)/2)]){l=((m+l)/2)+1;}
    if(k<array[((m+l)/2)]){m=((m+l)/2)-1;}
    }
if(flag==0)
{
    printf("%d",(m+l)/2);
    }

return 0;

}