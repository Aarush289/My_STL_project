#include<bits/stdc++.h>
using namespace std;
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++)
    {
        int n;
        scanf("%d",&n);
        int array[n];
        int ans[n];
        int min=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&array[i]);
            if(array[i]<=0)
            {
                ans[i] =min-array[i];
            }
            else
            {
                ans[i]= min;
             min+=array[i];
            }
        }
            for(int i=0;i<n;i++)
            {
                printf("%d ",ans[i]);
            }
            printf("\n");
}
}