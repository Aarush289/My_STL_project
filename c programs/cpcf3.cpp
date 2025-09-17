#include<bits/stdc++.h>
using namespace std;
int main(){
   int cases;
   scanf("%d",&cases);
   while(cases--){
        int n;
        scanf("%d",&n);
        char s[n+1];
        int count=0;
         int sum = (n*(n+1))/2;
        getchar();
            scanf("%s",s);
            for(int i=0;i<n;i++){
            if(s[i]=='1' && i!=0){count++;}}
        if(n==1){printf("1\n");}
        else{int j=0;
                if(count!=(n-1)){
            for(int i=n-1;i>=j;i--){
                    if(count==1){sum=sum-(i+1);break;}
                    else
                    {
                        if(s[i]=='1'){sum-=(i+1);count--;j++;}
                    }
            }
                }
                else
                {
                     for(int i=n-1;i>j;i--){
                    if(count==1){sum=sum-(i+1);break;}
                    else
                    {
                        if(s[i]=='1'){sum-=(i+1);count--;j++;}
                    }
            }
                }
            printf("%d\n",sum);
        }
   }
}