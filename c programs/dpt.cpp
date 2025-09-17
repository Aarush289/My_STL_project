#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        int n,w,h;
        scanf("%d%d%d",&n,&w,&h);
        int arr1[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr1[i]);
        }
        int arr2[n];
          for(int i=0;i<n;i++){
            scanf("%d",&arr2[i]);
        }
        int arr3[n];
        for(int i=0;i<n;i++){
            arr3[i]=arr2[i]-arr1[i];
        }
        int diff=arr3[0];
        int flag=0;
        for(int i=0;i<n;i++){
            if((diff*arr3[i])<0){flag=1;break;}
        }
        if(flag==1){printf("NO\n");}
        else{
            sort(arr3,arr3+n);
            int max;
            if(arr3[0]>0){max=arr3[n-1];}
            else{max=abs(arr3[0]);}
            int diff=(max-(w-h));
            if(arr3[0]>0){
                for(int i=0;i<n;i++){
                    arr3[i]-=diff;
                }
                int flag1=0;
                for(int i=0;i<n;i++){
                    if(arr3[i]<(h-w)){flag1=1;break;}
                }
                if(flag1==1){printf("NO\n");}
                else{printf("Yes\n");}
            }
            else{
                 for(int i=0;i<n;i++){
                    arr3[i]+=diff;
                }
                 int flag1=0;
                for(int i=0;i<n;i++){
                    if(arr3[i]>(w-h)){flag1=1;break;}
                }
                if(flag1==1){printf("NO\n");}
                else{printf("Yes\n");}
            }
        }
    }
}