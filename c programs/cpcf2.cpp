#include<bits/stdc++.h>
using namespace std;
int main(){
   int cases;
   scanf("%d",&cases);
   while(cases--){
        int n;
        scanf("%d",&n);
        if(n==1){int a;scanf("%d",&a);printf("1\n");}
        else{
        if(n%2!=0){
        int a[n];
        int dif[n/2];
        int dif2[n/2];
         for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
         }   
         for(int i=0;i<(n/2);i++){
            dif[i]=a[(2*i)+1]-a[(2*i)];
            dif2[i]=a[(2*i)+2]-a[(2*i)+1];
         }
            int max1=dif[0];
            int max2=dif2[0];
            for(int i=0;i<(n/2);i++){
                if(max1<dif[i]){max1=dif[i];}
                if(max2<dif2[i]){max2=dif2[i];}
            }
            if(max1>max2){printf("%d\n",max2);}
            else{printf("%d\n",max1);}
         }
         else{
            int a[n];
        int dif[n/2];
         for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
         }   
         for(int i=0;i<(n/2);i++){
            dif[i]=a[(2*i)+1]-a[(2*i)];
         }
            int max1=dif[0];
            for(int i=0;i<(n/2);i++){
                if(max1<dif[i]){max1=dif[i];}
            }
           printf("%d\n",max1);
         }
        }
   }
}